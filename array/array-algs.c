#include<stdio.h>
#include<stdlib.h>
void search(int *arr,int num,int *sorted_asc,int *sorted_desc);
void binary_search_asc(int *arr,int start,int end,int search_val,int count,int max_iter);
void binary_search_desc(int *arr,int start,int end,int search_val,int count,int max_iter);
void sort(int *arr,int num,int *sorted_asc,int *sorted_desc);//ok
void insert(int *arr,int *num);//ok
int * input(int *num);//ok
void print(int *arr,int num);//ok
void main(){
	int *arr,num;
	printf("arr %p",arr);
	int sorted_asc=0;
	int sorted_desc=0;
	arr=input(&num);
	printf("num %d arr %p",num,arr);
	while(1)
	{
		printf("Enter\n1 to search for an element in the array\n");
		printf("2 to sort the array\n");	
		printf("3 to insert for an element in the array\n");
		printf("4 to print the array\n");
		printf("5 to exit\n");
		printf("Enter your choice:");
		int choice;
		scanf("%d",&choice);
		printf("%d,%d\n",choice==1,choice==1 || choice==2 || choice==3 || choice==4 || choice==5 );
		if(!(choice==1 || choice==2 || choice==3 || choice==4 || choice==5))
		{
			printf("Please enter a valid choice.");
			continue;
		}
		switch(choice){
			case 1:
				search(arr,num,&sorted_asc,&sorted_desc);
				break;
			case 2:
				sort(arr,num,&sorted_asc,&sorted_desc);
				break;
			case 3:
				insert(arr,&num);
				sorted_asc=0;
				sorted_desc=0;
				break;
			case 4:
				print(arr,num);
				break;
			case 5:
			    free(arr);
				return;
		}
		printf("sa %d sd %d",sorted_asc,sorted_desc);				
	}
}
int * input(int *num)
{
 	int *arr;
	printf("Enter the number of elements:");
 	scanf("%d",num);
 	arr=(int *)calloc(*num,sizeof(int));
 	int i;
 	for(i=0;i<*num;i++)
 	{
 		printf("Enter the value of element at index %d:",i);
		scanf("%d",arr+i);
		printf("%d",arr[i]);
	}
	printf("\n");
	return arr;
	
}
void print(int *arr,int num)
{
	printf("[ ");
	int i;
	for(i=0;i<num;i++)
	{
		printf("%d ,",*(arr+i));
		
	}
	printf("\b]");
}
	

void binary_search_asc(int *arr,int start,int end,int search_val,int count,int max_iter)
{
	printf("in bas");
	int mid=(start+end)/2;
	//printf("mid %d, val %d,count %d, max %d \n",mid,*(arr+mid),count,max_iter);
	if(count>max_iter)
	{
		printf("The search element is not present in the array.\n");
		return;
	}
	else if(search_val==*(arr+mid))
	{
		printf("Element is found at index %d\n",mid);
		return;
	}
	else if(search_val>*(arr+mid))
	{
		count++;
		binary_search_asc(arr,mid+1,end,search_val,count,max_iter);
	}
	else
	{
		count++;
		binary_search_asc(arr,start,mid-1,search_val,count,max_iter);
	}
}
void binary_search_desc(int *arr,int start,int end,int search_val,int count,int max_iter)
{
	printf("in bds");
	int mid=(start+end)/2;
//	printf("start %d ,end %d ,mid %d, val %d,count %d, max %d \n",start,end,mid,*(arr+mid),count,max_iter);
	if(count>max_iter)
	
	{
		printf("The search element is not present in the array.\n");
		return;
	}
	else if(search_val==*(arr+mid))
	{
		printf("Element is found at index %d\n",mid);
		return;
	}
	else if(search_val<*(arr+mid))
	{
		count++;
		binary_search_desc(arr,mid+1,end,search_val,count,max_iter);
	}
	else
	{
		count++;
		binary_search_desc(arr,start,mid-1,search_val,count,max_iter);
	}
}
void search(int *arr,int num,int *sorted_asc,int *sorted_desc)
{
	printf("in search");
	int search_val;
	int max_iter=(num/2)+1;
	printf("Enter the value to be searched:");
	scanf("%d",&search_val);
	if (*sorted_asc)
	{
		printf("in bas");
		binary_search_asc(arr, 0,num-1,search_val,0,max_iter);
	}
	else if (*sorted_desc)
	{
		printf("in bds");
		binary_search_desc(arr, 0,num-1,search_val,0,max_iter);
	}
	else
	{
		printf("in search");
		int i;
		for( i=0;i<num;i++)
		{
			if(*(arr+i)==search_val)
			{
				printf("The element is present at index %d\n",i);
				return;
			}
		}
		printf("The search element is not present in the array.\n");
	}
}
void sort(int *arr,int num,int *sorted_asc,int *sorted_desc)
{
	int sort;
	printf("enter 0 to sort in ascending order\n");
	printf("enter 1 to sort in descending order\n");
	printf("Your choice:");
	scanf("%d",&sort);
	switch(sort){
		case 0:
			(*sorted_asc)=1;
			(*sorted_desc)=0;
			int current_val,i;
			for(i=0;i<num;i++){
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
			break;
		case 1:
			(*sorted_desc)=1;
			(*sorted_asc)=0;
			for(i=0;i<num;i++)
			{
				current_val=*(arr+i);
				int j;
				for(j=i;j>=0;j--)
				{
					if (current_val>*(arr+j))
					{
						int dummy=*(arr+j);
						*(arr+j)=current_val;
						*(arr+j+1)=dummy;
				}
			}
		}
			break;
	}
}
void insert(int *arr,int *num)
{
	*(num)=++(*num);
	arr=(int *)realloc(arr,(*num)*sizeof(int));
	int index,val,i;
	printf("Enter the value to be inserted:");
	scanf("%d",&val);
	printf("Enter the index number to insert at(below %d):",*num);
	scanf("%d",&index);
	for(i= *num-1;i>index;i--)
	{
		*(arr+i)=*(arr+i-1);	
	}
	*(arr+index)=val;
	
}

