/*
** bin.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Mon Dec 12 16:05:08 2011 tom rossi
** Last update Wed May  2 16:33:06 2012 tom rossi
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <env.h>
#include <str.h>

char	*binpath(char **path, int i, char *name, DIR *dir)
{
  char	*out;
  char	*a;

  a = my_strcat(path[i], "/");
  out = my_strcat(a, name);
  free(a);
  free_tab(path);
  free(path);
  closedir(dir);
  return (out);
}

char	*freenull(char **path)
{
  free_tab(path);
  free(path);
  return (NULL);
}

char	*get_cmd_path(char *exe, t_env *env)
{
  DIR	*dir;
  t_env	*tmp;
  struct dirent *result;
  char	**path;
  int	i;

  tmp = env;
  i = 0;
  while (tmp && my_strcmp(tmp->name, "PATH"))
    tmp = tmp->next;
  if (!tmp)
    return (NULL);
  path = my_str_to_wordtab(tmp->value, ":");
  while (path[i])
    {
      if ((dir = opendir(path[i])))
	while ((result = readdir(dir)))
	  if (!my_strcmp(result->d_name, exe))
	    return (binpath(path, i, result->d_name, dir));
      if (dir)
	closedir(dir);
      i++;
    }
  return (freenull(path));
}
