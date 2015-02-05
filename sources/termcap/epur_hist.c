/*
** epur_hist.c for 42sh in /home/lespag_m//Documents/Unix/42sh/SVN/42sh-rennes/new/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May 16 15:40:15 2012 maxime lespagnol
** Last update Wed May 16 16:33:22 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<str.h>
#include	<hist.h>

int	check_epur_need(char *str, int i, int k)
{
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  i++;
	  while (str[i] == ' ' || str[i] == '\t')
	    {
	      k++;
	      i++;
	    }
	}
      if (str[i] != '\0')
	i++;
    }
  return (k);
}

char	*epur_hist_me(char *str, int i, int k)
{
  char	*tmp;
  int	size;

  tmp = NULL;
  if (str != NULL && (size = check_epur_need(str, 0, 0)) > 0)
    {
      if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) - size + 1))) == NULL)
	return (NULL);
      while (str[i] != '\0')
	{
	  if (str[i] == ' ' || str[i] == '\t')
	    {
	      tmp[k++] = ' ';
	      while (str[i] == ' ' || str[i] == '\t')
		i++;
	    }
	  if (str[i] != '\0')
	    tmp[k++] = str[i++];
	}
      tmp[k] = '\0';
      return (tmp);
    }
  return (str);
}

char	*epur_hist(char *str)
{
  char	*tmp;

  tmp = epur_hist_me(str, 0, 0);
  if (my_strcmp(str, tmp) == 0)
    return (str);
  if (tmp[0] == ' ' && tmp[1] == '\0')
    {
      xfree(tmp);
      xfree(str);
      tmp = my_strdup("\0");
    }
  return (tmp);
}
