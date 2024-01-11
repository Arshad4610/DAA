#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int coinchange(int* coins,int coinsize,int amount){
    int v[amount+1];
    v[0]=0;
    for(int i=1;i<amount+1;i++){
        v[i]=INT_MAX;
    }
    for(int i=0;i<coinsize;i++){
        for(int j=coins[i];j<=amount;j++){
            if(v[j]>(1+v[j-coins[i]])){
                v[j]=1+v[j-coins[i]];
            }
        }
        for(int k=1;k<=amount;k++){
                printf("%d ",v[k]);
        }
        printf("\n");
    }
    if(v[amount]==INT_MAX){
        return -1;
    }
    else{
        return v[amount];
    }
}
int main(){
    int coins[3]={1,2,5};
    int coinsize=sizeof(coins)/sizeof(coins[0]);
    int amount=13;
    printf("%d",coinchange(coins,coinsize,amount));
}
OUTPUT:
1 2 3 4 5 6 7 8 9 10 11 12 13 
1 1 2 2 3 3 4 4 5 5 6 6 7 
1 1 2 2 1 2 2 3 3 2 3 3 4 
4
-------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
int eval(int m,int n){
    if(m==-1 && n==-1){
        return -1;
    }
    else if(m==-1){
        return n;
    }
    else if(n==-1){
        return m+1;
    }
    else{
        if(m+1>n){
            return n;
        }
        else{
            return m+1;
        }
    }
}
int coinchange(int* a,int n,int s){
    s=s+1;
    int b[n][s];
    for(int i=0;i<n;i++){
        for(int j=0;j<s;j++){
            if(i==0){
                if(j%a[i]==0){
                    b[i][j]=j/a[i];
                }
                else{
                    b[i][j]=-1;
                }
            }
            else{
                if(j<a[i]){
                    b[i][j]=b[i-1][j];
                }
                else{
                    int m=b[i][j-a[i]];
                    int n=b[i-1][j];
                    b[i][j]=eval(m,n);
                }
            }
        }
    }
    return b[n-1][s-1];
}
int main()
{
    int n=3,s=6;
    int a[]={2,2,2};
    printf("%d",coinchange(a,n,s));
}
-----------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
int main(){
int count=0,amount=5;
int coins[]={2,2,1};
for(int i=0;i<3;i++){
    while (amount >= coins[i]) {
        amount -= coins[i];
        count++;
    }
}
printf("%d",count);
}
