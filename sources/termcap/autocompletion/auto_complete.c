/*
** auto_complete.c for 42sh in /home/quemen_g//Projects/42SH/Ted/AUTO_COMPLETION/V_3.0
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Sun May  6 02:38:28 2012 guillaume quemener
** Last update Fri May 18 17:14:14 2012 guillaume quemener
*/

#include	<auto_complete_lib.h>
#include	<auto_glob.h>
#include	<str.h>
#include	<unistd.h>
#include        <sys/stat.h>
#include        <sys/types.h>
#include	<dirent.h>

char		*if_no_space(char *str, char **env)
{
  char		*match;
  char		*ret;
  char		*str2;

  str = auto_complete_epur(str);
  if (my_strcmp(str, "*") == 0)
    {
      match = auto_func_glob(str);
      return (NULL);
    }
  else
    {
      str2 = remove_star(str);
      match = auto_complete_bin(env, str2);
      if (match != NULL)
	{
	  ret = ret_missing_chars_bin(str2, match);
	  return (ret);
	}
      else
	return (NULL);
    }
}

char		*main_function(char *str, char **env)
{
  char		*match;
  char		*ret;
  char		*str2;
  char		*str3;

  if (find_char(' ', str) == 0 && *env != NULL)
    return (if_no_space(str, env));
  str3 = epur_spaces(str);
  str2 = auto_complete_epur(str3);
  match = auto_func_glob(str2);
  if (match != NULL)
    {
      ret = ret_missing_chars(str2, match);
      ret = display_slash(match, ret);
      free(str3);
      free(str2);
      free(match);
      return (ret);
    }
  free(str2);
  free(str3);
  return (NULL);
}
