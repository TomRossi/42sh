/*
** strings.h for mysh in /home/rossi_t//random/projets/minishell
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sat Dec 17 22:50:13 2011 tom rossi
** Last update Fri May 18 16:58:14 2012 tom rossi
*/

#ifndef __STR_H__
#define __STR_H__

#define	ABS(x)	(x) >= 0 ? (x) : (-x)

char    *epur_hist(char *str);
int     my_getnbr(char *str);
int	check_val(char *val);
void    my_putnbr(int nb);
char    *main_function(char *str, char **env);
char    **my_strdup_tab(char **tmp);
char    **verif_file_hist(char **out, char *new);
void    show_wordtab(char **tmp);
int     len_tab(char **tmp);
int     my_strncmp(char *s1, char *s2, int n);
char    *get_next_line(const int fd);
void    xfree_tab(char **ptr);
char    *my_strdup(char *s);
char    *my_strcat(char *dest, char *src);
char    **my_str_to_wordtab(char *str, char *sep);
void    malloc_bye();
void    my_putchar(char c);
int     my_putstr(char *str);
int     my_strlen(char *str);
int     match(char *s1, char *s2);
int     my_strcmp(char *s1, char *s2);
int     my_printf(char *str, char *arg);
void    my_putfd(char *str, int fd);
int     is_char_valid(char c, char *s);
int     is_str_valid(char *c, char *s);
int     skip_char(char *s, char *ref, int *i);
void    wait_for(char *s, char *ref, int *i);
void    delete_space(char *s);
int     quotes(char *s);
char    **recup_file(char *file);
int	my_pow(int, int);
char	*my_getstr(int);

#endif
