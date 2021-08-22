#include <iostream>

void    touppercase(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') 
		{
			str[i] -= 32;
		}
	}
}

void    print_args(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		touppercase(argv[i]);      
		std::cout << argv[i];
	}
	std::cout << std::endl;
}

#include <string>

int main(int argc, char *argv[])
{
	char *def_argv[2];

	if (argc != 1)
	{
		print_args(argc, argv);
	}
	else
	{
		def_argv[0] = argv[0];
		def_argv[1] = (char *)"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		print_args(2, def_argv); 
	}
	return (0);
}