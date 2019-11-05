/**
 * queuesusingstacks.c -- Queues using 2 stacks
 *
 * Written on Monday,  4 November 2019.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list LIST_T;

struct list {
    int data;
    LIST_T *next;
};

LIST_T *main_stack = NULL;
LIST_T *sub_stack = NULL;

void push(LIST_T **stack, int data)
{
    LIST_T *node = NULL;
    LIST_T *temp = *stack;
    
    node = malloc(sizeof(LIST_T));

    node->data = data;
    node->next = NULL;
    
    if (*stack == NULL) {
	*stack = node;
    } else {
	
	while (temp->next != NULL) {
	    temp = temp->next;
	}
	
	temp->next = node;
    }
}

int pop(LIST_T **stack)
{
    LIST_T *temp = *stack;
    LIST_T *prev = NULL;
    int data = -1;
    
    if (temp == NULL) {
	printf("No nodes present in the list\n");
    } else {
	while (temp->next != NULL) {
	    prev = temp;
	    temp = temp->next;
	}

	if (prev) {
	    prev->next = NULL;
	} else {
	    *stack = NULL;
	}
	data = temp->data;

	free(temp);
	
    }

    return data;
}

void enqueue_costly(int data)
{
    if (main_stack == NULL) {
	push(&main_stack, data);
    } else {
	
	while(main_stack != NULL) {
	    push(&sub_stack, pop(&main_stack));
	}

	push(&main_stack, data);

	while (sub_stack != NULL) {
	    push(&main_stack, pop(&sub_stack));
	}
    }
}

void dequeue()
{
    pop(&main_stack);
}

void display_list(LIST_T *stack)
{
    LIST_T *temp = stack;

    while(temp) {
	printf("%d->",temp->data);
	temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue_costly(1);
    display_list(main_stack);
    enqueue_costly(2);
    display_list(main_stack);
    enqueue_costly(3);
    display_list(main_stack);
    enqueue_costly(4);
    display_list(main_stack);
    dequeue();
    display_list(main_stack);
    dequeue();
    display_list(main_stack);
    dequeue();
    display_list(main_stack);
    return 0;
}
