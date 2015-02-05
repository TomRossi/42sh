/*
** env.h for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/Termcaps/includes
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Tue Mar 27 15:05:09 2012 maxime lespagnol
** Last update Fri May 18 17:21:24 2012 tom rossi
*/

#ifndef		__ENV_H__
#define		__ENV_H__

#include <list_alias.h>
#include <hist.h>

#define	NO_EXIT	2
#define BYE	3
#define V_TERM	0
#define V_TTY	1

typedef	struct	s_env
{
  char		*name;
  char		*value;
  struct s_env	*next;
}t_env;

typedef struct s_sh
{
  char		*prompt;
  char		**hist;
  struct s_env	*env;
  struct s_alias *alias;
  struct s_hist	*ptr;
}t_sh;

int     aff_history(char **opt, int fd, t_sh *sh);
int     term_mod(t_env **env);
int     normal_mod(t_env **env);
int     add_in_file(char **hist, t_env **env);
char    *definepwd(char *str, char *pwd);
char    **recup_hist_tab(t_env **env);
char    *make_name_file(t_env **env);

/*prompt.c*/
char    *recup_prompt(t_env *env);
void    aff_prompt(char *prompt);
void    no_term(t_env *env, int *tty);

/*recup_env.c*/
char    *parsing_name(char *str);
char    *parsing_value(char *str);
void    kill_env(t_env **env);
void    recup_env(t_env **env, char **env_tmp);

/*tabenv.c*/
char    **tabenv(t_env *env);
int     list_size(t_env *env);

/*status.c*/
void    fill_signals(char **);
int     display_status(int *status, int);

/*free.c*/
int	free_tab(char **);
void    free_env(t_env *env);
int	tcpgrp_reset();
#endif
