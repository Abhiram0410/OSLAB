#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h>
#include<sys/wait.h>
void asc_sort(int a[30],int n) 
{
	int i,j,temp; 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1]) 
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Ascending Order \n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]); 
	}
	printf("\n");
}
void des_sort(int a[30],int n) 

{
	int i,j,temp; 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1]) 
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Descending Order \n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]); 
	}
	printf("\n");
}
int main() 
{
	int a[30],n,i; 
	printf("Enter size of array to be sorted:");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		printf("Please enter the %dth array elements:",i+1);
		scanf("%d",&a[i]); 
		
	}
	if(fork()==0) 
	{
		printf("\nChild process id=%d\n",getpid());

		des_sort(a,n); 
	}
	else
	{
		wait(NULL); 
		
		printf("\nParent process id=%d\n",getppid());

		asc_sort(a,n); 
		
	}
	return 0;
}
