# include "printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	char *test;
	va_start (args, str);
	test = va_arg(args, char*);
	printf("%s", test);
	test = va_arg(args, char*);
	printf("%s", test);
	
	va_end(args);
	return 0;
}

int		main(int ac, char **av)
{
	ft_printf("test", "test2", "test3", "test4");
	return 0;
}