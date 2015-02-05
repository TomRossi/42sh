/*
** add_in_history.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/history
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Fri May 11 16:57:00 2012 maxime lespagnol
** Last update Wed May 16 15:54:08 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<str.h>

int	check_double_hist(char *new, char **hist)
{
  int	i;

  i = 0;
  while (hist != NULL && hist[i] != NULL)
    {
      if (my_strcmp(hist[i], new) == 0)
	return (1);
      i++;
    }
  return (0);
}

char	**delete_double_hist(char *new, char **hist)
{
  char	**tmp;
  int	k;
  int	i;

  if ((tmp = malloc(sizeof(*tmp) * (len_tab(hist)))) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (hist != NULL && hist[i] != NULL && my_strcmp(hist[i], new) != 0)
    tmp[k++] = my_strdup(hist[i++]);
  if (hist != NULL && hist[i] != NULL && my_strcmp(hist[i], new) == 0)
    i++;
  while (hist != NULL && hist[i] != NULL)
    tmp[k++] = my_strdup(hist[i++]);
  tmp[k] = NULL;
  return (tmp);
}

char	**add_in_hist(char *new, char **hist)
{
  char	**ret;
  int	i;
  int	k;

  if ((ret = malloc(sizeof(*ret) * (len_tab(hist) + 2))) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (hist != NULL && hist[i] != NULL)
    ret[k++] = my_strdup(hist[i++]);
  ret[k++] = my_strdup(new);
  ret[k] = NULL;
  return (ret);
}

char	**add_in_history(char *new, char **hist)
{
  char	**tmp;

  tmp = NULL;
  if (new != NULL && new[0] != '\0')
    {
      if ((check_double_hist(new, hist)) != 0)
	{
	  tmp = delete_double_hist(new, hist);
	  xfree_tab(hist);
	  hist = my_strdup_tab(tmp);
	  xfree_tab(tmp);
	}
      tmp = add_in_hist(new, hist);
      xfree_tab(hist);
      hist = my_strdup_tab(tmp);
      xfree_tab(tmp);
    }
  return (hist);
}
