/*
** recup_hist_tab.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/history
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May 16 10:52:18 2012 maxime lespagnol
** Last update Wed May 16 13:35:15 2012 maxime lespagnol
*/

#include        <stdlib.h>
#include        <str.h>
#include	<hist.h>
#include        <env.h>

char    *add_all_str_file(char *home, char *user, char *name, int size)
{
  char  *ret;
  int   k;
  int   i;

  if ((ret = malloc(sizeof(*ret) * (size))) == NULL)
    return (NULL);
  k = 0;
  i = 0;
  while (home != NULL && home[i] != '\0')
    ret[k++] = home[i++];
  i = 0;
  while (user != NULL && user[i] != '\0')
    ret[k++] = user[i++];
  i = 0;
  while (name != NULL && name[i] != '\0')
    ret[k++] = name[i++];
  ret[k] = '\0';
  return (ret);
}

char    *add_str_file(char *username)
{
  char  *ret;
  char  *home;
  char  *name;
  int   size;

  home = my_strdup("/home/");
  name = my_strdup("/.fgosh_history");
  size = my_strlen(home) + my_strlen(name) + my_strlen(username) + 1;
  ret = add_all_str_file(home, username, name, size);
  xfree(home);
  xfree(name);
  return (ret);
}

char    *make_name_file(t_env **env)
{
  t_env *ptr;
  char  *ret;

  ptr = *env;
  ret = NULL;
  while (ptr != NULL && my_strcmp(ptr->name, "USER") != 0)
    ptr = ptr->next;
  if (ptr != NULL && my_strcmp(ptr->name, "USER") == 0)
    ret = add_str_file(ptr->value);
  return (ret);
}

char    **recup_hist_tab(t_env **env)
{
  char  **ret;
  char  *file;

  if ((file = make_name_file(env)) == NULL)
    return (NULL);
  ret = recup_file(file);
  return (ret);
}
