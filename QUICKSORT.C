#include<stdio.h>
int partition(int a[],int l,int h)
{
    int i=l+1,j=h,p=l;
    while(i<j)
    {
        while(a[i]<a[p])
        {
            i++;
        }
        while(a[j]>a[p])
        {
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[p];
    a[p]=a[j];
    a[j]=temp;
    return j;
}
void quicksort(int a[],int l,int h)
{
    int p;
    if(l<h)
    {
        p=partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[]={24,9,29,14,19,27};
    int s=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,s-1);
    print(a,s);
}
