/*
** my_glob.h for my_glob 42 sh in /home/quemen_g//Projects/42SH/Ted/test_readdir/toto
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Fri Apr  6 15:52:03 2012 guillaume quemener
** Last update Sat May 19 11:46:51 2012 tom rossi
*/

#ifndef		__MY_GLOB_H__
#define		__MY_GLOB_H__

#include	<glob.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#define	G_I	0
#define G_A	1
#define G_X	2

void		my_globfree(glob_t *paths);
char		**my_globbing(char *str);
char            **my_func_glob(char *str);
void		show_tab(char **tab);
char		**glob_sub(char **tab, int *);

#endif
