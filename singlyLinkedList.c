//program for singly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

struct Node_2{
	int field;
	struct Node_2 *ptr;
};


struct Node* frontInsert(int new_data, struct Node *first)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;

	if(first == NULL)
	{
		new_node->link = NULL;
	}

	else
	{
		new_node->link = first;
	}

	return new_node;

}

struct Node* endInsert(int new_data, struct Node *first)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->link = NULL;

	if(first == NULL)
	{
		return new_node;
	}

	else
	{
		struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
		
		temp = first;
		
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		
		temp->link = new_node;
	}
	return first;

}


struct Node* insert_into_sorted(int new_data, struct Node *first)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	
	if(first == NULL)
	{
		new_node->link = NULL;
		return new_node;
	}

	if(new_node->data <= first->data)
	{
		new_node->link = first;
		return new_node;
	}

	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	
	temp = first;

	while(temp->link != NULL && new_node->data >= (temp->link)->data)
	{
		temp = temp->link;
	}
	
	new_node->link = temp->link;
	temp->link = new_node;

	return first;

}


struct Node* delete(int num, struct Node *first)
{
	if(first == NULL)
	{
		printf("Underflow\n");
		return first;
	}
	
	
	if(first->data == num)
	{
		if(first->link == NULL)
		{
			first = NULL;
			printf("Node Deleted..!!\n");
			return first;
		}
		
		else
		{
			first = first->link;
			printf("Node Deleted..!!\n");
			
			return first;
		}
	}
	
	
	
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	struct Node* preced = (struct Node*) malloc(sizeof(struct Node));

	temp = first;

	while(temp->data != num && temp->link != NULL)
	{
		preced = temp;
		temp = temp->link;
	}

	if(temp->data != num)
	{
		printf("Node not found\n");
		return first;
	}

	else
	{
		preced->link = temp->link;
		printf("Node Deleted..!!\n");
	}

	
	
	free(temp); 

	return first;
}


int countNode(struct Node *first)
{
	int count = 0;
	
	if(first == NULL)
	{
		count = 0;
		return count;
	}

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp = first;

	while(temp != NULL)
	{
		count += 1;
		temp = temp->link;
	}

	return count;
}


void copy(struct Node *first, struct Node_2 *begin)
{
	if(first == NULL)
	{
		return NULL;
	}

	struct Node_2* new_node = (struct Node_2*) malloc(sizeof(struct Node_2));
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
		
	temp = first;
	
	while(temp != NULL)
	{
		if(new_node == NULL)
		{
			new_node->field = first->data;
			new_node->ptr = NULL;
			begin = new_node;
		}
		
		else
		{
			struct Node_2* new_node = (struct Node_2*) malloc(sizeof(struct Node_2));
			
			new_node->field = temp->data;
			new_node->ptr = temp->link;
			printf("%d ", new_node->field);
		}
		
		temp = temp->link;
	}

	
	new_node->ptr = NULL;


	while (temp != NULL)
 	{
     	printf(" %d ", new_node->field);
     	new_node = new_node->ptr;
  	}
  	
  	return 0;	

}

void display_1(struct Node *temp)
{
	while (temp != NULL)
 	{
     	printf(" %d ", temp->data);
     	temp = temp->link;
  	}
}


void main()
{
	int value, opt, flag = 1, del_num;
	struct Node *first = NULL;
	struct Node_2 *begin = NULL;

	struct Node* t1 = (struct Node*) malloc(sizeof(struct Node));
	
	while(flag != 0)
	{
		printf("Select the operation you want to perform :\n1. Insert to front\n2. Insert to last\n3. Insert in b/w sorted list\n4. Delete\n5. Count Node\n6. Copy list\n7. display\n8. exit\n");
		
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
			printf("Enter the value you want to insert to front : ");
			scanf(" %d", &value);
			first = frontInsert(value, first);
			break;

			case 2:
			printf("Enter the value you want to insert to end : ");
			scanf(" %d", &value);
			first = endInsert(value, first);
			break;

			case 3:
			printf("Enter the value you want to insert to list : ");
			scanf(" %d", &value);
			first = insert_into_sorted(value, first);
			break;

			case 4:
			printf("Enter the number you want to delete : ");
			scanf("%d", &del_num);
			first = delete(del_num, first);
			break;

			case 5:
			printf("%d\n",countNode(first));
			break;

			case 6:
			printf("Copied List : ");
			copy(first, begin);
			printf("\n");
			break;

			case 7:
			t1 = first;
			printf("List : ");
			display_1(t1);
			printf("\n");
			break;

			case 8:
			flag = 0;
			break;
		}
	
		

	}

}
