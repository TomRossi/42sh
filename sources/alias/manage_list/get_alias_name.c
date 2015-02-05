/*
** get_alias_name.c for get_alias_name in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed Mar 28 10:50:32 2012 alexis letexier
** Last update Wed May  9 17:40:33 2012 alexis letexier
*/

#include	<alias.h>

int     len_alias_name_one(char *str)
{
  int   compt;
  int   n;

  n = 0;
  compt = 0;
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  while ((str[n] != ' ' && str[n] != '\t') && str[n] != '\0')
    n++;
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  while ((str[n] != ' ' && str[n] != '\t') && str[n] != '\0')
    {
      compt++;
      n++;
    }
  return (compt);
}

char	*get_alias_name_one(char *str, int a, int n)
{
  int	len;
  char	*ret;

  len = len_alias_name_one(str);
  ret = malloc(sizeof(*ret) * len + 1);
  if (ret == NULL)
    return (NULL);
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  while ((str[n] != ' ' && str[n] != '\t') && str[n] != '\0')
    n++;
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  while ((str[n] != ' ' && str[n] != '\t') && str[n] != '\0')
    ret[a++] = str[n++];
  ret[a] = '\0';
  return (ret);
}

char    *get_alias_name(char *str)
{
  char  *ret;

  ret = get_alias_name_one(str, 0, 0);
  return (ret);
}
