/*
** token.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Mar 28 12:34:35 2012 tom rossi
** Last update Sat May 19 11:10:02 2012 tom rossi
*/

#include <stdlib.h>
#include <str.h>
#include <token.h>

int	add_node(t_list **list, char *data, int x, int mode)
{
  t_list	*new;
  t_list	*last;

  last = *list;
  while (last && last->next)
    last = last->next;
  new = malloc(sizeof(*new));
  if (!new)
    return (RETURN_ERROR);
  new->data = my_strdup(data);
  new->mode = mode;
  new->next = NULL;
  new->rank = x;
  if (!last)
    *list = new;
  if (last)
    last->next = new;
  if (data)
    free(data);
  return (RETURN_ERROR);
}

char	*get_str(char *str, int i, int mode)
{
  char	*tab[3];
  int	x;
  char	*out;
  char	*wait;

  set_mode(tab);
  wait = tab[mode];
  x = i;
  wait_for(str, wait, &x);
  x = x - i;
  if (!x)
    return (NULL);
  out = malloc(sizeof(*out) * (x + 1));
  if (!out)
    return (NULL);
  x = 0;
  while (str[i] && is_char_valid(str[i], wait) == FALSE)
    out[x++] = str[i++];
  out[x] = '\0';
  return (out);
}

int	set_alpha(int *tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (tab[i] == T_ALPHA)
	{
	  if (i && (tab[i - 1] == T_IN_S || tab[i - 1] == T_OUT_S ||
		    tab[i - 1] == T_IN_D || tab[i - 1] == T_OUT_D))
	    tab[i] = T_RED;
	  else if (!i || tab[i - 1] == T_PIPE || tab[i - 1] == T_RED ||
		   tab[i - 1] == T_AND || tab[i - 1] == T_OR ||
		   tab[i - 1] == T_BRACKET_C || tab[i - 1] == T_BRACKET_O ||
		   tab[i - 1] == T_SEMICOL)
	    tab[i] = T_CMD;
	  else if (i && (tab[i - 1] == T_ARG || tab[i - 1] == T_BIN ||
			 tab[i - 1] == T_CMD))
	    tab[i] = T_ARG;
	  else
	    return (RETURN_ERROR);
	}
      i++;
    }
  return (RETURN_SUCCESS);
}

int	*token(char *s, t_list **list)
{
  int		*tab;
  int		size;
  int		ref[128];

  *list = NULL;
  delete_space(s);
  ref_tab(ref);
  size = get_size(s, list);
  tab = malloc(sizeof(*tab) * (size + 1));
  if (!tab)
    return (NULL);
  set_token(s, tab, ref);
  set_alpha(tab);
  return (tab);
}
