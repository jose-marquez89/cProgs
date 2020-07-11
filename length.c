#include <stdio.h>

int main()
{
	int len = 0;

	printf("Enter a message: ");
	while (getchar() != '\n') 
		len++;
		ch = getchar();
	printf("Your message was %d character(s) long.\n", len);

	return 0;
}
