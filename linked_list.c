#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(void);
void delete(void);
void contains(void);

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *tail = NULL;

    /* allocate 3 nodes in heap */
    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    tail = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = tail;

    tail->data = 3;
    tail->next = NULL;

    printf("Head data: %d\n", head->data);
    printf("Address of next: %p\n", head->next);
    free(head);
    printf("%p", head);

    return 0;
}

/* insert: insert an integer value into a node */
void insert(void)
{
    struct node *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct node));
    /* if space cannot be allocated for node, print message */
    if (new_node = NULL) {
        print("Could not allocate space for new list member\n");
    }
    
}
