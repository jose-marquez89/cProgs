#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
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
  int *f, *r, *qs;
  char selection;

  f = &front;
  r = &rear;
  qs = &qsize;

  printf("Queue created. Select an option:\n");
  printf("[q]: Quit\n[p]: Put item in queue\n[g]: Get item from queue\n");
  printf("[e]: Check if queue is empty\n\n");

  for (;;) {
    printf("-> ");
    scanf("%s", &selection);
    switch (selection) {
      case 'q': printf("Front: %i - Rear: %i, Qsize: %i\n", front, rear, qsize);
                return 0;
      case 'p': printf("Enter value to put in queue: ");
                scanf("%i", &input);
                printf("Putting %i in queue...\n", input);
                put(queue, input, f, r, qs);
                break;
      case 'g': return_val = get(queue, f, r, qs);
                printf("Value %i returned from queue\n", return_val);
                break;
      case 'e': printf("Checking...\n");
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
  printf("*f: %i - *r: %i - *c: %i\n", *f, *r, *c);
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
    printf("Queue is empty!\n");
    return -1;
  }

  if (*f == MAX_SIZE-1) {
    temp = *f;
    *f = 0;
    return_val = q[temp];
  }
  else
    return_val =  q[(*f)++];

  /* Reset front and rear if queue has been emptied */
  if (*f > *r) {
    printf("*f was more than or equal to *r\n*f: %i - *r: %i\n", *f, *r);
    *f = -1;
    *r = 0;
  }

  (*c)--;
  return return_val;
}
