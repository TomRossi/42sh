/*
** bin_cmd_path.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr  4 10:35:07 2012 tom rossi
** Last update Mon May 14 13:22:10 2012 tom rossi
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <token.h>
#include <tree.h>
#include <builtin.h>
#include <str.h>
#include <env.h>

int	is_builtin(char *s)
{
  char	*tab[N_BUILT + 1];
  int	i;

  i = 0;
  tab[0] = B_CD;
  tab[1] = B_ENV;
  tab[2] = B_SENV;
  tab[3] = B_UENV;
  tab[4] = B_ECHO;
  tab[5] = B_EXIT;
  tab[6] = B_ALIAS;
  tab[7] = B_UNALIAS;
  tab[8] = B_HISTORY;
  tab[9] = NULL;
  while (tab[i])
    {
      if (!my_strcmp(tab[i], s))
	return (RETURN_SUCCESS);
      i++;
    }
  return (RETURN_ERROR);
}

int	path_cmd(t_cmd *list, t_env *env)
{
  if (list->type == T_BUILT)
    {
      list->path = my_strdup(list->av[0]);
      return (RETURN_SUCCESS);
    }
  list->type = T_CMD;
  list->path = get_cmd_path(list->av[0], env);
  if (!list->path)
    {
      fprintf(stderr, "%s: Command not found.\n", list->av[0]);
      return (RETURN_ERROR);
    }
  return (RETURN_SUCCESS);
}

int	path_bin(t_cmd *list, t_env *env)
{
  if (access(list->av[0], F_OK))
    fprintf(stderr, "%s: No such file or directory.\n", list->av[0]);
  else if (access(list->av[0], X_OK))
    fprintf(stderr, "%s: Permission denied.\n", list->av[0]);
  else
    {
      list->type = T_BIN;
      list->path = my_strdup(list->av[0]);
      return (RETURN_SUCCESS);
    }
  return (RETURN_ERROR);
}

int	get_path(t_cmd *tmp, t_env *env)
{
  int		ret;
  int		(*func[T_RED + 1])();

  func[T_CMD] = path_cmd;
  func[T_BIN] = path_bin;
  ret = RETURN_SUCCESS;
  if (tmp && tmp->type == T_CMD && ((tmp->av[0][0] == '.'
				     && tmp->av[0][1] == '/')|| tmp->av[0][0] == '/'))
    tmp->type = T_BIN;
  if (tmp && (tmp->type == T_CMD || tmp->type == T_BIN))
    ret = func[tmp->type](tmp, env);
  if (ret != RETURN_SUCCESS)
    return (RETURN_ERROR);
  return (RETURN_SUCCESS);
}

int	bin_cmd(t_cmd *list, t_env *env)
{
  int	ret;

  if (list->av && list->av[0])
    ret = get_path(list, env);
  return (ret);
}
