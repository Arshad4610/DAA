#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define v 5
int mindist(int key[],bool mstset[])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<v;i++)
    {
        if(mstset[i]==false && key[i]<=min)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void prims(int graph[v][v],int src)
{
    int key[v],parent[v];
    bool mstset[v];
    for(int i=0;i<v;i++)
    {
        key[i]=INT_MAX,mstset[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<v-1;count++)
    {
        int u=mindist(key,mstset);
        mstset[u]=true;
        for(int j=0;j<v;j++)
        {
            if(!mstset[j] && graph[u][j] && graph[u][j] < key[j])
                {
                    parent[j]=u,key[j]=graph[u][j];
                }
        }
    }
    printsol(parent,graph);
}
void printsol(int parent[],int graph[v][v])
{
    printf("Edge \t weight\n");
    for(int i=1;i<v;i++)
    {
        printf("%d-%d \t%d\n",parent[i],i,graph[i][parent[i]]);
    }
}
int main()
{
    int graph[v][v]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
    
    prims(graph,0);
}
------------------------------------------------------------------------------------------------------------------------
output:
Edge 	 weight
0-1 	2
1-2 	3
0-3 	6
1-4 	5
