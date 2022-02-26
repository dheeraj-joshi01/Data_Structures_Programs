//program for circular Linked list
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


struct Node* Cir_frontInsert(int new_data, struct Node *first)
{
	struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	
	if(first == NULL)
	{
		new_node->link = new_node;
		first = new_node;
		
		return first;
	}
	
	if(first->link == first)
	{
		new_node->link = first;
		first->link = new_node;
		first = new_node;
		
		return first;
	}
	
	else
	{
		new_node->link = first;
				
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		
		temp = first;
		
		while(temp->link != first)
		{
			temp = temp->link;
		}
		
		temp->link = new_node;
		first = new_node;		
		
		return first;
	}
		
}

struct Node* Cir_endInsert(int new_data, struct Node *first)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	
	if(first == NULL)
	{
		new_node->link = new_node;
		first = new_node;
		
		return first;
	}
	
	if(first->link == first)
	{
		first->link = new_node;
		new_node->link = first;
		
		return first;
	}
	
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = first;
	
	while(temp->link != first)
	{
		temp = temp->link;
	}
	
	temp->link = new_node;
	new_node->link = first;
	
	return first;
	
}

struct Node* Cir_insert_into_sorted(int new_data, struct Node *first)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	
	if(first == NULL)
	{
		new_node->link = new_node;
		first = new_node;
		
		return first;
	}

	if(new_node->data <= first->data)
	{
		new_node->link = first;
		
		temp = first;
		
		while(temp->link != first)
		{
			temp = temp->link;
		}
		
		temp->link = new_node;
		first = new_node;
		
		return first;
	}

	
	temp = first;

	while(temp->link != first && new_node->data >= (temp->link)->data)
	{
		temp = temp->link;
	}
	
	new_node->link = temp->link;
	temp->link = new_node;

	return first;

}




struct Node* delete(int num, struct Node *first)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	if(first == NULL)
	{
		printf("Underflow\n");
		return first;
	}
	
	
	if(first->data == num)
	{
		if(first->link == first)
		{
			first = NULL;
			printf("Node Deleted..!!\n");
			return first;
		}
		
		else
		{
			temp = first;
			temp = temp->link;
			
			while(temp->link != first)
			{
				temp = temp->link;
			}
			
			temp->link = first->link;
			first = first->link;
			printf("Node Deleted..!!\n");
			
			return first;
		}
	}
	
	
	struct Node* preced = (struct Node*) malloc(sizeof(struct Node));

	temp = first;

	while(temp->data != num && temp->link != first)
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
		
		//if()
		printf("Node Deleted..!!\n");
	}

	
	
	free(temp); 

	return first;
}




int display(struct Node *t, struct Node *first)
{
	
	if(t == NULL)
	{	
		printf("Empty\n");
		return 0;
	}
	
	if(t->link == first)
	{
		printf("%d ", t->data);
		return 0;
	}
	
	printf("%d ", t->data);
	
	do
 	{
 		t = t->link;
		printf("%d ", t->data);
		
		
  	}while(t->link != first);
		
		
	return 0;
}


void main()
{
	int value, opt, flag = 1;
	int del_num;
	
	struct Node *first = NULL;	
	struct Node* t1 = (struct Node*) malloc(sizeof(struct Node));
		
	while(flag != 0)
	{
		
		printf("Select the operation you want to perform :\n1. Insert to front\n2. Insert to last\n3. Insert in b/w sorted list\n4. Delete\n5. display\n6. exit\n");
		
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
			printf("Enter the value you want to insert to front : ");
			scanf("%d", &value);
			first = Cir_frontInsert(value, first);
			printf("%d\n", first->data);
			break;

			case 2:
			printf("Enter the value you want to insert to end : ");
			scanf("%d", &value);
			first = Cir_endInsert(value, first);
			break;

			case 3:
			printf("Enter the value you want to insert to list : ");
			scanf("%d", &value);
			first = Cir_insert_into_sorted(value, first);
			break;

			case 4:
			printf("Enter the number you want to delete : ");
			scanf("%d", &del_num);
			first = delete(del_num, first);
			break;

			case 5:
			t1 = first;
			printf("List : ");
			display(t1, first);
			printf("\n");
			break;

			case 6:
			flag = 0;
			break;
		}
	
		

	}


}
