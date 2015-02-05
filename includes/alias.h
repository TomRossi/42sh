/*
** alias.h for alias in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Tue Mar 27 15:38:53 2012 alexis letexier
** Last update Fri May 18 12:59:54 2012 alexis letexier
*/

#ifndef	__ALIAS_H__
#define	__ALIAS_H__

#include        <stdlib.h>
#include        <stdio.h>
#include        <unistd.h>
#include	<str.h>
#include	<list_alias.h>

int     error(int flag);
char	**my_str_to_wordtab_alias(char *str);
int     my_strcmp(char *s1, char *s2);
int	error_alias(char **tab_a);
int     my_strlen(char *str);
char    *my_strdup(char *str);
int	unalias_func(t_alias **alias, char **tab_a);
int     display_alias(t_alias **alias, char *str);
char    **modif_wordtab_alias(char **arg, int i, int a, t_alias *alias);
char	**my_wordtab(char *str);
char    **replace_alias(char **arg, t_alias *alias, int *type);
int     copy_start_alias(char **ret, char **arg, int n, int i);
int     copy_int_alias(char **tmp, char **ret, int n);
int     copy_end_alias(char **ret, int n, char **arg, int a);
void    my_show_wordtab(char **tab_a);
void    copy_to_wordtab(char *str, char *tab_a);
char    *concat_arg_alias(char **tab_a);
void    free_alias(t_alias *alias);

#endif
