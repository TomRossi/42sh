/*
** pwd.c for mysh in /home/rossi_t//random/projets/mini_pwd
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Thu Dec 22 10:41:58 2011 tom rossi
** Last update Sat May 19 11:06:06 2012 tom rossi
*/

#include <stdlib.h>
#include <builtin.h>
#include <env.h>
#include <str.h>

char	*slash(char *freeme)
{
  char	*str;

  if (freeme)
    free(freeme);
  if (!(str = malloc(sizeof(*str) * 2)))
    return (NULL);
  str[0] = '/';
  str[1] = '\0';
  return  (str);
}

char    *rmpath(char *str)
{
  int   i;
  int   x;
  char *path;

  i = 0;
  x = my_strlen(str) - 1;
  while (x > 0 && str[x] && str[x] == '/')
    x--;
  while (x > 0 && str[x] && str[x] != '/')
    x--;
  if (x <= 0)
    return (slash(str));
  if (!(path = malloc(sizeof(*path) * (x + 3))))
    return (NULL);
  while (i <= x)
    {
      path[i] = str[i];
      i++;
    }
  if (i > 0 && path[i - 1] != '/')
    path[i++] = '/';
  path[i] = '\0';
  free(str);
  return (path);
}

char    *pwdcat(char *path, char *exe)
{
  int i;
  int a;
  char *str_out;

  a = 0;
  i = 0;
  str_out = malloc(sizeof(*str_out) *
		   (my_strlen(path) + my_strlen(exe) + 4));
  if (!str_out)
    return (NULL);
  while (path[a])
    {
      str_out[a] = path[a];
      a++;
    }
  if (a > 0 && str_out[a - 1] && str_out[a - 1] != '/')
    str_out[a++] = '/';
  while (exe[i])
    str_out[a++] = exe[i++];
  str_out[a++] = '/';
  str_out[a] = '\0';
  free(path);
  return (str_out);
}

char    *definepwd(char *str, char *pwd)
{
  char **tab;
  int   i;
  char *path;

  i = 0;
  tab = NULL;
  if (str && !(str[0] && !str[1] && str[0] == '/'))
    tab = my_str_to_wordtab(str, "/");
  if (str && str[0] != '/')
    path = my_strdup(pwd);
  else
    path = slash(NULL);
  while (tab && tab[i])
    {
      if (!my_strcmp(tab[i], ".."))
	path = rmpath(path);
      else if (my_strcmp(tab[i], "."))
	path = pwdcat(path, tab[i]);
      i++;
    }
  if (tab)
    free_tab(tab);
  if (tab)
    free(tab);
  return (path);
}
