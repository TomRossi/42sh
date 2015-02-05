/*
** recup_env.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/Termcaps/env
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Tue Mar 27 15:12:07 2012 maxime lespagnol
** Last update Sat May 19 11:05:42 2012 tom rossi
*/

#include <stdio.h>
#include <stdlib.h>
#include <env.h>

char	*parsing_name(char *str)
{
  char	*out;
  int	k;

  out = NULL;
  k = 0;
  while (str[k] && str[k] != '=')
    k++;
  if ((out = malloc(sizeof(*out) * (k + 1))) == NULL)
    return (NULL);
  k = 0;
  while (str[k] != '\0' && str[k] != '=')
    {
      out[k] = str[k];
      k++;
    }
  out[k] = '\0';
  return (out);
}

char	*parsing_value(char *str)
{
  char	*out;
  int	k;
  int	i;

  out = NULL;
  k = 0;
  i = 0;
  while (str[i] != '\0' && str[i] != '=')
    i++;
  if (str[i])
    i++;
  if (str[i] == '\0')
    return (NULL);
  k = i;
  while (str[i])
    i++;
  if ((out = malloc(sizeof(*out) * (i - k + 1))) == NULL)
    return (NULL);
  i = k;
  k = 0;
  while (str[i] != '\0')
    out[k++] = str[i++];
  out[k] = '\0';
  return (out);
}

void	kill_env(t_env **env)
{
  *env = NULL;
  printf("Warning: Not able to initiate the environnement.\n");
  return;
}

void	recup_env(t_env **env, char **env_tmp)
{
  int	i;
  t_env	*new;

  i = 0;
  if (!env_tmp || !env_tmp[0])
    return;
  if ((new = malloc(sizeof(*new))) == NULL)
    return;
  *env = new;
  while (env_tmp[i] != NULL)
    {
      if (!(new->name = parsing_name(env_tmp[i])))
	return (kill_env(env));
      if (!(new->value = parsing_value(env_tmp[i])))
	return (kill_env(env));
      if (env_tmp[i + 1] != NULL)
	{
	  if ((new->next = malloc(sizeof(*new->next))) == NULL)
	    return;
	  new = new->next;
	}
      i++;
    }
  new->next = NULL;
}
