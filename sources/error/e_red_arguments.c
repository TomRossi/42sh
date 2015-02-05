/*
** e_red_arguments.c for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Thu Apr 12 20:11:20 2012 yoann bourgault
** Last update Fri May 18 11:01:35 2012 yoann bourgault
*/

#include	<token.h>
#include	<errors.h>

int		e_red_arguments(int *tkz, int pos)
{
  if (pos && (tkz[pos - 1] == T_IN_S
	      || tkz[pos - 1] == T_IN_D
	      || tkz[pos - 1] == T_OUT_S
	      || tkz[pos - 1] == T_OUT_D
	      || tkz[pos - 1] == T_BRACKET_O
	      || tkz[pos - 1] == T_BRACKET_C))
    return (RETURN_SUCCESS);
  else
    pstr(E_FAT, 2);
  return (RETURN_ERROR);
}
