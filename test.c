#include <stdio.h>
#include <stdlib.h>
#include "exec.h"
#include <unistd.h>

int change_dirc()
{
	if (chdir("/tmp") != 0)
		perror("cd");	
	return 0;
}



int main(int ac, char **av, char **env)
{
    
    if (fork())
    {
	char *arg[] = {"ls", NULL};
	execve("/usr/bin/ls", arg, env); 
	printf("the cmd is not found\n"); 
    }
    return (0);
}

// int main(int ac, char **av)
// {
// 	t_cmd node;

// 	node.args->word->str = "Desktop/Minishell";
// 	node.args->next->word->str =  "klfdjs";
// 	my_cd(node);	
// 	// if (fork() == 0)
// 	// {
// 	// 	printf(getenv("HOME"));
// 	// 	char **arg = {"cd", "cd /home/yahya/Desktop", NULL};
// 	// 	execvp("ls", "/home/yahya/Desktop/libft/" );
// 	// }
// 	// wait(NULL);
// 		return (0);
// }
