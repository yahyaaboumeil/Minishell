#include "exec.h"
#include "libft/libft.h"

typedef struct paht
{
    char **paths;
    char **temp;
    int valid_cmd;

} path_info;


void free_mem(char **var)
{
	int i = 0;
	while (var[i])
		free(var[i++]);
	free(var);
}

static char	**extruct_paths(char **env)
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	temp = env[i] + 5;
	path = ft_split(temp, ':');
	if (!path)
		exit((perror("ft_split failed"), 1));
	return (path);
}

static char	**join_paths_cmd(char **path, char *cmd)
{
	int		i;
	char	**new_path;
	char	*join_cmd;

	join_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path[i])
		i++;
	new_path = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (path[i])
	{
		new_path[i] = ft_strjoin(path[i], join_cmd);
		i++;
	}
	new_path[i] = NULL;
	free(join_cmd);
	free_mem(path);
	return (new_path);
}

static int	is_valid_cmd(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (access(path[i], X_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_path_cmd(char **env, char *cmd)
{
    path_info info;
	char	*temp1;

	if (ft_strchr(cmd, ' '))
	{
		info.temp = ft_split(cmd, ' ');
		info.paths = join_paths_cmd(extruct_paths(env), info.temp[0]);
		free_mem(info.temp);
	}
	else
		info.paths = join_paths_cmd(extruct_paths(env), cmd);
	info.valid_cmd = is_valid_cmd(info.paths);
	if (info.valid_cmd)
	{
		free_mem(info.paths);
		return (ft_strdup("null"));
	}
	temp1 = ft_strdup(info.paths[info.valid_cmd]);
	free_mem(info.paths);
	return (temp1);
}
