/*
** red_access.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Tue Apr 10 15:26:49 2012 tom rossi
** Last update Sat May 19 12:04:10 2012 tom rossi
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <tree.h>
#include <token.h>
#include <red.h>

int     red_access(char *path, int type)
{
  struct stat   buf;

  if (!path)
    return (RETURN_ERROR);
  if (access(path, F_OK) && type == INPUT)
    printf("%s: No such file or directory.\n", path);
  else if (access(path, R_OK) && type == INPUT)
    printf("%s: Permisson denied.\n", path);
  else if (access(path, W_OK) && type == OUTPUT && !access(path, F_OK))
    printf("%s: Permisson denied.\n", path);
  else
    {
      if ((stat(path, &buf) < 0) || (S_ISREG(buf.st_mode) && type == INPUT))
	{
          printf("%s: Not a regular file.\n", path);
          return (RETURN_ERROR);
	}
      return (RETURN_SUCCESS);
    }
  return (RETURN_SUCCESS);
}
