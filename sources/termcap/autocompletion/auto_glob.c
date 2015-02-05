/*
** main.c for glob in /home/quemen_g//Projects/42SH/Ted/test_readdir/toto
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Wed Apr  4 13:43:22 2012 guillaume quemener
** Last update Wed May 16 18:27:31 2012 guillaume quemener
*/

#include	<auto_complete_lib.h>
#include	<str.h>
#include	<auto_glob.h>

void		my_auto_globfree(glob_t *paths)
{
  int		i;

  i = 0;
  while ((paths)->gl_pathv[i] != '\0')
    free((paths)->gl_pathv[i++]);
  free((paths)->gl_pathv);
  return ;
}
void		display_result(char *str)
{
  int		c;
  int		i;
  int		j;

  i = 0;
  j = 0;
  c = 0;
  if (find_char('/', str) == 0)
    {
      my_putstr(str);
      return ;
    }
  if (find_char('/', str) == 1)
    c = count_char('/', str);
  while (str[i])
    {
      if (str[i] == '/')
	j++;
      i++;
      if (j == c)
	my_putchar(str[i]);
    }
  return ;
}
void		auto_show_tab(char **str, int n)
{
  int		i;

  i = 0;
  my_putchar('\n');
  while (str[i] != NULL && i != n)
    {
      display_result(str[i]);
      my_putstr("\t");
      i++;
    }
}
t_glob		*auto_globbing(char *str, t_glob *match)
{
  glob_t	paths;
  int		ret;

  ret = glob(str, 0, NULL, &paths);
  if (ret == 0)
    {
      match->_tab = paths.gl_pathv;
      match->nb = paths.gl_pathc;
      return (match);
    }
  return (NULL);
}

char		*auto_func_glob(char *str)
{
  t_glob	*match;
  char		*word;

  match = malloc(sizeof(*match));
  match = auto_globbing(str, match);
  if (match == NULL)
    return (NULL);
  if (match->nb > 1)
    {
      auto_show_tab(match->_tab, match->nb);
      return (NULL);
    }
  word = my_strdup(match->_tab[0]);
  return (word);
}
