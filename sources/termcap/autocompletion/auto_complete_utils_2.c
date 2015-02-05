/*
** auto_complete_utils_2.c for 42 in /home/quemen_g//42SH_BCKP/V7/sources/termcap/autocompletion
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Fri May 18 16:04:04 2012 guillaume quemener
** Last update Fri May 18 17:46:39 2012 guillaume quemener
*/

#include	<stdio.h>
#include	<dirent.h>
#include	<stdlib.h>
#include        <sys/types.h>
#include	<unistd.h>
#include        <sys/stat.h>
#include	<auto_complete_lib.h>
#include	<auto_glob.h>
#include	<str.h>

char		*remove_star(char *str)
{
  char		*new;
  int		i;

  i = 0;
  new = malloc(sizeof(*new) * my_strlen(str) + 1);
  if (new == NULL)
    return (NULL);
  while (str[i] != '\0' && str[i] != '*')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

int             get_type_of_file(struct stat *sb)
{
  if (sb->st_mode >= 4198320)
    return (1);
  return (-1);
}
char		*add_slash(char *new, char *ret)
{
  int		i;

  i = 0;
  if (new == NULL || ret == NULL)
    return (NULL);
  while (ret[i] != '\0')
    {
      new[i] = ret[i];
      i++;
    }
  new[i] = '/';
  new[i + 1] = '\0';
  return (new);
}

char		*display_slash(char *str, char *ret)
{
  struct dirent	*entry;
  struct        stat sb;
  DIR		*dirp;
  char		*new;
  int		i;

  i = 0;
  new = malloc(sizeof(*new) * my_strlen(ret) + 2);
  if (new == NULL)
    return (NULL);
  if ((dirp = opendir(str)) == NULL)
    return (ret);
  if ((entry = readdir(dirp)) != NULL)
    stat(entry->d_name, &sb);
  if (get_type_of_file(&sb) == 1)
    {
      closedir(dirp);
      return (add_slash(new, ret));
    }
  closedir(dirp);
  return (ret);
}
