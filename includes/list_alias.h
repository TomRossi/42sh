/*
** list_alias.h for list_alias in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Tue Mar 27 15:44:56 2012 alexis letexier
** Last update Mon May 14 17:53:12 2012 alexis letexier
*/

#ifndef	__LIST_ALIAS_H__
#define	__LIST_ALIAS_H__

typedef	struct	s_alias
{
  char	*name;
  char	*arg;
  int	pos;
  struct s_alias	*next;
}t_alias;

#define	RETURN_SUCCESS	0
#define RETURN_ERROR	-1

int	list_alias(t_alias **alias, char *name, char *arg);
int	alias_func(t_alias **alias, char **tab_a);
int	add_alias(t_alias **alias, char *name, char *arg);
void    my_show_alias(t_alias *alias);
int     my_strcmp(char *s1, char *s2);
int	manage_add_alias(t_alias **alias, char **);
int     verif_add_alias(char **);

#endif
