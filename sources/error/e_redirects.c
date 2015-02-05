/*
** e_redirects.c for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Thu Apr 12 16:42:31 2012 yoann bourgault
** Last update Sat May 19 11:11:58 2012 tom rossi
*/

#include	<token.h>
#include	<errors.h>

int		ambigious_redirection(int *tkz, int i, int in, int out)
{
  while (i > -1 && tkz[i] != T_SEMICOL && tkz[i] != T_OR && tkz[i] != T_AND)
    {
      if (tkz[i] == T_BRACKET_C)
	while (tkz[i] != T_BRACKET_O)
	  i--;
      if (tkz[i] == T_IN_S || tkz[i] == T_IN_D)
	in++;
      else if (tkz[i] == T_OUT_S || tkz[i] == T_OUT_D)
        out++;
      i--;
    }
  if (in > 1 || out > 1)
    {
      pstr(E_AMB, 2);
      return (RETURN_ERROR);
    }
  return (RETURN_SUCCESS);
}

int		double_redirection_check(int *tkz, int pos)
{
  if (ambigious_redirection(tkz, pos + 1, 0, 0) == RETURN_ERROR)
    return (-2);
  if (pos >= 2 && (tkz[pos - 1] == T_IN_S || tkz[pos - 1] == T_IN_D
			|| tkz[pos - 1] == T_OUT_S || tkz[pos - 1] == T_OUT_D)
      && (tkz[pos - 2] == T_BRACKET_C || tkz[pos - 2] == T_ARG
          || tkz[pos - 2] == T_CMD || tkz[pos - 2] == T_BUILT
          || tkz[pos - 2] == T_BIN))
    return (RETURN_SUCCESS);
  else if (tkz[pos] == T_BRACKET_C)
    return (RETURN_SUCCESS);
  return (RETURN_ERROR);
}

int		double_redirection(int *tkz, int pos)
{
  int		ref;

  if (tkz[pos + 1] == T_RED || tkz[pos + 1] == T_RED_IN_S)
    {
      pos--;
      ref = double_redirection_check(tkz, pos);
      if (ref == -2)
	return (-2);
      else if (ref == RETURN_SUCCESS)
	return (RETURN_SUCCESS);
    }
  return (RETURN_ERROR);
}

int		e_redirects(int *tkz, int pos, int ref)
{
  if (!pos && (tkz[1] == T_RED || tkz[1] == T_RED_IN_S)
      && (tkz[2] == T_CMD || tkz[2] == T_BUILT || tkz[2] == T_BIN
	  || tkz[2] == T_BRACKET_O))
    return (RETURN_SUCCESS);
  else if (pos && (tkz[pos - 1] == T_CMD || tkz[pos - 1] == T_BUILT
		   || tkz[pos - 1] == T_BIN || tkz[pos - 1] == T_ARG)
	   && (tkz[pos + 1] == T_RED || tkz[pos + 1] == T_RED_IN_S))
    return (RETURN_SUCCESS);
  else if ((tkz[pos + 1] == T_RED || tkz[pos + 1] == T_RED_IN_S)
	   && tkz[pos + 1] != T_END
	   && (tkz[pos + 2] == T_CMD || tkz[pos + 2] == T_BUILT
	       || tkz[pos + 2] == T_BIN	|| tkz[pos + 2] == T_BRACKET_O))
    return (RETURN_SUCCESS);
  if (pos && (tkz[pos - 1] == T_RED || tkz[pos - 1] == T_RED_IN_S
		   || tkz[pos - 1] == T_BRACKET_C))
    {
      ref = double_redirection(tkz, pos);
      if (ref == RETURN_SUCCESS)
	return (RETURN_SUCCESS);
      else if (ref == RETURN_ERROR)
	pstr(E_RED, 2);
    }
  else
    pstr(E_RED, 2);
  return (RETURN_ERROR);
}
