#include<stdio.h>
#include<stdlib.h>
#define inf 99999
int bellman(int v,int e,int g[][3],int src){
    int dist[v];
    for(int i=0;i<v;i++){
        dist[i]=inf;
    }
    dist[src]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            if(dist[g[j][0]]!=inf && dist[g[j][0]]+g[j][2]<dist[g[j][1]]){
                dist[g[j][1]]=dist[g[j][0]]+g[j][2];
            }
        }
    }
    for(int j=0;j<e;j++){
        if(dist[g[j][0]]+dist[g[j][2]]<dist[g[j][1]]){
            printf("\n negative cycles are present");
        }
    }
    printf("Min dist from src to all vertices");
    for(int i=0;i<v;i++){
        printf("\n %d-%d->%d",src,i,dist[i]);
    }
}
int main(){
    int v,e,src;
    printf("\n Ent no.of vertices,no.of edges,src vertex");
    scanf("%d%d%d",&v,&e,&src);
    int g[e][3];
    printf("Ent src vertex,destinantion vertex,distance");
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&g[i][j]);
        }
    }
    bellman(v,e,g,src);
}
-------------------------------------------------------------------------------------------------------------------------
Output:
Ent no.of vertices,no.of edges,src vertex4
4
0
Ent src vertex,destinantion vertex,distance0 1 5
1 2 3
2 3 1
3 0 10
negative cycles are presentMin dist from src to all vertices
 0-0->0
 0-1->5
 0-2->8
 0-3->9
