#include "MyLinkedList.h"

/******************************************************************************
*
*	Name: create_node 
*
*	Function: take in a value and create a structure node with that value
*
*	Inputs: int temp, takes in an integer value to store in the node
*	
*	Outputs: struct node* that points to the new node created by function
*
*******************************************************************************
*
*Begin
*	define node pointer
*	allocate memory to hold a node
*	set pointer to that memory
*	set the value of the node to input value
*	return the pointer to the node
*End
*
******************************************************************************/

struct node* create_node(int temp)
{
	struct node *new_node;	//define node pointer
							//define memory to hold a node
							//set pointer to that memory
	new_node = (struct node*) malloc(sizeof(struct node)); 
	new_node->value = temp; //set the value of the node to input value
	return new_node;		//return the pointer to the node
}							//End

/******************************************************************************
*
*	Name: add_to_list
*
*	Function: take in a pointer to a linked list and a pointer to a node and
*			  put the node into the list in sorted order.
*
*	Inputs: struct node* head and new_node, head is the start of the list
*			while new_node is the address of the new node to be inserted
*
*	Outputs: outputs a pointer to the start of the linked list with node input
*
*******************************************************************************
*
*Begin
*	define node pointers
*	forLoop while current pointer isn't null
*		set previous to null and current to the head of the list
*		if the value of the new node is greater than the first value
*			then place new node at start of list
*			return the pointer to new start of list
*		else if the value of the node is greater than the current value
*				then set new_node next to current set previous to new_node
*				return the start of the list
*		else if current->next is null/current is at the end of the list
*				then add new_node to the back of list
*				return start of list
*	EndLoop after gone through the entire list or returned
*End
*
******************************************************************************/

struct node* add_to_list(struct node *head, struct node *new_node)
{										//Begin
	struct node *current, *previous;	//define node pointers
		//forLoop while current pointer isn't null
		//set previous to null and current to the head of the list
	for(current = head, previous = NULL; current != NULL;
		previous = current, current = current->next)
	{
		//if the value of the new node is greater than the first value
		if(new_node->value > current->value && previous == NULL)
		{		//then place the new_node at start of list
			new_node->next = current;
			previous = new_node;
			return previous;	//return pointer to start of new list
		}
		//else if the value of the node is greater than the current value
		else if(new_node->value > current->value && previous != NULL)
		{
			//then set new_node next to current set previous to new_node
			new_node->next = current;
			previous->next = new_node;
			return head;	//return the start of the list
		}
		//else if current->next is null/current is at the end of the list
		else if(current->next == NULL)
		{
			//then add new_node to the back of list
			current->next = new_node;
			new_node->next = NULL;
			return head;	//return start of list
		}
	}		//EndLoop after gone through the entire list or returned
}			//End

/******************************************************************************
*
*	Name: check_list
*
*	Function: check if an input value is already inside of a linked list
*			  returns 1 if true and 0 if false
*
*	Inputs: struct node* head and int temp, head is the pointer to the start
*			the list. Temp is the value to check
*
*	Outputs: outputs 1 if value is in list, outputs 0 if not in list
*
*******************************************************************************
*
*Begin
*	define variables
*	define a node pointer
*	forLoop while inside list and loop is true
*		if temp equals the pointer's value
*			then set check to one
*				set loop to false
*		else
*			set check to 0
*	EndLoop if loop is false or reaches end of list
*	return the check variable
*End
*
******************************************************************************/

int check_list(struct node *head, int temp)
{
	int check = 0;	//define variables
	int loop = 1;
	struct node *current; //define a node pointer
	//forLoop while inside list and loop is true
	for(current = head; current != NULL && loop == 1; current = current->next)
	{
		if(temp == current->value) //if temp equals the pointer's value
		{
			check = 1;	//then set check to one
			loop = 0;	//set loop to false
		}
		else 			//else
		{
			check = 0;	//set check to 0 
		}
	}				//EndLoop if loop is false or reaches end of list
	return check;	//return the check variable
}					//End