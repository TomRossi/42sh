/*
** auto_complete_utils.h for 42 in /home/quemen_g//Projects/42SH/Ted/AUTO_COMPLETION
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Wed May  2 16:56:20 2012 guillaume quemener
** Last update Sat May 12 15:35:03 2012 guillaume quemener
*/

#ifndef		__AUTO_COMPLETE_UTILS_H__
#define		__AUTO_COMPLETE_UTILS_H__

int		find_space(char *str);
char		*take_str_auto(char *str);
int		check_dot_slash(char *str);
int		detect_path(char *str);
int		count_slash(char *str);
char		*cpy_word(char *str, int i, int c);
char		*remove_slash(char *str);
char		*take_path(char *str);
char		*cpy_path(char *str);
int		check_str(char *str);
char		*auto_co_epur_str(char *str);
int		count_invisible_chars(char *str);
char		*concat_path_word(char *path, char *word);
char		**take_env_path(char **str);
int		check_if_cmd(char *str);

/* my_str_to_wordtab.c */
int     is_sep(char a, char *sep);
int	len(char *str, int i, char *sep);
char	*wcopy(char *str, char *str_out, int i, char *sep);
int	words(char *str, char *sep);
char	**my_str_to_wordtab(char *str, char *sep);
#endif
