#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *arr,*num,n=3;
	num=&n;
	arr=(int *)calloc(*num,sizeof(int));
	*(arr+0)=3;
	*(arr+1)=1;
	*(arr+2)=2;
	int i;
	printf("[ ");
	
	for(i=0;i<*num;i++)
	{
		printf("%d ,",*(arr+i));
		
	}
	printf("\b]");
	//sort
	int current_val;
			for(i=0;i<*num;i++){
				current_val=*(arr+i);
				int j;
				for(j=i;j>=0;j--)
				{
					if (current_val<*(arr+j))
					{
						int dummy=*(arr+j);
						*(arr+j)=current_val;
						*(arr+j+1)=dummy;
	
					}
					
				}
			}
			//print
	printf("[ ");
	
	for(i=0;i<*num;i++)
	{
		printf("%d ,",*(arr+i));
		
	}
	printf("\b]");
	//insert
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
		if(i==index+1)
		{
			*(arr+index)=val;
		}
	}
	//print
	printf("[ ");
	
	for(i=0;i<*num;i++)
	{
		printf("%d ,",*(arr+i));
		
	}
	printf("\b]");
}
