/*
** cd.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Wed Dec 14 18:09:31 2011 tom rossi
** Last update Sat May 19 13:05:35 2012 tom rossi
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <env.h>
#include <builtin.h>
#include <str.h>

int             dispaccess(char *path)
{
  struct stat   buf;

  if (access(path, F_OK))
    printf("%s: No such file or directory.\n", path);
  else if (access(path, R_OK))
    printf("%s: Permisson denied.\n", path);
  else
    {
      if (stat(path, &buf))
        return (0);
      if (!S_ISDIR(buf.st_mode))
        {
          printf("%s: Not a directory.\n", path);
          return (0);
        }
      return (1);
    }
  return (0);
}

int	print(char *str)
{
  my_putstr(str);
  my_putchar('\n');
  return (0);
}

int	home(t_env **env)
{
  t_env *tmp_pwd;
  t_env	*tmp_home;

  tmp_pwd = *env;
  tmp_home = *env;
  while (tmp_home && my_strcmp(tmp_home->name, "HOME"))
    tmp_home = tmp_home->next;
  while (tmp_pwd && my_strcmp(tmp_pwd->name, "PWD"))
    tmp_pwd = tmp_pwd->next;
  if (!tmp_pwd || !tmp_home)
    {
      my_putstr("No HOME or PWD env variable.\n");
      return (EXIT_FAILURE);
    }
  if (!dispaccess(tmp_home->value))
    return (EXIT_FAILURE);
  free(tmp_pwd->value);
  tmp_pwd->value = my_strdup(tmp_home->value);
  if (tmp_pwd && !chdir(tmp_pwd->value))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int	back(t_env **env)
{
  t_env	*pwd;
  t_env	*pwd_old;
  char	*path;

  pwd = *env;
  pwd_old = *env;
  while (pwd && my_strcmp(pwd->name, "PWD"))
    pwd = pwd->next;
  while (pwd_old && my_strcmp(pwd_old->name, "OLDPWD"))
    pwd_old = pwd_old->next;
  if (!pwd || !pwd_old)
    return (EXIT_SUCCESS);
  path = pwd->value;
  pwd->value = pwd_old->value;
  pwd_old->value = path;
  chdir(pwd->value);
  return (EXIT_SUCCESS);
}

int	cd(t_env **env, char **av)
{
  char* s;

  if (!av[1] || !my_strcmp(av[1], "~"))
    return (home(env));
  else if (!my_strcmp(av[1], "-"))
    return (back(env));
  if (!my_strcmp(av[1], "-l") && av[2])
    {
      s = av[1];
      av[1] = av[2];
      av[2] = s;
    }
  if (!dispaccess(av[1]))
    return (EXIT_FAILURE);
  if (!chdir(av[1]))
    return (pwd(env, av));
  printf("%s: No such file or directory.\n", av[1]);
  return (EXIT_FAILURE);
}
