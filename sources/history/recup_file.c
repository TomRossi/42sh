/*
** recup_file.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/history
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Fri May 11 17:17:25 2012 maxime lespagnol
** Last update Wed May 16 17:06:17 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<str.h>
#include	<hist.h>

int	len_tab(char **tmp)
{
  int	i;

  i = 0;
  while (tmp != NULL && tmp[i] != NULL)
    i++;
  return (i);
}

char	**add_str_tab(char **out, char *str, int i, int k)
{
  char	**tmp;

  tmp = NULL;
  if ((tmp = malloc(sizeof(*tmp) * (len_tab(out) + 2))) == NULL)
    return (NULL);
  while (out != NULL && out[i] != NULL)
    tmp[k++] = my_strdup(out[i++]);
  tmp[k++] = my_strdup(str);
  tmp[k] = NULL;
  return (tmp);
}

char	**my_strdup_tab(char **tmp)
{
  char	**out;
  int	i;
  int	k;

  out = NULL;
  if ((out = malloc(sizeof(*out) * (len_tab(tmp) + 1))) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (tmp != NULL && tmp[i] != NULL)
    out[k++] = my_strdup(tmp[i++]);
  out[k] = NULL;
  return (out);
}

int	len_all(char **out)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (out != NULL && out[i] != NULL)
    {
      while (out[i][j] != '\0')
	{
	  j++;
	  k++;
	}
      i++;
      j = 0;
    }
  return (k);
}

char	**recup_file(char *file)
{
  char	**tmp;
  char	**out;
  char	*str;
  int	fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  tmp = NULL;
  out = NULL;
  while ((str = get_next_line(fd)) != NULL && len_all(out) < 100000)
    {
      tmp = add_str_tab(out, str, 0, 0);
      xfree_tab(out);
      out = my_strdup_tab(tmp);
      xfree_tab(tmp);
      xfree(str);
    }
  close(fd);
  return (out);
}
