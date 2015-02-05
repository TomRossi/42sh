/*
** fill_pipe.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr  4 13:39:12 2012 tom rossi
** Last update Fri May 18 14:00:34 2012 tom rossi
*/

#include <stdlib.h>
#include <tree.h>
#include <token.h>
#include <str.h>

int	*return_av_type(int *tab, int i)
{
  tab[i] = 0;
  return (tab);
}

char	**return_av(char **av, int i)
{
  av[i] = '\0';
  return (av);
}

int	av_size(t_list *tmp, int i)
{
  while (tmp && tmp->type != T_CMD && tmp->type != T_BIN)
    {
      if (tmp && tmp->type == T_ARG)
	i++;
      tmp = tmp->next;
    }
  return (i);
}

char	**build_av(t_list *list)
{
  t_list	*tmp;
  char		**av;
  int		i;

  if (!list)
    return (NULL);
  i = av_size(list->next, 1);
  if (!(av = malloc(sizeof(*av) * (i + 1))))
    return (NULL);
  i = 1;
  tmp = list;
  if (!tmp->data)
    return (NULL);
  av[0] = my_strdup(tmp->data);
  tmp = tmp->next;
  while (tmp && tmp->type != T_CMD && tmp->type != T_BIN)
    {
      if (tmp->type == T_ARG)
	av[i++] = my_strdup(tmp->data);
      tmp = tmp->next;
    }
  return (return_av(av, i));
}

int	*build_av_type(t_list *list)
{
  t_list	*tmp;
  int		*av;
  int		i;

  if (!list)
    return (NULL);
  i = av_size(list->next, 1);
  if (!(av = malloc(sizeof(*av) * (i + 1))))
    return (NULL);
  i = 1;
  tmp = list;
  if (!tmp->data)
    return (NULL);
  av[0] = tmp->mode;
  tmp = tmp->next;
  while (tmp && tmp->type != T_CMD && tmp->type != T_BIN)
    {
      if (tmp->type == T_ARG)
	av[i++] = tmp->mode;
      tmp = tmp->next;
    }
  return (return_av_type(av, i));
}
