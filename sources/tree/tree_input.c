/*
** tree_input.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sat May 19 11:13:41 2012 tom rossi
** Last update Sat May 19 11:16:16 2012 tom rossi
*/

#include <unistd.h>
#include <stdlib.h>
#include <token.h>
#include <str.h>

char	*double_end(char *out)
{
  my_putchar('\n');
  if (!out[0])
    return (my_strdup(out));
  out[my_strlen(out)] = '\0';
  return (out);
}

char    *double_red(char *stop)
{
  char  *out;
  char  buf[100];
  int   size;

  out = "";
  buf[0] = -1;
  buf[1] = '\0';
  while (my_strcmp(buf, stop))
    {
      if (buf[0] < 0)
        buf[0] = 0;
      my_putchar('?');
      size = read(0, buf, 99);
      if (!size)
	return (double_end(out));
      if (size < 0)
        return (0);
      buf[size] = '\0';
      out = (my_strcat(out, buf));
      buf[size - 1] = '\0';
    }
  out[my_strlen(out) - size] = '\0';
  return (out);
}
