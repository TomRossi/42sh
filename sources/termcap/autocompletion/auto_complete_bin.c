/*
** auto_complete_bin.c for 42 in /home/quemen_g//42SH_BCKP/VF
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Thu May 17 13:09:41 2012 guillaume quemener
** Last update Fri May 18 18:54:06 2012 guillaume quemener
*/

#include	<auto_complete_lib.h>
#include	<auto_glob.h>
#include	<str.h>
#include	<env.h>
#include	<unistd.h>

void		show_tab_bin(char **t)
{
  int		i;
  int		j;

  i = 0;
  j = 1;
  my_putchar('\n');
  if (t != NULL)
    {
      while (t != NULL && t[i] != NULL)
	{
	  if (j % 9 == 0)
	    my_putchar('\n');
	  my_putstr(t[i]);
	  my_putchar('\t');
	  i++;
	}
    }
}

char 		*display_match_bin(char **t, int i, char *str)
{
  if (t != NULL)
    {
      if (i == 1 && t[0] != NULL)
	{
	  if (my_strlen(str) < my_strlen(t[0]))
	    return (my_strdup(t[0]));
	}
      show_tab_bin(t);
      free_tab(t);
    }
  return (NULL);
}
char		*find_match_bin(t_list *list, char *str)
{
  t_list	*tmp;
  int		i;
  char		**t;

  i = 0;
  if (list == NULL || str == NULL || my_strlen(str) == 1)
    return (NULL);
  tmp = list;
  t = malloc(sizeof(*t) * my_list_size(list) + 1);
  if (t == NULL)
    return (NULL);
  while (tmp != NULL && tmp->file != NULL && tmp->next != NULL
	 && tmp->next->file != NULL)
    {
      if (my_strncmp(tmp->file, str, my_strlen(str/* tmp->file */)) == 0)
  	{
	  t[i] = my_strdup(tmp->file);
	  i++;
  	}
      tmp = tmp->next;
    }
  t[i] = NULL;
  return (display_match_bin(t, i, str));
}

char            *ret_missing_chars_bin(char *str, char *match)
{
  int           i;
  char          *buf;
  int           j;

  if (str == NULL || match == NULL)
    return (NULL);
  j = 0;
  buf = NULL;
  if (match != NULL)
    buf = malloc(sizeof(*buf) * my_strlen(match) + 1);
  if (buf == NULL)
    return (NULL);
  if (str != NULL)
    i = my_strlen(str);
  while (match != NULL && match[i] != '\0')
    {
      buf[j] = match[i];
      j++;
      i++;
    }
  buf[j] = '\0';
  return (buf);
}

char		*auto_complete_bin(char **env, char *str)
{
  char		*match;
  char		**tab_paths;
  int		i;
  char		*path;
  t_list	*list;

  i = 0;
  list = NULL;
  match = NULL;
  tab_paths = my_str_to_wordtab(take_path_from_env(env), ":");
  while (tab_paths[i] != NULL)
    {
      if (tab_paths[i] != NULL)
	path = my_concat_path(tab_paths[i], str);
      if (access(tab_paths[i], F_OK) == 0)
	list = list_files(tab_paths[i], list);
      i++;
    }
  free_tab(tab_paths);
  match = find_match_bin(list, str);
  if (list != NULL)
    free_list_auto_bin(list);
  if (match != NULL)
    return (match);
  return (NULL);
}
