/*
** e_brackets_others.c for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Thu May  3 00:37:29 2012 yoann bourgault
** Last update Fri May 18 11:01:25 2012 yoann bourgault
*/

#include        <token.h>
#include        <errors.h>

int             e_into_brackets(int *tkz, int i, int counter)
{
  while (tkz[i])
    {
      if (tkz[i] == T_BRACKET_O)
        {
          i++;
          while (tkz[i] && tkz[i] != T_BRACKET_O)
            {
              if (tkz[i] == T_CMD || tkz[i] == T_BUILT || tkz[i] == T_BIN)
                counter++;
              i++;
            }
          if (!counter)
            {
              pstr(E_BADLY, 2);
              return (RETURN_ERROR);
            }
        }
      else
	i++;
    }
  return (RETURN_SUCCESS);
}

int             e_before_opening_bracket(int *tkz, int i)
{
  while (tkz[i])
    {
      if (i && tkz[i] == T_BRACKET_O
          && !(tkz[i - 1] == T_AND || tkz[i - 1] == T_OR
                 || tkz[i - 1] == T_BRACKET_O || tkz[i - 1] == T_PIPE
	       || tkz[i - 1] == T_SEMICOL))
        {
          pstr(E_BADLY, 2);
          return (RETURN_ERROR);
        }
      i++;
    }
  return (RETURN_SUCCESS);
}
