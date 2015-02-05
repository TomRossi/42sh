/*
** token.h for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Mar 28 12:40:52 2012 tom rossi
** Last update Sat May 19 10:17:42 2012 tom rossi
*/

#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <env.h>

/*tokens, zero is for the end of the int* */
#define	T_END		0
#define	T_IN_S		1
#define	T_ARG		2
#define	T_CMD		3
#define	T_BIN		4
#define	T_AND		5
#define	T_OR		6
#define	T_OUT_S		7
#define	T_PIPE		8
#define	T_RED		9
#define	T_ALPHA		10
#define	T_BUILT		11
#define T_IN_D		12
#define T_OUT_D		13
#define T_RED_IN_S	14
#define	T_BRACKET_O	15
#define	T_BRACKET_C	16
#define T_SEMICOL	17

/*specifics chars, use this*/
#define C_PIPE		'|'
#define C_IN		'<'
#define	C_OUT		'>'
#define	C_AND		'&'
#define	C_OR		'|'
#define	C_TAB		'\t'
#define	C_SPACE		' '
#define	C_SIMPLE	'\''
#define	C_DOUBLE	'\"'
#define	C_BRACKET_O	'('
#define C_BRACKET_C	')'
#define C_SEMICOL	';'

/*specific strings*/
#define	S_SPEC		"|><&;$\""
#define	S_SEP_ALL	" \t|;&<>\"\'"
#define	S_SPACE		" \t"
#define S_ANDOR		"&|"
#define	S_SEP		"|&<;>\"\'"
#define	S_MULT		"|&<>"
#define	S_SIMPLE	"\'"
#define	S_DOUBLE	"\""

/*quotes*/
#define	M_NORMAL	0
#define	M_DOUBLE	1
#define	M_SIMPLE	2
#define M_NONE		3

/*useful defines*/
#define	TRUE	1
#define	FALSE	0
#define	RETURN_SUCCESS	0
#define	RETURN_ERROR	-1
#define	EXEC_FAIL	-8
#define OR_SUCCESS	-7
#define OR_FAIL		-9
#define AND_SUCCESS	-11
#define AND_FAIL	-10
#define	NO_RETURN	1

typedef struct s_list
{
  int		type;
  int		is_data;
  char		*data;
  char		*path;
  int		mode;
  int		red_type;
  int		rank;
  struct s_list	*next;
  struct s_list	*prev;
} t_list;

/*returns FALSE if c isn't in s*/
int     is_char_valid(char c, char *s);
int     is_str_valid(char *c, char *s);
char    *my_strdup(char *str);
char    **build_av(t_list *list);
char    *var_sub(t_env *env, char *s, int *i);

/*token.c*/
int     add_node(t_list **list, char *data, int x, int mode);
char    *get_str(char *str, int i, int mode);
int     set_alpha(int *);
int     *token(char *s, t_list **list);

/*returns FALSE if c isn't in s*/
int     is_char_valid(char c, char *s);
int     is_str_valid(char *c, char *s);
char    *my_strdup(char *str);
char    **build_av(t_list *list);
char    *var_sub(t_env *env, char *s, int *i);

/*token.c*/
int     add_node(t_list **list, char *data, int x, int mode);
char    *get_str(char *str, int i, int mode);
int     set_alpha(int *);
int     *token(char *s, t_list **list);

/*token_set.c*/
void    set_mode(char **);
void    token_and_or(char c, int *, int x);
void    token_bin(char c, int *, int x);
void    token_init_val(char **tab_, int *x, int *i);
void    set_token(char *s, int *, int *ref);

/*token_redirect.c*/
int     is_red(t_list *tmp);
void    push_red(t_list *tmp);
int     move_red(t_list *tmp);
void    move_first_red(t_list **list);
int     token_redirect(t_list **list);

/*token_size.c*/
void    calc_close(int *i, int *x, char c, char *s);
int     calc_size(t_list **list, char *s, int *i, int *x);
int     get_size(char *s, t_list **list);

/*token_clean.c*/
int     node_kill(t_list **list, t_list *tmp);
t_list  *get_close(t_list *_open);
int     bracket_kill(t_list **list, t_list *_open);
int     useless(t_list *tmp);
int     token_clean(t_list **list);

/*token_envsub.c*/
void    sub_end(char *s, char *out, int i, int *x);
char    *str_sub(char *s, int *i, char *data);
int     my_envcmp(t_env *tmp, char *s, int i);
char    *var_sub(t_env *env, char *s, int *i);

/*token_substitute.c*/
char    *list_sub(char *, t_env *env);
char    **token_envsub(char **, t_env *env, int *);

/*token_list.c*/
int     new_list(t_list **new, int type);
void    edit_list(t_list *tmp, t_list **new);
void    init_list(t_list **tmp, t_list **new, int *i, t_list **list);
int     token_list(int *, t_list **list);
void    free_list(t_list *list);

int     *token(char *s, t_list **list);
void	ref_tab(int *ref);
void    free_list(t_list *list);

#endif
