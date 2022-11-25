#ifndef LISTS
#define LISTS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	int value;
	struct node *next;
};

struct node* create_node(int temp);

struct node* add_to_list(struct node *head, struct node *new_node);

int check_list(struct node *head, int temp);

#endif 