/*
** main.c for glob in /home/quemen_g//Projects/42SH/Ted/test_readdir/toto
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Wed Apr  4 13:43:22 2012 guillaume quemener
** Last update Fri May 18 17:18:59 2012 tom rossi
*/

#include	<glob.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<str.h>
#include	<my_glob.h>

void		my_globfree(glob_t *paths)
{
  int		i;

  i = 0;
  while ((paths)->gl_pathv[i] != '\0')
    free((paths)->gl_pathv[i++]);
  free((paths)->gl_pathv);
  return ;
}
void		show_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putstr(" ");
      i++;
    }
}
char		**my_globbing(char *str)
{
  glob_t	paths;
  int		ret;
  char		**tab;

  ret = glob(str, 0, NULL, &paths);
  if (ret == 0)
    {
      tab = paths.gl_pathv;
      return (tab);
    }
  return (NULL);
}

char		**my_func_glob(char *str)
{
  char		**tab_gl;

  tab_gl = my_globbing(str);
  return (tab_gl);
}
