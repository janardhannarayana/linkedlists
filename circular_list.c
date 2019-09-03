#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int val;
    struct slist *next;
}SLIST;

SLIST *root = NULL;

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

void display_cll()
{
    SLIST *temp = root;
    int i = 10;

    while (i--) {
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void break_circular_list()
{
    SLIST *sp = root;
    SLIST *fp = root->next->next;
    int len = 0;

    while (sp && fp && fp->next){
        sp = sp->next;
        fp = fp->next->next;
        if (sp == fp) {
            printf("Circular linked list detected\n");
            if (sp == sp->next) {
                len = 1;
                sp->next = NULL;
            } else {
                fp = fp->next->next;
                len++;
                while(fp != sp && fp->next != sp) {
                    fp = fp->next->next;
                    len++;
                }
                if(fp == sp) {
                    len *= 2;
                    sp = sp->next;
                } else if (fp->next = sp) {
                    len = (len * 2) + 1;
                }
                printf("Number of nodes in circular list = %d\n",len);
                sp = root;
                if (sp == fp) {
                    while(sp->next != fp) {
                        sp = sp->next;
                    }
                    sp->next = NULL;
                } else {
                    while(sp->next != fp->next) {
                        sp = sp->next;
                        fp = fp->next;
                    }
                    fp->next = NULL;
                }
            }
            printf("Circular linked lists with %d nodes\n",len);
            break;
        }
    }
}

int main(){
    SLIST *temp = NULL;
    SLIST *temp1 = NULL;
    temp = insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    insert_node(6);
    insert_node(7);
    display_list();
    temp1 = root;
    while(temp1->next)
        temp1 = temp1->next;
    temp1->next = temp;
    display_cll();
    break_circular_list();
    display_list();
}
