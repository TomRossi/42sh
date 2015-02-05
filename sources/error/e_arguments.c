/*
** e_arguments.c for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Thu Apr 12 18:38:37 2012 yoann bourgault
** Last update Fri May 18 11:01:15 2012 yoann bourgault
*/

#include	<errors.h>
#include	<token.h>

int		multiple_arguments(int *tkz, int pos)
{
  while (pos >= 0 && (tkz[pos] == T_ARG
		      || tkz[pos] == T_BRACKET_O
		      || tkz[pos] == T_BRACKET_C))
    pos--;
  if (tkz[pos] == T_CMD
      || tkz[pos] == T_BUILT
      || tkz[pos] == T_BIN)
    return (RETURN_SUCCESS);
  return (RETURN_ERROR);
}

int		e_arguments(int *tkz, int pos)
{
  if (pos && (tkz[pos - 1] == T_CMD || tkz[pos - 1] == T_BUILT
	      || tkz[pos - 1] == T_BIN
	      || tkz[pos - 1] == T_BRACKET_O
	      || tkz[pos - 1] == T_BRACKET_C))
    return (RETURN_SUCCESS);
  else if (pos && (tkz[pos - 1] == T_ARG
		   || tkz[pos - 1] == T_BRACKET_O
		   || tkz[pos - 1] == T_BRACKET_C)
	   && (multiple_arguments(tkz, pos) == RETURN_SUCCESS))
    return (RETURN_SUCCESS);
  else
    pstr(E_FAT, 2);
  return (RETURN_ERROR);
}
