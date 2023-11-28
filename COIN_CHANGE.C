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
