#include<stdio.h>


int cqInsert(char q[], int *f, int *r, int size, char element)			//CIRCULAR ENQUEUE FUNCTION
{
	if(*r == size)			//condition for circular queue
	{
		*r = 1;
	}
	
	else
	{
		*r += 1;
	}

	if(*r == *f)			//Checking Overflow
	{
		printf("Stack Overflow\n");
		
		return 0;
	}

	if(*f == 0)			//condition for 1st element of queue
	{
		*f = 1;
	}
	
	

	q[*r] = element;
	
	
	return 1;
	

}

char cqDelete(char q[],int *f, int *r, int size)					//CIRCULAR DEQUEUE FUNCTION
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


	else if(*f == size)
	{
		*f = 1;
	}

	else
	{
		*f += 1;
	}

	printf("Deleted : %c\n ", y);

	return 0;

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
			cqInsert(queue, &f, &r, 5, value);
			break;

			case 2:
			cqDelete(queue, &f, &r, 5);
			//printf("Deleted : %c\n", );
			break;

			case 3:
			flag = 0;
			break;
		}

	}

}
