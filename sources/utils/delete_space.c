/*
** delete_space.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Thu Mar 29 15:51:26 2012 tom rossi
** Last update Thu Mar 29 15:51:37 2012 tom rossi
*/

#include <token.h>

void    delete_space(char *s)
{
  int   i;

  i = 0;
  while (s[i])
    i++;
  if (i)
    i--;
  while (i >= 0 && is_char_valid(s[i], S_SPACE))
    s[i--] = '\0';
}
