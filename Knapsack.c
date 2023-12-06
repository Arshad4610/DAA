#include<stdio.h>
#include<stdlib.h>
int main(){
    double p[]={10,5,15,7,6,18,3};
    double w[]={2,3,5,7,1,4,1};
    double pw[7];
    float cap=15;
    int n=7;
    for(int i=0;i<n;i++){
        pw[i]=p[i]/w[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(pw[j]<pw[j+1]){
                double t=pw[j];
                pw[j]=pw[j+1];
                pw[j+1]=t;
                double te=p[j];
                p[j]=p[j+1];
                p[j+1]=te;
                double tem=w[j];
                w[j]=w[j+1];
                w[j+1]=tem;
            }
        }
    }
    float pr=0.0;int i=0;
    while(cap>0){
        if(cap<w[i]){
            pr+=(cap/w[i])*p[i];
            cap-=cap;
        }
        else{
            pr+=p[i];
            cap-=w[i];
            i++;
        }
    }
    printf("%f",pr);
    
}
