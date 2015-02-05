/*
** concat_arg_alias.c for concat_arg_alias in /home/letexi_a//Documents/Tek1/Projets/42sh/alias/manage_list
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Fri May  4 14:26:06 2012 alexis letexier
** Last update Wed May 16 15:40:26 2012 alexis letexier
*/

#include	<alias.h>

int	len_concat(char **tab_a)
{
  int	ret;
  int	n;
  int	a;

  n = 2;
  a = 0;
  ret = 0;
  while (tab_a[n] != NULL)
    {
      while (tab_a[n][a] != '\0')
	a++;
      ret = ret + a + 1;
      a = 0;
      n++;
    }
  return (ret);
}

char    *concat_arg_alias(char **tab_a)
{
  int   n;
  int   a;
  int   b;
  char  *ret;

  n = 2;
  a = 0;
  b = 0;
  ret = malloc(sizeof(*ret) * len_concat(tab_a) + 1);
  if (ret == NULL)
    return (NULL);
  while (tab_a[n] != NULL)
    {
      while (tab_a[n][a] != '\0')
        {
          ret[b++] = tab_a[n][a];
          a++;
        }
      n++;
      if (tab_a[n] != NULL)
        ret[b++] = ' ';
      a = 0;
    }
  ret[b] = '\0';
  return (ret);
}
