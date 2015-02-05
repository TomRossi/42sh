/*
** lib.h for 42 in /home/quemen_g//Projects/42SH/Ted/AUTO_COMPLETION
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Wed May  2 15:54:55 2012 guillaume quemener
** Last update Fri May 18 17:14:09 2012 guillaume quemener
*/

#ifndef		__LIB_H__
#define		__LIB_H__

#include	<unistd.h>
#include	<stdlib.h>
#include        <termios.h>
#include        <curses.h>
#include        <term.h>
#include	<glob.h>
#include	<stdio.h>
#include	<string.h>

typedef struct	s_list
{
  char		*file;
  struct s_list	*next;
} t_list;

/* auto-completion */
int		find_longest_word(char **str, int nb);
char		*func_match(char **str, int nb, int len);
char		*auto_complete_epur(char *str);
char		*ret_missing_chars(char *str, char *match);
char		*ret_missing_chars_bin(char *str, char *match);
int		find_char(char c, char *str);
int		count_char(char c, char *str);
char		*remove_spaces(char *str);
char		*epur_spaces(char *str);
char		*take_path_from_env(char **env);
char		**my_str_to_word_tab(char *str, char c);
char		*my_concat_path(char *str, char *str2);
t_list		*add_to_list_bin(t_list *list, char *str);
void		show_list_bin(t_list *list);
char		*find_match_bin(t_list *list, char *str);
char		*auto_complete_bin(char **env, char *str);
char		*remove_star(char *str);
char		*main_function(char *str, char **env);
char		*display_slash(char *str, char *ret);
void		free_list_auto_bin(t_list *list);
/* list */
t_list		*list_files(char *str, t_list *list);
int		my_put_in_list(t_list **list, char *str);
int		my_list_size(t_list *begin);
t_list		*rm_list(t_list *list);

#endif
