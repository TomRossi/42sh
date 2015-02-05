/*
** main.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Mar 28 12:34:44 2012 tom rossi
** Last update Sat May 19 11:21:29 2012 tom rossi
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <sys/ioctl.h>
#include <str.h>
#include <hist.h>
#include <alias.h>
#include <env.h>
#include <token.h>
#include <errors.h>
#include <get_next_line.h>
#include <tree.h>
#include <term_man.h>

char    *new_hist(t_env **env, t_hist **ptr, char *prompt, t_sh *sh);

void	var_init(t_sh *sh, int *value, int *flag)
{
  value[V_TTY] = isatty(0);
  value[V_TERM] = 1;
  sh->ptr = NULL;
  sh->env = NULL;
  *flag = NO_EXIT;
  sh->alias = NULL;
}

int	free_them_all(t_sh *sh, int *value, int ret)
{
  add_in_file(sh->hist, &(sh->env));
  free_env(sh->env);
  if (value[V_TTY] && value[V_TERM])
    free(sh->prompt);
  free_hist(sh->ptr);
  xfree_tab(sh->hist);
  free_alias(sh->alias);
  return (ret);
}

void	signal_handler()
{
  signal(SIGTTOU, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
}

int	tcpgrp_reset()
{
  tcsetpgrp(0, getpgrp());
  tcsetpgrp(1, getpgrp());
  return (1);
}

int	main(int ac, char **av, char **envp)
{
  t_sh		sh;
  char		*str;
  int		flag;
  int		value[2];

  signal_handler();
  var_init(&sh, value, &flag);
  recup_env(&(sh.env), envp);
  if (value[V_TTY])
    sh.prompt = recup_prompt(sh.env);
  sh.hist = recup_hist_tab(&(sh.env));
  while (flag == NO_EXIT && tcpgrp_reset())
    {
      no_term(sh.env, &(value[V_TERM]));
      if (value[V_TTY])
	aff_prompt(sh.prompt);
      if (value[V_TTY] && value[V_TERM])
	str = new_hist(&(sh.env), &(sh.ptr), sh.prompt, &sh);
      else
	str = get_next_line(0);
      if (!str || (sh.ptr != NULL && sh.ptr->flag == MY_QUIT))
	flag = EXIT_SUCCESS;
      if (str != NULL && str[0] != '\0' && quotes(str) == RETURN_SUCCESS)
	flag = str_action(str, &sh);
    }
  return (free_them_all(&sh, value, flag));
}
