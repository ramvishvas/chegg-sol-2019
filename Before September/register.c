#include <stdio.h>
int main(int argc, char const *argv[])
{
	register int x = 10;
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n",x);
	}
	// this is not applicable
	printf("%p\n",&x);
	return 0;
}