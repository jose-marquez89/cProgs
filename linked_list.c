#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *next;
};

/* points to the head node */
struct node *head = NULL;

void insert_at_head(void);
void delete(void);
void contains(void);

int main()
{
    char option;
    int quit = FALSE;

    while (quit == FALSE) {
        printf("Enter an option: ");
        scanf(" %c", &option);

        while(getchar() != '\n')
            ;
        switch (option) {
            case 'i': insert_at_head();
                      break;
            case 'q': quit = TRUE;
                      break;
            default: printf("Not a valid option\n");
        }
        printf("\n");
    }

    printf("Exiting.\n");

    return 0;
}

/* insert: insert an integer value into the head of list, not ordered */
void insert_at_head(void)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    /* if space cannot be allocated for node, print message */
    if (new_node == NULL) {
        printf("Could not allocate space for new list member\n");
        return;
    }

    printf("Enter an whole number to store in the list: ");
    scanf("%d", &new_node->data);

    if (head == NULL) {
        head = new_node;
        head->next = NULL;
    } else {
        new_node->next = head;
        head = new_node;
    }

    printf("<%d> inserted at %p\n", head->data, &head);
}
