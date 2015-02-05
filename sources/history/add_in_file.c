/*
** add_in_file.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/history
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May 16 13:23:22 2012 maxime lespagnol
** Last update Wed May 16 13:33:46 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<str.h>
#include	<env.h>

int	add_in_file(char **hist, t_env **env)
{
  char	*file;
  int	fd;
  int	k;

  if ((file = make_name_file(env)) == NULL)
    return (-1);
  if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
    return (-1);
  k = 0;
  while (hist != NULL && hist[k] != NULL)
    {
      my_putfd(hist[k], fd);
      k++;
      my_putfd("\n", fd);
    }
  return (0);
}
