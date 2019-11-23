#include <stdio.h>
int main(int argc, char const *argv[])
{
	float usd, rate, brl;

	printf("Moving to Brazil\n");

	printf("US Dollar Amount: ");
	scanf("%f", &usd);

	printf("Exchange Rate: ");
	scanf("%f", &rate);

	printf("Converted to Brazilian Real: %0.3f\n",(usd*rate));

	printf("Thank you for converting $%0.3f to BRL!\n", usd);
	return 0;
}