/*
** determ_flag.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Tue May  1 03:37:38 2012 maxime lespagnol
** Last update Thu May 10 18:18:50 2012 maxime lespagnol
*/

#include	<stdio.h>
#include	<term_man.h>

int	special_flag(char *buff)
{
  if (buff[0] == 27 && buff[1] == 91)
    {
      if (buff[2] == 65)
	return (UP);
      else if (buff[2] == 66)
	return (DOWN);
      else if (buff[2] == 68)
	return (LEFT_T);
      else if (buff[2] == 67)
	return (RIGHT_T);
      else if (buff[2] == 51)
	return (DELETE);
      else if (buff[2] == 72)
	return (BEGIN);
      else if (buff[2] == 70)
	return (END);
      else if (buff[2] == 49 && buff[3] == 59 && buff[4] == 53)
	{
	  if (buff[5] == 68 && buff[6] == '\0')
	return (CTRL_LEFT);
	  else if (buff[5] == 67 && buff[6] == '\0')
	    return (CTRL_RIGHT);
	}
    }
  return (NOTH);
}

int	return_again_flag(char *buff)
{
  if (buff[0] == 23 && buff[1] == '\0')
    return (COPY_W);
  else if (buff[0] == 27 && buff[1] == 127 && buff[2] == '\0')
    return (COPY_W);
  else if (buff[0] == 21 && buff[1] == '\0')
    return (COPY_W);
  else if (buff[0] == 15 && buff[1] == '\0')
    return (DONT);
  else if (buff[0] == 16 && buff[1] == '\0')
    return (UP);
  else if (buff[0] == 8 && buff[1] == '\0')
    return (BACKSPACE);
  else if (buff[0] == 27 && buff[1] == 79 && buff[2] == 72)
    return (BEGIN);
  else if (buff[0] == 27 && buff[1] == 79 && buff[2] == 70)
    return (END);
  else
    return (special_flag(buff));
}

int	determ_oth_flag(char *buff)
{
  if (buff[0] == 1 && buff[1] == '\0')
    return (BEGIN);
  else if (buff[0] == 11 && buff[1] == '\0')
    return (COPY);
  else if (buff[0] == 25 && buff[1] == '\0')
    return (PASTE);
  else
    return (return_again_flag(buff));
}

int	determ_flag(char *buff)
{
  if (buff[0] == 4 && buff[1] == '\0')
    return (MY_QUIT);
  else if (buff[0] == 127 && buff[1] == '\0')
    return (BACKSPACE);
  else if (buff[0] == 5 && buff[1] == '\0')
    return (END);
  else if (buff[0] == 27 && buff[1] == 97 && buff[2] == '\0')
    return (ALT_A);
  else if (buff[0] == 10 && buff[1] == '\0')
    return (ENTER);
  else if (buff[0] == 12 && buff[1] == '\0')
    return (CLEAR);
  else if (buff[0] == 9 && buff[1] == '\0')
    return (TAB);
  else
    return (determ_oth_flag(buff));
  return (NOTH);
}
