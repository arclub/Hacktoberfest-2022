#include<stdio.h>
#include<conio.h>
void input(int a[5],int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
}

void output(int a[5],int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("the element %d is = %d\n",i,a[i]);
	}
}
void swap(int a[5], int i, int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int a[5],int lb, int ub)
{
    int pivot,i,j;
    pivot = a[ub];
    i=lb-1;
    for(j=1; j<ub; j++)
    {
        if(a[j]<pivot)
        {
        i++;
        swap(a,i,j);
        }
    }
    swap(a,i+1,ub);
    return i+1;
}

void quick(int a[5],int lb,int ub)
{
    int pi;
    if(lb<ub){
        pi = partition(a,lb,ub);
        quick(a,lb,pi-1);
        quick(a,pi+1,ub);
    }
}
int main()
{
	int a[5],n,lb=0,ub;
	printf("size of array element\n");
	scanf("%d",&n);
    ub=n-1;
	printf("enter array's element\n");
	input(a,n);
	quick(a,lb,ub);
	output(a,n);
	return 0;
}
