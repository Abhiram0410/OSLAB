#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
   int n=argc-1;
   int arr[n];
   for(int i=0;i<n;i++)
   {
     arr[i]=atoi(argv[i+1]);
     }
   printf("Reversed array:\t");
   for(int i=n-1;i>=0;i--)
   {
     printf("%d",arr[i]);
     if (i > 0) {
            printf(" ");
     }
     }
     printf("  \n");
     return 0;
}
