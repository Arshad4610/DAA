#include<stdio.h>
#include<stdlib.h>
int x[100],n;
int place(int q,int i){
    for(int j=1;j<q;j++){
        if((x[j]==i)||abs(q-j)==abs(i-x[j])){
            return 0;
        }
    }
    return 1;
}
void nqueens(int q){
    for(int i=1;i<=n;i++){
        if(place(q,i)){
            x[q]=i;
            if(q==n){
                for(int j=1;j<=n;j++){
                    printf("%d ",x[j]);
                }
                printf("\n");
            }
            else{
                nqueens(q+1);
            }
        }
    }
}
int main(){
    printf("enter n=");
    scanf("%d ",&n);
    printf("%d",n);
    nqueens(1);
}
