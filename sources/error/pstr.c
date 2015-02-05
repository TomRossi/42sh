/*
** pstr.c for 42sh in /home/bourga_y//42sh-rennes/new/sources/error
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Fri May 18 10:58:10 2012 yoann bourgault
** Last update Fri May 18 10:59:28 2012 yoann bourgault
*/

#include	<unistd.h>

void		pchar(char c, int fd)
{
  write(fd, &c, 1);
}

void		pstr(char *s, int fd)
{
  int		i;

  i = 0;
  while (s[i])
    pchar(s[i++], fd);
}
