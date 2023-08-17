#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *arr,*num,n=5;
	num=&n;
	arr=(int *)calloc(*num,sizeof(int));
	*(arr+0)=2;
	*(arr+1)=7;
	*(arr+2)=3;
	*(arr+3)=9;
	*(arr+4)=5;
	int i;
	printf("before sorting:");
	printf("[ ");
	
	for(i=0;i<*num;i++)
	{
		printf("%d ,",*(arr+i));
		
	}
	printf("\b]\n");
	
	//sort
	//int current_val;
	for(i=0;i<5;i++)
	{
		int j;
		for(j=i+1;j<5;j++)
		{
			printf("i %d j %d\n",i,j);
			if (arr[i]>arr[j])
			{
				printf("in\n");
				printf("aari %d %p\n",arr[i],&arr[i]);
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				printf("af aari %d %p\n",arr[i],&arr[i]);
			}
			
			int k;
			printf("[ ");
				for(k=0;k<*num;k++)
				{
				printf("%d ,",*(arr+k));
		
				}
				printf("\b]\n");
						
		}
	}
	printf("after sorting:");
	printf("[ ");
	
	for(i=0;i<*num;i++)
	{
		printf("%d ,",*(arr+i));
		
	}
	printf("\b]");
	/*//insert
	*(num)=++(*num);
	arr=(int *)realloc(arr,(*num)*sizeof(int));
	int index,val;
	printf("Enter the value to be inserted:");
	scanf("%d",&val);
	printf("Enter the index number to insert at(below %d):",*num);
	scanf("%d",&index);
	for(i= *num-1;i>index;i--)
	{
		*(arr+i)=*(arr+i-1);
		
	}
	*(arr+index)=val;
	//print
	printf("[ ");
	
	for(i=0;i<*num;i++)
	{
		printf("%d ,",*(arr+i));
		
	}
	printf("\b]");
	
	int search_val;
	printf("Enter the value to be searched:");
	scanf("%d",&search_val);
	
	int is_present=0;
		for( i=0;i<5;i++)
		{
			if(*(arr+i)==search_val)
			{
				printf("The element is present at index %d\n",i);
				is_present=1;
				break;
			}
		
		}
		if(is_present==0)
		{
			printf("The search element is not present in the array.\n");
		}
		*/
}
