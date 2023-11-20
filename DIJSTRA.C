#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define v 9
int mindist(int dist[],bool sptset[])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<v;i++)
    {
        if(sptset[i]==false && dist[i]<=min)
        {
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void dijstra(int graph[v][v],int src)
{
    int dist[v];
    bool sptset[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX,sptset[i]=false;
    }
    dist[src]=0;
    for(int count=0;count<v-1;count++)
    {
        int u=mindist(dist,sptset);
        sptset[u]=true;
        for(int j=0;j<v;j++)
        {
            if(!sptset[j] && graph[u][j] && dist[u]!=INT_MAX && 
                dist[u] + graph[u][j] < dist[j])
                {
                    dist[j]=dist[u]+graph[u][j];
                }
        }
    }
    printsol(dist);
}
void printsol(int dist[])
{
    printf("vertex \t\t\t dist from src\n");
    for(int i=0;i<v;i++)
    {
        printf("%d \t\t\t %d\n",i,dist[i]);
    }
}
int main()
{
    int graph[v][v]={{0,4,0,0,0,0,0,8,0},
                     {4,0,8,0,0,0,0,11,0},
                     {0,8,0,7,0,4,0,0,2},
                     {0,0,7,0,9,14,0,0,0},
                     {0,0,0,9,0,10,0,0,0},
                     {0,0,4,14,10,0,2,0,0},
                     {0,0,0,0,0,2,0,1,6},
                     {8,11,0,0,0,0,1,0,7},
                     {0,0,2,0,0,0,6,7,0}};
    
    dijstra(graph,0);
}

OUTPUT :
vertex 	  dist from src
0 			   0
1 			   4
2 			   12
3 			   19
4 			   21
5 			   11
6 			   9
7 			   8
8 			   14
