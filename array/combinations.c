#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void binary();
void print(int *arr,int len);
void main()
{
	//binary();
	int i;
	int k=1;
	for(i=0;i<15;i++)
	{
		printf("0b%d\n",(k<<1)+1);
		k<<=1;
		k++;
	}
	
}

void binary()
{
	int len=4;
	int *arr=(int*)calloc(len,sizeof(int));
	int i,k=0;
	for(i=1;i<pow(2,len);i++)
	{
		int num=i;
		int j=len-1;
		while(num!=0 && j>=0)
		{
			*(arr+j)=num%2;
			num/=2;
			j--;
		}
		print(arr,len);
		k++;
	}
}
void print(int *arr,int len)
{
	int brr[]={2,3,4,5};
	printf("[");
	int i;
	for(i=0;i<len;i++)
	{
		int a= *(arr+i);
		int b= *(brr+i);
		printf("%d,",a*b);
	}
	printf("\b]\n");
}
