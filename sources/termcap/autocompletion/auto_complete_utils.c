/*
** auto_complete_utils.c for 42 in /home/quemen_g//42SH_BCKP/VF
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Thu May 17 13:07:45 2012 guillaume quemener
** Last update Fri May 18 17:11:27 2012 guillaume quemener
*/

#include	<unistd.h>
#include	<auto_complete_lib.h>
#include	<auto_glob.h>
#include	<str.h>

int		find_longest_word(char **str, int nb)
{
  int		i;
  int		len;

  len = my_strlen(str[0]);
  i = 1;
  while (str[i + 1] != '\0' && i + 1 < nb)
    {
      if (len <= my_strlen(str[i + 1]))
	len = my_strlen(str[i]);
      i++;
    }
  return (len);
}

int		find_char(char c, char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}
int		count_char(char c, char *str)
{
  int		i;
  int		count;

  count = 0;
  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	count++;
      i++;
    }
  return (count);
}

void    free_list_auto_bin(t_list *list)
{
  if (list != NULL)
    {
      if (list->next != NULL)
	free_list_auto_bin(list->next);
      if (list->file != NULL)
	free(list->file);
      if (list != NULL)
	free(list);
    }
}

char		*epur_spaces(char *str)
{
  int		a;
  int		i;
  char		*buf;

  i = my_strlen(str);
  a = 0;
  if (str == NULL)
    return (NULL);
  buf = malloc(sizeof(*buf) * my_strlen(str) + 1);
  if (buf == NULL)
    return (NULL);
  while (str[i] != ' ')
    i--;
  while (str[i++])
    {
      buf[a] = str[i];
      a++;
    }
  buf[a] = '\0';
  return (buf);
}
