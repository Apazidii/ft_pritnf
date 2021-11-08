#include "head.h"

void test(char *s, int k)
{
	ft_printf(s, k);
	   printf(s, k);
	printf("-----------------\n");
}

int main()
{
	test("_%-30#.15x_\n", 52625);
	test("_%#30.15x_\n", 52625);

	// https://github.com/paulo-santana/ft_printf_tester.git
}