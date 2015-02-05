/*
** strings.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Sat Dec 17 22:47:08 2011 tom rossi
** Last update Fri May 18 14:39:22 2012 tom rossi
*/

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    my_putchar(str[i++]);
  return (1);
}

void    my_putfd(char *str, int fd)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 0)
        write(fd, &(str[i]), 1);
      i++;
    }
}
