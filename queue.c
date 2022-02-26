#include<stdio.h>


int enqueue(char q[], int *f, int *r, int size, char element)			//ENQUEUE FUNCTION
{
	if(*r >= size)
	{
		printf("Stack Overflow\n");
		
		return 0;
	}
	
	if(*f == 0)
	{
		*f = 1;
	}

	
	*r = *r + 1;
	q[*r] = element;
	
	
	return 1;
	

}

char dequeue(char q[],int *f, int *r)					//DEQUEUE FUNCTION
{
	if(*f == 0)
	{
		printf("Stack Underflow\n");
		
		return 0;
	}

	char y = q[*f];

	if(*f == *r)
	{
		*f = 0, *r = 0;
	}
	
	else
	{
		*f += 1;
	}

	return y;

}


void main()
{
	char queue[5], value;
	int f = 0, r = 0, opt, flag = 1;

	while(flag != 0)
	{
		printf("Select the operation you want to perform :\n1. Insert\n2. Delete\n3. exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
			printf("Enter the value you want to insert : ");
			scanf(" %c", &value);
			enqueue(queue, &f, &r, 5, value);
			break;

			case 2:
			printf("Deleted : %c\n", dequeue(queue, &f, &r));
			break;

			case 3:
			flag = 0;
			break;
		}

	}

}
