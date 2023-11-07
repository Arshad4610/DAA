#include<stdio.h>
#define v 4
#define INF 99999
void floydwarshall(int d[][v])
{
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    printgraph(d);
}
void printgraph(int d[][v])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(d[i][j]== INF)
            {
                printf("%s ","INF");
            }
            else
            {
                printf("%d   ",d[i][j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int graph[v][v] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    floydwarshall(graph);
}
