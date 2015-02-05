/*
** prompt.c for sh in /home/rossi_t//random/projets/42sh/svn/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed May  2 14:33:09 2012 tom rossi
** Last update Wed May  9 16:43:08 2012 tom rossi
*/

#include <stdlib.h>
#include <env.h>
#include <token.h>
#include <str.h>

char    *recup_prompt(t_env *env)
{
  t_env *ptr;
  char  *prompt;
  char	*tmp;
  ptr = env;
  prompt = NULL;
  if (ptr != NULL)
    {
      while (ptr != NULL && my_strcmp(ptr->name, "USERNAME") != 0)
        ptr = ptr->next;
      if (ptr != NULL)
        prompt = my_strdup(ptr->value);
    }
  if (prompt == NULL)
    tmp = my_strdup("$");
  if (prompt != NULL)
    tmp = my_strcat(prompt, "> ");
  if (prompt)
    free(prompt);
  return (tmp);
}

void    aff_prompt(char *prompt)
{
  my_putstr("\r");
  if (prompt)
    my_putstr(prompt);
  else
    my_putstr("$>");
}

void	no_term(t_env *env, int *tty)
{
  t_env	*tmp;

  tmp = env;
  while (tmp && my_strcmp(tmp->name, "TERM"))
    tmp = tmp->next;
  if (!tmp)
    *tty = 0;
}
