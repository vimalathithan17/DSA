#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char push(int *top,char *stack,int size,char val);
char pop(int *top,char *stack,char *val);
void pop_all(int*top,char *stack);
int get_precidence(char operator_);
void reverse_polish(int *top,char *stack,int size);
void pop_untill_paranthesis(int *top,char *stack);
void push_operator(int *top,char *stack,int size,char operator_);
int main()
{
	int size;
	int top=-1;
	char *stack;
	printf("Enter the size of the stack:");
	scanf("%d",&size);
	stack=(char*)calloc(size,sizeof(char));
	//printf("%p %p %c",stack,&stack[top],stack[top]);
	reverse_polish(&top,stack,size);
	free(stack);
	return 0;
}
void pop_all(int*top,char *stack)
{
	char val;
	while(*top>-1)
	{
		pop(top,stack,&val);
		printf("%c",val);		
	}
}
char pop(int *top,char *stack,char *val)
{
	if(*top>-1)
	{
		*val=stack[(*top)--];
		//printf("t%d\n",*top);
		return 's';
	}
	return 'f';	
}
char push(int *top,char *stack,int size,char val)
{
	if(*top<size-1)
	{
		stack[++(*top)]=val;
		//printf("t%d\n",*top);
		return 's';
	}
	return 'f';	
}
int get_precidence(char operator_)
{
	switch(operator_)
	{
		case '/':	
		case '*':
		case '%':
			return 4;
		case '+':
		case '-':
			return 3;
		case '&':
			return 2;
		case '^':
			return 1;
		case '|':
			return 0;
		default:
			return -1;
	}
}
void reverse_polish(int *top,char *stack,int size)
{
	char *expression;
	expression=(char *)calloc(15,sizeof(char));
	printf("Enter the expression:");
	scanf("%s",expression);
	int i;
	for(i=0;expression[i]!='\0';i++)
	{
		if(isalnum(expression[i]))
		{
			printf("%c",expression[i]);
		}
		else if(expression[i]=='(')
		{
			push(top,stack,size,'(');
		}
		else if(expression[i]==')')
		{
			pop_untill_paranthesis(top,stack);
		}
		else
		{
			push_operator(top,stack,size,expression[i]);
		}
	}
	pop_all(top,stack);
}
void pop_untill_paranthesis(int *top,char *stack)
{
	char val;
	while(stack[*top]!='(')
	{
		
		pop(top,stack,&val);
		printf("%c",val);
	}
	pop(top,stack,&val);
}
void push_operator(int *top,char *stack,int size,char operator_)
{
	char val;
	while((*top>-1)&&(get_precidence(stack[*top])>=get_precidence(operator_)))
	{
		pop(top,stack,&val);
		printf("%c",val);
	}
	push(top,stack,size,operator_);
}









