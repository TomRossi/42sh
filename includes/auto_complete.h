/*
** my_glob.h for my_glob 42 sh in /home/quemen_g//Projects/42SH/Ted/test_readdir/toto
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Fri Apr  6 15:52:03 2012 guillaume quemener
** Last update Fri May 18 17:14:05 2012 guillaume quemener
*/

#ifndef		__AUTO_COMPLETE_H__
#define		__AUTO_COMPLETE_H__

#include	<stdio.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<termios.h>
#include	<curses.h>
#include	<term.h>
#include        <sys/stat.h>
#include        <sys/types.h>

typedef struct	s_list
{
  int		id;
  char		*file;
  int		type;
  struct s_list	*next;
} t_list;

char		*auto_completion(int flag, t_list *list, char *str, char **env);
char		*auto_type_path_only(t_list *list, char *str);
char		*auto_type_path_file(t_list *list, char *str);
char		*auto_type_file(t_list *list, char *str);
char		*auto_type_dot_slash(t_list *list, char *str);
char		*auto_cmd(t_list *list, char *str, char **env);
char		*main_function(char *str, char **env);

#endif
