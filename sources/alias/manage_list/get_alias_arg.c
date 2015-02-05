/*
** get_alias_arg.c for get_alias_arg in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed Mar 28 10:51:56 2012 alexis letexier
** Last update Wed May  9 17:40:45 2012 alexis letexier
*/

#include	<alias.h>

int     len_alias_arg_one(char *str)
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
    n++;
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  while (str[n] != '\0')
    {
      n++;
      if (str[n] != '"' && str[n] != '\'')
	compt++;
    }
  return (compt);
}

int	zap_space(int n, char *str)
{
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  while ((str[n] != ' ' && str[n] != '\t') && str[n] != '\0')
    n++;
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  while ((str[n] != ' ' && str[n] != '\t') && str[n] != '\0')
    n++;
  while ((str[n] == ' ' || str[n] == '\t') && str[n] != '\0')
    n++;
  return (n);
}

char	*get_alias_arg_one(char *str, int n, int a)
{
  char  *ret;
  int   len;

  len = len_alias_arg_one(str);
  ret = malloc(sizeof(*ret) * len + 1);
  if (ret == NULL)
    return (NULL);
  n = zap_space(n, str);
  while (str[n] != '\0')
    {
      if (str[n] != '"' && str[n] != '\'')
	ret[a++] = str[n++];
      else
	n++;
    }
  ret[a] = '\0';
  return (ret);
}

char    *get_alias_arg(char *str)
{
  char  *ret;

  ret = get_alias_arg_one(str, 0, 0);
  return (ret);
}
