#include <stdio.h>  

int zero_count(int n);

int main(int argc, char *argv[])
{
	printf("zero_count is %d...\n", zero_count(1024));
	return 0;
}

int zero_count(int n)
{
	int count = 0;
	while (n > 0) {
		n = n / 5;
		count += n;
	}
	return count;
}