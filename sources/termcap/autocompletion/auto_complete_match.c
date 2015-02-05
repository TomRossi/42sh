/*
** auto_complete_match.c for 42 in /home/quemen_g//42SH_BCKP/VF
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Thu May 17 13:33:03 2012 guillaume quemener
** Last update Thu May 17 13:33:33 2012 guillaume quemener
*/

#include	<auto_complete_lib.h>
#include	<auto_glob.h>
#include	<str.h>
#include	<unistd.h>

char		*func_match(char **str, int nb, int len)
{
  char		*buf;
  int		i;
  int		j;
  int		flag;

  flag = 0;
  j = 0;
  i = 0;
  buf = malloc(sizeof(*buf) * (len + 1));
  if (buf == NULL)
    return (NULL);
  while (str[i + 1] != '\0' || i + 1 != nb)
    {
      if (str[i][j] == str[i + 1][j])
	flag++;
      if (flag == nb)
	{
	  my_putchar(str[i][j]);
	  flag = 0;
	  j++;
	}
      i++;
    }
  return (NULL);
}

char		*auto_complete_epur(char *str)
{
  int		i;
  char		*ret;

  if (str == NULL)
    {
      ret = my_strdup("*");
      return (ret);
    }
  i = 0;
  ret = malloc(sizeof(*ret) * my_strlen(str) + 3);
  if (ret == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '*';
  ret[i + 1] = '\0';
  return (ret);
}
char		*ret_missing_chars(char *str, char *match)
{
  int		i;
  char		*buf;
  int		j;

  if (str == NULL || match == NULL)
    return (NULL);
  j = 0;
  buf = malloc(sizeof(*buf) * my_strlen(match));
  if (buf == NULL)
    return (NULL);
  i = my_strlen(str) - 1;
  while (match[i] != '\0')
    {
      buf[j] = match[i];
      j++;
      i++;
    }
  buf[j] = '\0';
  return (buf);
}

char		*take_path_from_env(char **env)
{
  int		i;
  char		*path;
  int		j;
  int		k;

  k = 0;
  j = 5;
  i = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	{
	  path = malloc(sizeof(*path) * my_strlen(env[i]));
	  if (path == NULL)
	    return (NULL);
	  while (env[i][j] != '\0')
	    path[k++] = env[i][j++];
	  path[k] = '\0';
	  return (path);
	}
      i++;
    }
  return (NULL);
}

char		*my_concat_path(char *str, char *str2)
{
  int		i;
  int		j;
  char		*ret;

  i = 0;
  j = 0;
  ret = malloc(sizeof(*ret) * (my_strlen(str) + my_strlen(str2)) + 2);
  if (ret == NULL)
    return (NULL);
  while (str[i])
    ret[j++] = str[i++];
  i = 0;
  ret[j++] = '/';
  while (str2[i])
    {
      ret[j] = str2[i];
      j++;
      i++;
    }
  ret[j] = '\0';
  return (ret);
}
