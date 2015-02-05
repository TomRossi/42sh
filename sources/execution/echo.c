/*
** echo.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sat May 19 13:12:47 2012 tom rossi
** Last update Sat May 19 13:38:16 2012 tom rossi
*/

#include <unistd.h>
#include <stdlib.h>
#include <str.h>
#include <builtin.h>

int	echo_option(char *s)
{
  if (!my_strcmp(s, S_ON))
    return (O_ON);
  else if (!my_strcmp(s, S_OFF))
    return (O_OFF);
  else if (!my_strcmp(s, S_N))
    return (O_N);
  return (-1);
}

void	init_echo(int *value, char *data)
{
  int	i;

  i = 0;
  while (i <= 2)
    value[i++] = 0;
  data['r'] = '\r';
  data['b'] = '\b';
  data['a'] = '\a';
  data['t'] = '\t';
  data['n'] = '\n';
  data['v'] = '\v';
  data['f'] = '\f';
  data['r'] = '\r';
  data['0'] = '\0';
}

int	valid_echo(char c)
{
  if (c == 'r' || c == 'b' || c == 'a')
    return (1);
  if (c == 't' || c == 'n' || c == 'v')
    return (1);
  if (c == 'f' || c == 'r' || c == '0')
    return (1);
  return (0);
}

void	my_putecho(char *s, int fd, char *data)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '\\' && valid_echo(s[i + 1]))
	write(fd, &(data[(int)(s[(i++) + 1])]), 1);
      else
	write(fd, &(s[i]), 1);
      i++;
    }
}

int     echo(char **tab, int fd)
{
  int   i;
  int	x;
  char	data[115];
  int	value[3];

  i = 1;
  init_echo(value, data);
  while (tab[i] && (x = echo_option(tab[i])) >= 0)
    {
      value[x] = 1;
      i++;
    }
  while (tab[i])
    {
      if (!value[O_ON])
	my_putfd(tab[i], fd);
      else
	my_putecho(tab[i], fd, data);
      i++;
      if (tab[i])
	my_putfd(" ", fd);
    }
  if (!value[O_N])
    my_putfd("\n", fd);
  return (EXIT_SUCCESS);
}
