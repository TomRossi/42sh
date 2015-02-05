/*
** manage_copy_and_paste.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May  2 05:13:31 2012 maxime lespagnol
** Last update Wed May 16 16:36:59 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<term.h>
#include	<str.h>
#include	<lib.h>
#include	<term_man.h>

char	*copy_into_beg(t_term *ptr, int k, int j)
{
  int	i;
  char	*tmp;

  i = ptr->pos;
  tmp = NULL;
  if (i > 0 && ptr->str != NULL)
    {
      if ((tmp = malloc(sizeof(*tmp) * (i + 2))) == NULL)
	return (NULL);
      while (j <= i && ptr->str[j] != '\0')
	tmp[k++] = ptr->str[j++];
      tmp[k] = '\0';
    }
  return (tmp);
}

char	*copy_into_end(t_term *ptr, int i, int j, int k)
{
  char	*tmp;

  i = ptr->pos;
  tmp = NULL;
  if (i < (my_strlen(ptr->str) - 1) && ptr->str != NULL)
    {
      while (ptr->str[i] != '\0')
	{
	  i++;
	  k++;
	}
      if ((tmp = malloc(sizeof(*tmp) * (k + 2))) == NULL)
	return (NULL);
      i = ptr->pos;
      while (ptr->str[i] != '\0')
	tmp[j++] = ptr->str[i++];
      tmp[j] = '\0';
    }
  return (tmp);
}

int	delete_copy(t_term *ptr, int i, int k)
{
  char	*tmp;

  if ((tmp = malloc(sizeof(*tmp) * (ptr->pos + 2))) == NULL)
    return (0);
  while (ptr->str != NULL && i < ptr->pos && ptr->str[i] != '\0')
    tmp[k++] = ptr->str[i++];
  tmp[k] = '\0';
  xfree(ptr->str);
  ptr->str = my_strdup(tmp);
  xfree(tmp);
  return (0);
}

int	delete_copy_w(t_term *ptr, int i, int k)
{
  char	*tmp;

  i = ptr->pos;
  if (i > 0)
    {
      while (ptr->str != NULL && ptr->str[i] != '\0')
	{
	  i++;
	  k++;
	}
      if ((tmp = malloc(sizeof(*tmp) * (k + 2))) == NULL)
	return (0);
      i = ptr->pos;
      k = 0;
      while (ptr->str != NULL && ptr->str[i] != '\0')
	tmp[k++] = ptr->str[i++];
      tmp[k] = '\0';
      xfree(ptr->str);
      ptr->str = my_strdup(tmp);
      xfree(tmp);
    }
  return (0);
}
void	manage_copy_and_paste(t_term *ptr)
{
  char	*cpy;

  cpy = NULL;
  if (ptr->flag == COPY_W)
    cpy = copy_into_beg(ptr, 0, 0);
  if (ptr->flag == COPY)
    cpy = copy_into_end(ptr, 0, 0, 0);
  if (ptr->flag == COPY || ptr->flag == COPY_W)
    add_into_struct(cpy, ptr);
  if (ptr->flag == COPY)
    delete_copy(ptr, 0, 0);
  if (ptr->flag == COPY_W)
    delete_copy_w(ptr, 0, 0);
  if (ptr->flag == COPY || ptr->flag == COPY_W)
    aff_copy(ptr);
  xfree(cpy);
  if (ptr->flag == PASTE)
    instance_paste(ptr);
}
