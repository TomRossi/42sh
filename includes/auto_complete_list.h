/*
** list.h for list 42 auto in /home/quemen_g//Projects/42SH/Ted/test_readdir/AUTO_COMPLETION
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Sat Apr 14 04:59:58 2012 guillaume quemener
** Last update Wed May  2 17:11:43 2012 guillaume quemener
*/

#ifndef		__LIST_H__
#define		__LIST_H__

int		my_list_size(t_list *list);
t_list		*rm_list(t_list *list);
int		get_type_of_file(struct stat *sb);
int		my_put_in_list(t_list **list, char *str, int i, struct stat *sb);
t_list		*list_files(char *str, t_list *list);
int		my_list_size(t_list *begin);

#endif
