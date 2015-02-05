/*
** error_management.c for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Tue Apr 10 10:29:58 2012 yoann bourgault
** Last update Fri May 18 11:01:45 2012 yoann bourgault
*/

#include	<token.h>
#include	<errors.h>

int		error_management(int *tkz, int i)
{
  if (e_brackets(tkz) == RETURN_ERROR)
    return (RETURN_ERROR);
  while (tkz[i])
    {
      if ((tkz[i] == T_IN_S || tkz[i] == T_IN_D
      		|| tkz[i] == T_OUT_S || tkz[i] == T_OUT_D)
      	       && (e_redirects(tkz, i, 0) == RETURN_ERROR))
      	return (RETURN_ERROR);
      else if (tkz[i] == T_ARG && (e_arguments(tkz, i) == RETURN_ERROR))
      	return (RETURN_ERROR);
      else if ((tkz[i] == T_AND || tkz[i] == T_OR || tkz[i] == T_PIPE)
      	       && (e_or_and_pipe(tkz, i) == RETURN_ERROR))
      	return (RETURN_ERROR);
      else if ((tkz[i] == T_RED || tkz[i] == T_RED_IN_S)
      	       && (e_red_arguments(tkz, i) == RETURN_ERROR))
      	return (RETURN_ERROR);
      i++;
    }
  return (RETURN_SUCCESS);
}
