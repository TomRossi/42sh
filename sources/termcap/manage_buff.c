/*
** add_buff.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Mon Apr 30 18:51:36 2012 maxime lespagnol
** Last update Thu May 10 18:16:29 2012 maxime lespagnol
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<lib.h>
#include	<str.h>
#include	<term_man.h>

int	make_modif(t_term *ptr, int i)
{
  ptr->flag = STR_ENTER;
  return (i + 1);
}

int	add_buff(t_term *ptr, int i, int k, int size)
{
  char	*tmp;
  int	j;

  size = my_strlen(ptr->buff) + my_strlen(ptr->str);
  j = 0;
  if ((tmp = malloc(sizeof(*tmp) * (size + 1))) == NULL)
    return (-1);
  while (ptr->str != NULL && j < ptr->pos)
    tmp[k++] = ptr->str[j++];
  while (ptr->buff[i] != '\0')
    {
      tmp[k++] = ptr->buff[i++];
      if (ptr->buff[i] == '\n')
	i = make_modif(ptr, i);
    }
  while (ptr->str != NULL && ptr->str[j] != '\0')
    tmp[k++] = ptr->str[j++];
  tmp[k] = '\0';
  xfree(ptr->str);
  if ((ptr->str = my_strdup(tmp)) == NULL)
    return (-1);
  xfree(tmp);
  return (0);
}

int	del_one(t_term *ptr, int i, int k, char *tmp)
{
  if (my_strlen(ptr->str) > 0)
    {
      if ((tmp = malloc(sizeof(*tmp) * (my_strlen(ptr->str) + 1))) == NULL)
	return (-1);
      if (ptr->flag == BACKSPACE)
	{
	  while ((i + 1) != ptr->pos && ptr->str[i] != '\0')
	    tmp[k++] = ptr->str[i++];
	}
      if (ptr->flag == DELETE)
	{
          while (i != ptr->pos && ptr->str[i] != '\0')
            tmp[k++] = ptr->str[i++];
	}
      if (ptr->str[i] != '\0')
	i++;
      while (ptr->str != NULL && ptr->str[i] != '\0')
	tmp[k++] = ptr->str[i++];
      tmp[k] = '\0';
      xfree(ptr->str);
      if ((ptr->str = my_strdup(tmp)) == NULL)
	return (-1);
      xfree(tmp);
    }
  return (0);
}

int	manage_str_modif(t_term *ptr)
{
  int	ret;

  ret = 0;
  if (ptr->flag == NOTH)
    ret = add_buff(ptr, 0, 0, 0);
  else if (ptr->flag == DELETE || ptr->flag == BACKSPACE)
    ret = del_one(ptr, 0, 0, NULL);
  return (ret);
}

int	manage_buff(t_term *ptr)
{
  char	buff[4000];
  int	ret;

  if ((ret = read(0, buff, 3999)) == -1)
    return (-1);
  buff[ret] = '\0';
  ptr->flag = determ_flag(buff);
  xfree(ptr->buff);
  if ((ptr->buff = my_strdup(buff)) == NULL)
    return (-1);
  if (manage_str_modif(ptr) == -1)
    return (-1);
  return (0);
}
