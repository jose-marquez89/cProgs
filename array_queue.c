#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0


/* A very "wordy" queue program using an array + rotation */
int is_empty(int *front);
void put(int queue[], int value, int *front, int *rear, int *count);
int get(int queue[], int *front, int *rear, int *count);

int main()
{
  int queue[MAX_SIZE];
  int front = -1, rear = 0, qsize = 0;
  int input, return_val;
  char selection;

  printf("Queue created. Select an option:\n");
  printf("[q]: Quit\n[p]: Put item in queue\n[g]: Get item from queue\n");
  printf("[e]: Check if queue is empty\n\n");

  for (;;) {
    printf("-> ");
    scanf(" %c", &selection);
    switch (selection) {
      case 'q': return 0;
      case 'p': printf("Enter value to put in queue: ");
                scanf(" %i", &input);
                printf("Putting %i in queue...\n", input);
                put(queue, input, &front, &rear, &qsize);
                break;
      case 'g': return_val = get(queue, &front, &rear, &qsize);
                if (return_val == -1)
                  printf("Queue is empty!\n");
                else
                  printf("Value %i returned from queue\n", return_val);
                break;
      case 'e': printf("Checking queue...\n");
                if (is_empty(&front) == TRUE)
                  printf("Queue is empty\n");
                else
                  printf("The queue is not empty\n");
                break;
      default: printf("Enter a valid selection\n");
               break;
    }
  }
}

int is_empty(int *f)
{
  if (*f < 0)
    return TRUE;
  else
    return FALSE;
}

void put(int q[], int v, int *f, int *r, int *c)
{
  if (*c == MAX_SIZE) {
    printf("Queue has reached capacity!\n");
    return;
  }

  if (is_empty(f) == TRUE) {
    q[++(*f)] = v;
    (*c)++;
  }
  else {
    if (*r == MAX_SIZE-1)
      *r = 0;
    else
      (*r)++;
    q[*r] = v;
    (*c)++;
  }
}

int get(int q[], int *f, int *r, int *c)
{
  int temp;
  int return_val;

  if (is_empty(f) == TRUE) {
    return -1;
  }

  if (*f == MAX_SIZE-1) {
    printf("*f has reached max size\n");
    temp = *f;
    *f = 0;
    return_val = q[temp];
  }
  else
    return_val =  q[(*f)++];

  (*c)--;
  /* Reset front and rear if queue has been emptied */
  if (*c == 0) {
    *f = -1;
    *r = 0;
  }
  return return_val;
}
