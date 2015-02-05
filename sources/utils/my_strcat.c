/*
** my_strcat.c for my_strcat in /u/epitech_2016/rossi_t/rendu/piscine/Jour_07
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Tue Oct 11 10:30:41 2011 tom rossi
** Last update Wed Apr  4 11:33:48 2012 tom rossi
*/

#include <stdlib.h>
#include <str.h>

char	*my_strcat(char *path, char *exe)
{
  int i;
  int a;
  char *str_out;

  a = 0;
  i = 0;
  str_out = malloc(my_strlen(path) + my_strlen(exe) + 2);
  if (!str_out)
    return (NULL);
  while (path[a])
    {
      str_out[a] = path[a];
      a++;
    }
  while (exe[i])
    str_out[a++] = exe[i++];
  str_out[a] = '\0';
  return (str_out);
}
