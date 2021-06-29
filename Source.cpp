#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};
void display(struct Node *n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}
void push(struct Node *head_ref, int new_value)
{
	struct Node *top = head_ref;
	if(top == NULL)
		{
			top = (struct Node *)malloc(sizeof(struct Node));
			top->data = new_value;
			top->next = NULL;
			head_ref = top;
		}
	else
		{
			struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
			new_node->data = new_value;
			new_node->next = top;
			head_ref = new_node;
		}
}
int return_top(struct Node *head_ref)
{
	return head_ref->data;
}
Node* pop(struct Node *head_ref)
{
	struct Node *temp = head_ref;
	head_ref = head_ref->next;
	free(temp);
	return head_ref;
}
void main()
{
	struct Node *top = NULL;	
	push(top, 50);
	push(top, 40);
	push(top, 30);
	push(top, 20);
	push(top, 10);
	printf("After push operation, Stack is : ");
	display(top);
	printf("\nTop Of Stack is : ");
	printf(" %d ", return_top(top));
	top = pop(top);
	printf("\nAfter POP operation, The Stack is: ");
	display(top);
	_getch();
}