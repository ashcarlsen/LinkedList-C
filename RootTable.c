/******************************************************************************
*
*	Name: main 
*	
*	Function: take two command line arguments and read the integers from one
*			  then print the sqrt cbrt and fourth root to the output file
*
*	Inputs: argc and char *argv[], takes in strings for file names
*	Outputs: none
*
*	Compile Instructions: make
*
*******************************************************************************
*
*Begin
*	define variables
*	if less arguments than 3 
*	then print string 
*	end program
*	else if more arguments than 3
*	then print string
*	end program 
*	open file to read
*	if file pointer is null
*	then print error
*	end program
*	define nodes
*	set first equal to null
*	Loop while end_of_file is not 1
*		if filepointer points to EOF
*			set end_of_file to 1
*		else
*			scan number and store in temp
*			if first pointer equals null
*				then create a new node with temp as value 
*			else
*				check if temp is in the list
*					if temp isn't in list 
*					then create a node and add it to the list
*					else
*						return to start of loop
*	EndLoop when end_of_file is true
*	close first file
*	open second file for writing
*	if filepointer is null
*	then print error 
*		end program
*	forLoop 
*		set a pointer to first in the linked list
*		print the value sqrt cube root and 4th root to new file
*		move to the next value in the list
*	EndLoop when done with the list
*	Loop through every link in the list
*		free the nodes for memory
*	EndLoop when all are freed
*	close second file
*End
******************************************************************************/


#include "MyLinkedList.h"


int main(int argc, char *argv[])
{
	int temp, check, end_of_file = 0;
	int arguments = argc;				//define variables
	if(arguments < 3)					//if less arguments than 3 
	{									//then print string 
		printf("You need more arguments on the command line dummy.");
		exit(EXIT_FAILURE);				//end program
	}
	else if(arguments > 3)				//else if more arguments than 3
	{									//then print string
		printf("Jeez how many files are you trying to access :/");
		exit(EXIT_FAILURE);				//end program
	}
	FILE *filepointer = fopen(argv[1], "r");	//open file to read
	if(filepointer == NULL)						//if file pointer is null
	{											//then print error
		printf("Couldn't open %s", argv[1]);	//end program
		exit(1);
	}
	struct node *first, *current, *previous, *new_node; //define nodes
	first = NULL;								//set first to null
	while(end_of_file != 1)		//Loop while end_of_file is not 1
	{
		if(feof(filepointer)== 1) //if filepointer points to EOF
		{
			end_of_file = 1;	//set end_of_file to 1
		}
		else					//else 
		{	
		fscanf(filepointer, "%d", &temp); //scan number and store in temp
		if(first == NULL)		//if first pointer equals null
		{						//then create a new node with temp as value
			new_node = (struct node*) malloc(sizeof(struct node));
			first = new_node;
			new_node->value = temp;
		}
		else					//else
		{
			check = check_list(first, temp); //check if temp is in the list
			if(check == 0)			//if temp isn't in list 
			{				//then create a node and add it to the list
			new_node = create_node(temp);
			first = add_to_list(first, new_node);
			}
			else{}	//return to start of loop
		}
		}
	}					//EndLoop when end_of_file is true
	fclose(filepointer);	//close first file
	filepointer = fopen(argv[2], "w"); //open second file for writing
	if(filepointer == NULL)			//if file pointer is null
	{								//then print error
		printf("Couldn't open %s", argv[2]);
		exit(1);					//end program
	}													//forLoop
	for(current = first; current != NULL; current = current->next)
	{							//set a pointer to first in the linked list
		fprintf(filepointer, "%d\t%.3f\t%.3f\t%.3f\n",
		current->value, sqrt((double) current->value), 
		cbrt((double)current->value), sqrt(sqrt((double)current->value)));
		//print the value sqrt cube root and 4th root to new file
		//move to the next value in the list
		//EndLoop when done with the list
	}
	//Loop through every link in the list
	for(current = first, previous = NULL; current != NULL && previous != NULL;
		previous = current, current = current->next)
	{
		free(previous);	//free the nodes for memory
	}					//endLoop when all are freed
	fclose(filepointer);	//close second file
	return 0;			//End
}
