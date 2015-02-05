/*
** token_substitute.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Mon Apr 30 18:25:51 2012 tom rossi
** Last update Thu May 17 12:56:28 2012 tom rossi
*/

#include <env.h>
#include <token.h>

char     *list_sub(char	*s, t_env *env)
{
  int   i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '$' && (!i || s[i - 1] == ' ' || s[i - 1] == '\t'))
	{
          s = var_sub(env, s, &i);
	  i = 0;
	}
      i += 1;
    }
  return (s);
}

char             **token_envsub(char **av, t_env *env, int *type)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (type[i] == M_NORMAL || type[i] == M_DOUBLE)
        av[i] = list_sub(av[i], env);
      i++;
    }
  return (av);
}
