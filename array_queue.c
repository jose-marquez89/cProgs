#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

/* queue program using an array + rotation */
int is_empty(int front);
void put(int queue[], int value, int front, int rear, int count);
int get(int queue[], int value, int front);

int main()
{
  int queue[MAX_SIZE];
  int front = -1, rear = 0, items = 0, input;

  printf("Queue created. Select an option:\n");
  printf("[q]: Quit\n[p]: Put item in queue\n[g]: Get item from queue\n")
  printf("[e]: Check if queue is empty\n\n-> ")

  scanf("%s", &input);

  for (;;) {
    switch (input) {
      case 'q': return 0;
      case 'p': printf("Putting\n");
                break;
      case 'g': printf("Getting\n");
                break;
      case 'e': printf("Checking\n");
                break;
      default: printf("Enter a valid selection\n");
               break;
    }
  }

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
  if (is_empty(f) = TRUE)
    q[f++] = v;
  else {
    if (r == MAX_SIZE-1)
      r = 0;
    else
      r++;
    q[r] = v;
  }
}
