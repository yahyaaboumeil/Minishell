#include "exec.h"


char *_env(char *p)
{

    p = getenv("PWD");
    return p;
}

int main()
{
    char *path;

    path = getenv("HOME");
    printf("%s\n", path);

	return 0;
}