/*
** list.c for 42 in /home/quemen_g//Projects/Max
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Tue May 15 14:07:03 2012 guillaume quemener
** Last update Fri May 18 16:10:58 2012 guillaume quemener
*/
#include	<stdio.h>
#include	<dirent.h>
#include	<stdlib.h>
#include        <sys/types.h>
#include	<unistd.h>
#include        <sys/stat.h>
#include	<auto_complete_lib.h>
#include	<str.h>
#include	<auto_glob.h>

t_list		*add_to_list_bin(t_list *list, char *str)
{
  t_glob	*match;
  int		i;

  i = 0;
  match = malloc(sizeof(*match));
  if (match == NULL)
    return (NULL);
  match = auto_globbing(str, match);
  if (match == NULL)
    return (list);
  if (match->nb == 0)
    return (list);
  while (match->_tab[i] != '\0' && (i + 1) < match->nb)
    my_put_in_list(&list, match->_tab[i++]);
  return (list);
}

t_list		*list_files(char *str, t_list *list)
{
  struct dirent	*entry;
  struct        stat sb;
  DIR		*dirp;
  int		ret;

  ret = 0;
  if ((dirp = opendir(str)) == NULL)
    return (NULL);
  while ((entry = readdir(dirp)) != NULL)
    {
      stat(entry->d_name, &sb);
      if (&sb == NULL)
	return (NULL);
      if (entry->d_name[0] != '.')
	my_put_in_list(&list, entry->d_name);
    }
  closedir(dirp);
  return (list);
}

int		my_put_in_list(t_list **list, char *str)
{
  t_list	*element;

  element = malloc(sizeof(*element));
  if (element == NULL)
    return (1);
  element->file = my_strdup(str);
  element->next = *list;
  *list = element;
  return (0);
}

int		my_list_size(t_list *begin)
{
  int		i;
  t_list	*tmp;

  i = 0;
  tmp = begin;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  return (i);
}

t_list		*rm_list(t_list *list)
{
  t_list	*tmp;
  t_list	*ptmp;

  if (list == NULL)
    return (NULL);
  if (list->next == NULL)
    {
      free(list);
      return (NULL);
    }
  tmp = list;
  ptmp = list;
  while (tmp->next != NULL)
    {
      ptmp = tmp;
      tmp = tmp->next;
    }
  ptmp->next = NULL;
  free(tmp);
  return (list);
}
