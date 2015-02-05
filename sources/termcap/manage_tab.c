/*
** manage_tab.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Fri May  4 14:12:57 2012 maxime lespagnol
** Last update Wed May 16 18:41:01 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<term_man.h>
#include	<str.h>
#include	<env.h>

void	modif_str(t_term *ptr, char *ret, int i, int k)
{
  char	*tmp;
  int	size;

  size = my_strlen(ptr->str) + my_strlen(ret) + 1;
  if ((tmp = malloc(sizeof(*tmp) * (size))) != NULL)
    {
      while (ptr->str != NULL && ptr->str[i] != '\0')
	tmp[k++] = ptr->str[i++];
      i = 0;
      while (ret != NULL && ret[i] != '\0')
	tmp[k++] = ret[i++];
      tmp[k] = '\0';
      xfree(ptr->str);
      ptr->str = my_strdup(tmp);
      xfree(tmp);
    }
}

void	manage_tab(t_term *ptr, t_env **env_tmp)
{
  char	*ret;
  char	**env;

  env = tabenv(*env_tmp);
  ret = main_function(ptr->str, env);
  my_putstr("\r\n");
  my_putstr(ptr->prompt);
  my_putstr(ptr->str);
  my_putstr(ret);
  if (ret != NULL)
    {
      modif_str(ptr, ret, 0, 0);
      ptr->pos = ptr->pos + my_strlen(ret);
    }
  xfree(ret);
  xfree_tab(env);
}
