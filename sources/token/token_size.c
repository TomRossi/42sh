/*
** token_size.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Mon Apr 30 18:42:32 2012 tom rossi
** Last update Tue May  8 11:21:35 2012 tom rossi
*/

#include <token.h>
#include <str.h>

void	calc_close(int *i, int *x, char c, char *s)
{
  (*i)++;
  if (c == s[*i] && is_char_valid(c, S_MULT))
    (*i)++;
  (*x)++;
}

void	size_init(int *tab)
{
  tab[C_SIMPLE] = M_SIMPLE;
  tab[C_DOUBLE] = M_DOUBLE;
}

int	calc_size(t_list **list, char *s, int *i, int *x)
{
  int	c;
  int   tab[40];

  size_init(tab);
  if (is_char_valid(s[*i], S_SEP) == FALSE)
    add_node(list, get_str(s, *i, M_NORMAL), (*x)++, M_NORMAL);
  wait_for(s, S_SEP_ALL, i);
  skip_char(s, S_SPACE, i);
  if (s[*i] && is_char_valid(s[*i], S_SEP) == TRUE)
    {
      c = s[*i];
      if (c == C_DOUBLE || c == C_SIMPLE)
	{
	  (*i)++;
	  add_node(list, get_str(s, *i, tab[c]), (*x), tab[c]);
	  while (s[*i] && s[*i] != c)
	    (*i)++;
	}
      calc_close(i, x, c, s);
    }
  skip_char(s, S_SPACE, i);
  return (RETURN_SUCCESS);
}

int     get_size(char *s, t_list **list)
{
  int   i;
  int   x;

  x = 0;
  i = 0;
  skip_char(s, S_SPACE, &i);
  while (s[i])
    calc_size(list, s, &i, &x);
  return (x);
}
