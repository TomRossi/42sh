/*
** builtin.h for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr  4 11:40:09 2012 tom rossi
** Last update Sat May 19 13:25:20 2012 tom rossi
*/

#ifndef __BUILINT_H__
#define __BUILTIN_H__

#include <env.h>

#define	B_CD		"cd"
#define B_ENV		"env"
#define B_SENV		"setenv"
#define B_UENV		"unsetenv"
#define B_ECHO		"echo"
#define B_EXIT		"exit"
#define B_ALIAS		"alias"
#define B_UNALIAS	"unalias"
#define B_HISTORY	"history"
#define	N_BUILT		9

#define	S_ON	"-e"
#define S_OFF	"-E"
#define S_N	"-n"

#define O_ON	0
#define O_OFF	1
#define O_N	2

#define EXIT_RETURN	32

/*builtins.c*/
int     freeturn(char **tab, int ret);
int     echo(char **tab, int fd);
int     builtins(char **tab, t_env **env, t_sh *sh, int fd);
int     display(t_env *env, int fd);

/*cd.c*/
int	dispaccess(char *path);
int     print(char *str);
int     home(t_env **env);
int     back(t_env **env);
int     cd(t_env **env, char **av);

/*path.c*/
char    *slash(char *freeme);
char    *rmpath(char *str);
char    *pwdcat(char *path, char *exe);
char    *definepwd(char *str, char *pwd);
int     pwd(t_env **env, char **av);

/*setenv.c*/
void    freevararg(char *name, char *value);
int     unset_env(t_env **env, char *name);
int     update(t_env **env, char **av);
int     set_env(t_env **env, char **av, int fd);
int     addvar(t_env **env, char *var, char *arg);

#endif
