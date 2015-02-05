/*
** copy_alias.c for copy_alias in /home/letexi_a//Documents/Tek1/Projets/42sh/alias/replace_alias
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed May  2 10:47:13 2012 alexis letexier
** Last update Wed May  9 17:43:33 2012 alexis letexier
*/

#include	<alias.h>

int     copy_start_alias(char **ret, char **arg, int n, int i)
{
  while (n < i)
    {
      ret[n] = malloc(sizeof(ret[n]) * my_strlen(arg[n]) + 1);
      if (ret[n] == NULL)
        return (-1);
      copy_to_wordtab(arg[n], ret[n]);
      n++;
    }
  return (n);
}

int     copy_int_alias(char **tmp, char **ret, int n)
{
  int   b;

  b = 0;
  while (tmp[b] != NULL)
    {
      ret[n] = malloc(sizeof(ret[n]) * my_strlen(tmp[b]) + 1);
      if (ret[n] == NULL)
        return (-1);
      copy_to_wordtab(tmp[b], ret[n]);
      n++;
      b++;
    }
  return (n);
}

int     copy_end_alias(char **ret, int n, char **arg, int a)
{
  while (arg[a] != NULL)
    {
      ret[n] = malloc(sizeof(ret[n]) * my_strlen(arg[a]) + 1);
      if (ret[n] == NULL)
        return (-1);
      copy_to_wordtab(arg[a], ret[n]);
      n++;
      a++;
    }
  return (n);
}
