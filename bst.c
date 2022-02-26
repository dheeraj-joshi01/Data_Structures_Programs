/**************
Binary Search Tree Operations
****************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

/*
struct node *search(struct node *,int);
void inorder(struct node *);
struct node *new(int);
struct node *insert(struct node *,int);
struct node *delete(struct node *,int);
struct node *findmin(struct node *);*/


void Preorder(struct node *T)
{
	if(T == NULL)
	{
		printf("Empty Tree\n");
		return;
	}

	else
	{
		printf("%d ", T->data);
	}

	if(T->left != NULL)
	{
		Preorder(T->left);
	}

	if(T->right != NULL)
	{
		Preorder(T->right);
	}


}

void Inorder(struct node *T)
{
	if(T == NULL)
	{
		printf("Empty Tree\n");
		return;
	}


	if(T->left != NULL)
	{
		Preorder(T->left);
	}

	printf("%d ", T->data);
	
	if(T->right != NULL)
	{
		Preorder(T->right);
	}


}

void Postorder(struct node *T)
{
	if(T == NULL)
	{
		printf("Empty Tree\n");
		return;
	}


	if(T->left != NULL)
	{
		Preorder(T->left);
	}

	if(T->right != NULL)
	{
		Preorder(T->right);
	}
	
	
	printf("%d ", T->data);


}

struct node* new(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node *root, int data)
{
	if(root == NULL)
	{
		root = new(data);
		return root;
	}
	
	else if(data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
		return root;
	}
}

struct node* search(struct node *root, int data)
{
	if(root == NULL)
	{
		return NULL;		
	}
	
	if(data == root->data)
	{
		return root;
	}
	
	else if(data < root->data)
	{
		return search(root->left, data);
	}
	
	else
	{
		return search(root->right, data);
	}
}

struct node* minSearch(struct node *root)
{
	
	while(root->left != NULL)
	{
		root = root->left;
		return root;
	}
	
}

struct node* delete(struct node *root, int data)
{
	if(root == NULL)
	{
		return root;
	}
	
	else if(data < root->data)
	{
		root->left = delete(root->left, data);
	}
	
	else if(data > root->data)
	{
		root->right = delete(root->right, data);
	}
	
	else 
	{
		if(root->left == NULL && root->right == NULL)
		{
			free (root);
			root = NULL;
			
		}
		else if(root->left == NULL)
		{
			struct node *temp = root;
			root = root->right;
			free (temp);
			
		}
		
		else if(root->right == NULL)
		{
			struct node *temp = root;
			root = root->left;
			free (temp);	
		}
		
		else
		{
			struct node *temp = minSearch(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	
	return root;
}



int main()
{
	struct node *R = NULL, *t;
	int n;
	int opt, flag = 0;	
	
	while(flag == 0)
	{
		printf("Select the operation you want to perform  on BST:\n1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. exit\n");
			
			scanf("%d", &opt);

			switch(opt)
			{
				case 1:
				printf("Enter no. you want to insert\n");
				scanf("%d",&n);
				R = insert(R, n);
				break;

				case 2:
				printf("\nEnter number you want to delete\n");
				scanf("%d",&n);
				delete(R, n);
				printf("\n%d deleted..\n", n);
				break;

				case 3:
				printf("\nEnter number you want to search\n");
				scanf("%d",&n);
				t = search(R, n);
				if(t != NULL)
				{
					printf("Found: %d\n", t->data);
				}
				else
				{
					printf("Not found\n");
				}
				break;
				
				case 4:
				printf("\nPreorder traversal of BST :\t");
				t = R;
				Preorder(t);
				
				printf("\nInorder traversal of BST :\t");
				t = R;
				Inorder(t);

				printf("\nPostorder traversal of BST :\t");
				t = R;
				Postorder(t);
				printf("\n");
				break;

				case 5:
				flag = 1;
				break;
			}
	}	

	return 0;
}
