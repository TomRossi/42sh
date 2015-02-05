/*
** token_utils.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed May  2 16:22:09 2012 tom rossi
** Last update Wed May  2 16:22:21 2012 tom rossi
*/

#include <str.h>
#include <token.h>

void    set_mode(char **tab)
{
  tab[M_NORMAL] = S_SEP_ALL;
  tab[M_DOUBLE] = S_DOUBLE;
  tab[M_SIMPLE] = S_SIMPLE;
}

void    token_and_or(char c, int *tab, int x)
{
  if (c == C_OR)
    tab[x] = T_OR;
  else if (c == C_AND)
    tab[x] = T_AND;
  else if (c == C_IN)
    tab[x] = T_IN_D;
  else if (c == C_OUT)
    tab[x] = T_OUT_D;
}

void    token_bin(char c, int *tab, int x)
{
  tab[x] = T_ALPHA;
}

void    token_init_val(char **tab_, int *x, int *i)
{
  tab_[C_SIMPLE] = S_SIMPLE;
  tab_[C_DOUBLE] = S_DOUBLE;
  *x = 0;
  *i = 0;
}
