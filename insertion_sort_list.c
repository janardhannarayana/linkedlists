#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int val;
    struct slist *next;
}SLIST;

SLIST *root = NULL;

#define MAX_ELEMENTS 1000

SLIST *insert_node(int val)
{
    SLIST *node = malloc(sizeof(SLIST));
    SLIST *temp = root;

    node->val = val;
    node->next = NULL;

    if (root == NULL) {
        root = node;
    } else {
        while(temp->next)
            temp = temp->next;
        temp->next = node;
    }
    return node;
}

void display_list()
{
    SLIST *temp = root;

    while (temp) {
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void insertion_sort()
{
    SLIST *sorted = NULL;
    SLIST *temp = root;
    SLIST *next = NULL;
    SLIST *prev = NULL;
    SLIST *s_temp = NULL;

    
    while (temp != NULL) {
	next = temp->next;
	if (sorted == NULL) {
	    sorted = temp;
	    sorted->next = NULL;
	} else {
	    s_temp = sorted;
	    prev = NULL;
	    while(s_temp != NULL) {
		if ((temp->val > s_temp->val)) {
		    if (s_temp->next == NULL) {
			s_temp->next = temp;
			temp->next = NULL;
			break;
		    } else {
			prev = s_temp;
			s_temp = s_temp->next;
		    }
		} else {
		    if (prev == NULL) {
			temp->next = s_temp;
			sorted = temp;
		    } else {
			prev->next = temp;
			temp->next = s_temp;
		    }
		    break;
		}
	    }
	}
	temp = next;
    }

    root = sorted;
}

int main(){
    SLIST *temp = NULL;
    SLIST *temp1 = NULL;
    int i = 0;

    for (i = 0; i < MAX_ELEMENTS; i++) {
	insert_node(rand()%10000);
    }
    display_list();
    insertion_sort();
    display_list();
}
