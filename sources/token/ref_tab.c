/*
** ref_tab.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Thu Mar 29 17:58:06 2012 tom rossi
** Last update Wed Apr 18 15:51:04 2012 tom rossi
*/

#include <token.h>

void    ref_tab(int *ref)
{
  ref[C_PIPE] = T_PIPE;
  ref[C_IN] = T_IN_S;
  ref[C_OUT] = T_OUT_S;
  ref[C_AND] = T_AND;
  ref[C_SIMPLE] = T_ALPHA;
  ref[C_DOUBLE] = T_ALPHA;
  ref[C_BRACKET_O] = T_BRACKET_O;
  ref[C_BRACKET_C] = T_BRACKET_C;
  ref[C_SEMICOL] = T_SEMICOL;
}
