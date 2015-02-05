/*
** getnextline.c for get_next_line in /home/rossi_t//random/projets/getnextline
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Mon Nov 14 16:19:21 2011 tom rossi
** Last update Sat May 19 11:01:31 2012 tom rossi
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <get_next_line.h>
#include <str.h>

char	*nreturn(char *str)
{
  free(str);
  return (NULL);
}

char	*push(char *str, char *str_out)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] && str[i] != '\n')
    i++;
  while (str[i] == '\n')
    i++;
  while (str[i])
    str[a++] = str[i++];
  str[a] = '\0';
  return (str_out);
}

char		*init(char *buf, int *a)
{
  int   i;
  char  *str_out;

  i = 0;
  str_out = malloc(my_strlen(buf) + 1);
  if (!str_out)
    return (NULL);
  str_out[0] = '\0';
  while (buf[(*a)] && buf[(*a)] != '\n')
    str_out[i++] = buf[(*a)++];
  str_out[i] = '\0';
  return (str_out);
}

char		*copy(char *buf, char *str, int *a)
{
  int	i;
  char	*str_out;

  i = 0;
  if (!(str_out = malloc(my_strlen(buf) + my_strlen(str) + 1)))
    return (NULL);
  while (str[i])
    {
      str_out[i] = str[i];
      i++;
    }
  while (buf[(*a)] && buf[(*a)] != '\n')
    str_out[i++] = buf[(*a)++];
  str_out[i] = '\0';
  free(str);
  return (str_out);
}

char            *get_next_line(const int fd)
{
  char		*str_out;
  static char	buf[G_READ + 1];
  int		size;
  int		a;

  a = 0;
  if (!(str_out = init(buf, &a)))
    return (NULL);
  if (buf[a] == '\n')
    return (push(buf, str_out));
  while ((size = read(fd, buf, G_READ)) > 0 && my_strlen(str_out) < 100000)
    {
      a = 0;
      buf[size] = '\0';
      if (!(str_out = copy(buf, str_out, &a)))
	return (NULL);
      if (buf[a] == '\n')
	return (push(buf, str_out));
    }
  if (size < 0)
    return (str_out);
  buf[size] = '\0';
  if (!size && !str_out[0])
    return (nreturn(str_out));
  return (str_out);
}
