#include "builtin.h"

int	count_args(char **args)
{
	int	i;
	
	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	pwd(char **args)
{
	char	buffer[100];
	int 	i;

	i = count_args(args);
	if (i == 0)	
	{
		printf("%s",getcwd(buffer, 100));
		return (1);
	}
	else 
		printf("minishell :  you have to enter no option :)\n");
	return (1);

}

int main()
{
	char buffer[100];
	printf("%s",getcwd(buffer, 100));
}
