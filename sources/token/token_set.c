/*
** token_set.c for sh$ in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Thu Mar 29 15:54:59 2012 tom rossi
** Last update Sat May 19 10:09:51 2012 tom rossi
*/

#include <str.h>
#include <token.h>

int	set_token_if(char *s, int i, char **tab_)
{
  int	c;

  c = s[i];
  if ((c == C_SIMPLE || c == C_DOUBLE) && (i = i + 1) >= 0)
    wait_for(s, tab_[c], &(i));
  i++;
  if (s[i] && is_char_valid(s[i], S_MULT) == TRUE && c == s[i])
    i++;
  return (i);
}

void    set_token(char *s, int *tab, int *ref)
{
  int   i;
  char	*tab_[40];
  int   x;

  token_init_val(tab_, &x, &i);
  skip_char(s, S_SPACE, &i);
  while (s[i])
    {
      if (is_char_valid(s[i], S_SEP) == FALSE)
	token_bin(s[i], tab, x++);
      wait_for(s, S_SEP_ALL, &i);
      skip_char(s, S_SPACE, &i);
      if (s[i] && is_char_valid(s[i], S_SEP) == TRUE)
        {
	  if (s[i + 1] == s[i] && (s[i] == C_OR || s[i] == C_AND || s[i] == C_IN
				   || s[i] == C_OUT))
	    token_and_or(s[i], tab, x++);
	  else
	    tab[x++] = ref[(int)(s[i])];
	  i = set_token_if(s, i, tab_);
        }
      skip_char(s, S_SPACE, &i);
    }
  tab[x] = 0;
}
