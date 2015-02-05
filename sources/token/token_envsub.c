/*
** token_envsub.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sun Apr 29 11:15:32 2012 tom rossi
** Last update Thu May 17 13:28:54 2012 tom rossi
*/

#include <stdlib.h>
#include <str.h>
#include <env.h>
#include <tree.h>
#include <token.h>

void	sub_end(char *s, char *out, int i, int *x)
{
  while (s[i] && s[i] != ' ' && s[i] != '\t')
    i++;
  if (!s[i])
    return;
  while (s[i])
    out[(*x)++] = s[i++];
}

char	*str_sub(char *s, int *i, char *data)
{
  char	*out;
  int	x;
  int	a;

  a = 0;
  x = 0;
  out = malloc(sizeof(*out) * (my_strlen(s) + my_strlen(data)));
  if (!out)
    return (NULL);
  while (x < *i)
    {
      out[x] = s[x];
      x++;
    }
  while (data[a])
    out[x++] = data[a++];
  sub_end(s, out, *i, &x);
  *i = my_strlen(data);
  out[x] ='\0';
  return (out);
}

int	my_envcmp(t_env *tmp, char *s, int i)
{
  int	x;
  char	*name;

  x = 0;
  i++;
  name = tmp->name;
  while (name[x] && s[i])
    {
      if (name[x] != s[i])
	return (1);
      x++;
      i++;
    }
  if (name[x])
    return (1);
  if (!s[i] || s[i] == ' ' || s[i] == '\t')
    return (0);
  return (1);
}

char	*var_sub(t_env *env, char *s, int *i)
{
  char	*out;
  t_env	*tmp;

  tmp = env;
  while (tmp && my_envcmp(tmp, s, *i))
    tmp = tmp->next;
  if (!tmp)
    return (s);
  if (!(out = str_sub(s, i, tmp->value)))
    return (s);
  free(s);
  return (out);
}
