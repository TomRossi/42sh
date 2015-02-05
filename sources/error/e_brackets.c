/*
** e_brackets.c for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Tue May  1 15:27:30 2012 yoann bourgault
** Last update Fri May 18 11:01:19 2012 yoann bourgault
*/

#include        <token.h>
#include        <errors.h>

int		e_post_closing_bracket(int *tkz, int i)
{
  while (tkz[i])
    {
      if (tkz[i] == T_BRACKET_C
	  && (tkz[i + 1] == T_ARG || tkz[i + 1] == T_CMD
	      || tkz[i + 1] == T_BIN || tkz[i + 1] == T_RED
	      || tkz[i + 1] == T_BUILT || tkz[i + 1] == T_RED_IN_S))
	{
	  pstr(E_BADLY, 2);
	  return (RETURN_ERROR);
	}
      i++;
    }
  return (RETURN_SUCCESS);
}

int             e_missing_brackets(int *tkz, int i, int op, int cl)
{
  while (tkz[i])
    {
      if (tkz[i] == T_BRACKET_O)
        op++;
      else if (tkz[i] == T_BRACKET_C)
        cl++;
      if (cl == 1 && op == 0)
        {
          pstr(E_BRACKET_C, 2);
          return (RETURN_ERROR);
        }
      i++;
    }
  if (op > cl)
    {
      pstr(E_BRACKET_O, 2);
      return (RETURN_ERROR);
    }
  else if (cl > op)
    {
      pstr(E_BRACKET_C, 2);
      return (RETURN_ERROR);
    }
  else
    return (RETURN_SUCCESS);
}

int             e_badly_or_invalid_brackets(int *tkz, int i, int counter)
{
  while (tkz[i])
    {
      if (!(tkz[i] == T_BRACKET_O || tkz[i] == T_BRACKET_C))
        counter++;
      i++;
    }
  if (!counter)
    {
      pstr(E_INV, 2);
      return (RETURN_ERROR);
    }
  i = 1;
  while (tkz[i])
    {
      if (tkz[i] == T_BRACKET_C && tkz[i - 1] == T_BRACKET_O)
        {
          pstr(E_BADLY, 2);
          return (RETURN_ERROR);
        }
      i++;
    }
  return (RETURN_SUCCESS);
}

int		e_useless_brackets(int *tkz, int i, int counter)
{
  while (tkz[i])
    {
      counter = 0;
      if (tkz[i] == T_BRACKET_C)
	{
	  i++;
	  while (tkz[i] && tkz[i] != T_BRACKET_C)
	    {
	      if (tkz[i] == T_AND || tkz[i] == T_OR
		  || tkz[i] == T_PIPE || tkz[i] == T_SEMICOL)
		counter++;
	      else if (tkz[i] == T_BRACKET_O && !counter)
		{
		  pstr(E_BRACKET_C, 2);
		  return (RETURN_ERROR);
		}
	      i++;
	    }
	}
      else
	i++;
    }
  return (RETURN_SUCCESS);
}

int             e_brackets(int *tkz)
{
  if (e_missing_brackets(tkz, 0, 0, 0) == RETURN_ERROR)
    return (RETURN_ERROR);
  else if (e_badly_or_invalid_brackets(tkz, 0, 0) == RETURN_ERROR)
    return (RETURN_ERROR);
  else if (e_post_closing_bracket(tkz, 0) == RETURN_ERROR)
    return (RETURN_ERROR);
  else if (e_useless_brackets(tkz, 0, 0) == RETURN_ERROR)
    return (RETURN_ERROR);
  else if (e_into_brackets(tkz, 0, 0) == RETURN_ERROR)
    return (RETURN_ERROR);
  else if (e_before_opening_bracket(tkz, 0) == RETURN_ERROR)
    return (RETURN_ERROR);
  return (RETURN_SUCCESS);
}
