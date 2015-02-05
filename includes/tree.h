/*
** tree.h for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sun Apr  1 11:57:59 2012 tom rossi
** Last update Sat May 19 11:16:35 2012 tom rossi
*/

#ifndef	__TREE_H__
#define	__TREE_H__

#include <red.h>
#include <env.h>
#include <token.h>

#define	LEFT	0
#define	RIGHT	1
#define	AND	0
#define	OR	1
#define	FROM	0
#define	TO	1

#define	PRINT(x)	fprintf(stderr, x);

#define	M_WRITE	0
#define	M_READ	1
#define M_VOID	3

#define V_VALID	0
#define V_FAIL	1
#define	V_NONE	2

#define IS_DOUBLE	-8

typedef struct s_tree
{
  int		type;
  int		ret;
  struct s_cmd	*semicol;
  struct s_cmd	*cmd[2];
  struct s_tree	*next[2];
}t_tree;

typedef struct s_cmd
{
  int		type;
  char		**av;
  int		*av_type;
  char		*path;
  char		*data;
}t_cmd;

typedef struct s_pipe
{
  int		p[2];
  int		mode;
  int		type;
  int		fd;
  char		*data;
  struct s_pipe	*next;
  struct s_pipe	*prev;
}t_pipe;

char    *get_cmd_path(char *exe, t_env *env);
t_pipe  *search_file(t_pipe *tmp);
int	send(t_tree *node, t_list *list, int where, t_tree **tree);

/*tree_build.c*/
t_list  *get_mid_type(t_list *list, int type);
t_list  *get_red(t_list *list);
t_list  *get_middle(t_list *list);
int     tree_build(t_tree **tree, t_list *list);
int     tree_node(t_list *list, t_tree **tree);
t_cmd   *tree_cmd(t_list *list);

/*tree_execute.c*/
int     close_pipe(t_pipe *_pipe);
int     execute_(t_cmd *cmd, t_pipe **_pipe, t_sh *sh);
int     exec_left(t_tree *tree, t_pipe **pipe, t_sh *sh, int);
int     exec_right(t_tree *tree, t_pipe **pipe, t_sh *sh, int);
int     f_exec(t_cmd *cmd, t_pipe **pipe, t_sh *sh, int gp);

/*tree_explore.c*/
int     valid_return(int *_ret, int type);
int     no_fork(t_tree *tree, t_pipe **pipe, t_sh *sh, int);
int     tree_explore(t_tree *tree, t_pipe **pipe, t_sh *sh, int);
int     my_sh(t_tree *tree, t_sh *sh);

/*tree_pipe.c*/
void    pipe_write(t_pipe *p);
void    pipe_read(t_pipe *p);
void    pipe_skip(t_pipe *r, t_pipe *w);
void    dup_pipe(t_pipe **_pipe, int type);
int     tree_pipe(t_pipe **_pipe, int type, t_tree *tree);

/*tree_redirect.c*/
t_pipe  *search_file(t_pipe *tmp);
int     set_output(t_pipe *new, int type, char *path);
int     set_input(t_pipe *new, int type, char *path);
int     tree_redirect(t_pipe *new, int type, t_tree *tree);

/*tree_utils.c*/
int     middle_node(int type);
int     exec_node(int type);
int    send(t_tree *node, t_list *list, int where, t_tree **tree);
int     valid_red(t_list *tmp);

/*bin.c*/
char    *freenull(char **path);
char    *get_cmd_path(char *exe, t_env *env);

/*bin_cmd_path.c*/
int     is_builtin(char *s);
int     path_cmd(t_cmd *list, t_env *env);
int     path_bin(t_cmd *list, t_env *env);
int     get_path(t_cmd *tmp, t_env *env);
int     bin_cmd(t_cmd *list, t_env *env);

/*red_set.c*/
int     redirect_type(t_list *list);
int     redirect_set(t_list *list);

/*red_access.c*/
int     red_access(char *path, int type);

/*red_access.c*/
void	kill_red_write(t_pipe **pipe);
void	kill_red_read(t_pipe **pipe);
void	kill_pipe(t_pipe **pipe);

void	free_tree(t_tree *);
int     exec_pipe(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad);
int     valid_return(int *_ret, int type);
int     not_a_pipe(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad);
int     is_redir(t_tree *tmp);
int     str_action(char *buf, t_sh *sh);
int     last_builtin(t_cmd *cmd, t_env **env, t_sh *sh, t_pipe *file);
int	new_group();
int     *build_av_type(t_list *list);
void    set_env_return(t_sh *sh, int ret);
char    *double_red(char *stop);

#endif
