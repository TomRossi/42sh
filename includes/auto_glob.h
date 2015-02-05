/*
** my_glob.h for my_glob 42 sh in /home/quemen_g//Projects/42SH/Ted/test_readdir/toto
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Fri Apr  6 15:52:03 2012 guillaume quemener
** Last update Wed May 16 18:26:44 2012 guillaume quemener
*/

#ifndef		__MY_GLOB_H__
#define		__MY_GLOB_H__

#include	<glob.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

typedef struct s_glob
{
  char		**_tab;
  int		nb;
} t_glob;

void		my_auto_globfree(glob_t *paths);
t_glob		*auto_globbing(char *str, t_glob *match);
void		auto_show_tab(char **str, int n);
char		*auto_func_glob(char *str);
#endif
