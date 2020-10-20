#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

/* TODO: queue doesn't work yet, need to fix */

/* queue program using an array + rotation */
int is_empty(int front);
void put(int queue[], int value, int front, int rear, int count);
int get(int queue[], int front);

int main()
{
  int queue[MAX_SIZE];
  int front = -1, rear = 0, items = 0, qsize = 0;
  int input, return_val;
  char selection;

  printf("Queue created. Select an option:\n");
  printf("[q]: Quit\n[p]: Put item in queue\n[g]: Get item from queue\n");
  printf("[e]: Check if queue is empty\n\n");

  for (;;) {
    printf("-> ");
    scanf("%s", &selection);
    switch (selection) {
      case 'q': break;
      case 'p': printf("Enter value to put in queue: ");
                scanf("%i", &input);
                printf("Putting %i in queue...\n", input);
                put(queue, input, front, rear, qsize);
                break;
      case 'g': return_val = get(queue, front);
                printf("Value %i returned from queue\n", return_val);
                break;
      case 'e': printf("Checking...\n");
                break;
      default: printf("Enter a valid selection\n");
               break;
    }
  }

  printf("Count: %i\n", qsize);
  printf("Front: %i Rear: %i\n", front, rear);

  for (qsize; rear > 0; rear--)
    printf("%i\n", queue[rear]);

}

int is_empty(int f)
{
  if (f < 0)
    return TRUE;
  else
    return FALSE;
}

void put(int q[], int v, int f, int r, int c)
{
  if (is_empty(f) == TRUE) {
    printf("queue was empty\n");
    q[f++] = v;
    c++;
  }
  else {
    if (r == MAX_SIZE-1)
      r = 0;
    else
      r++;
    q[r] = v;
    c++;
  }
}

int get(int q[], int f)
{
  int temp;
  if (f == MAX_SIZE-1) {
    temp = f;
    f = 0;
    return q[temp];
  }
  else
    return q[f++];
}
