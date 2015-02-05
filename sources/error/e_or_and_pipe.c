/*
** e_or_and_pipe.c for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Thu Apr 12 19:57:52 2012 yoann bourgault
** Last update Fri May 18 11:01:30 2012 yoann bourgault
*/

#include	<token.h>
#include	<errors.h>

int		e_or_and_pipe(int *tkz, int pos)
{
  if (pos && (tkz[pos - 1] == T_CMD || tkz[pos - 1] == T_ARG
	      || tkz[pos - 1] == T_BIN || tkz[pos - 1] == T_BUILT
	      || tkz[pos - 1] == T_BRACKET_O || tkz[pos - 1] == T_BRACKET_C
	      || tkz[pos - 1] == T_RED || tkz[pos - 1] == T_RED_IN_S)
      && (tkz[pos + 1] == T_CMD || tkz[pos + 1] == T_ARG
	  || tkz[pos + 1] == T_BIN || tkz[pos + 1] == T_BUILT
	  || tkz[pos + 1] == T_BRACKET_O || tkz[pos + 1] == T_BRACKET_C
	  || tkz[pos + 1] == T_IN_S || tkz[pos + 1] == T_IN_D
	  || tkz[pos + 1] == T_OUT_S || tkz[pos + 1] == T_OUT_D))
    return (RETURN_SUCCESS);
  else
    pstr(E_INV, 2);
  return (RETURN_ERROR);
}
