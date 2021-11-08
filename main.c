#include "head.h"

void test(char *s, char *k)
{
	ft_printf(s, k);
	   printf(s, k);
	printf("-----------------\n");
}

int main()
{

	test("_%s_\n", "HELLO WORLD");
	test("_%.5s_\n", "HELLO WORLD");
	test("_%30.5s_\n", "HELLO WORLD");
	test("_%-30.5s_\n", "HELLO WORLD");
	// https://github.com/paulo-santana/ft_printf_tester.git
}