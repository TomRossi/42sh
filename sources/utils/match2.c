/*
** match2.c for mysh in /home/rossi_t//random/projets/minishell
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Tue Dec 20 19:04:30 2011 tom rossi
** Last update Tue Dec 20 19:05:40 2011 tom rossi
*/

int	retmatch(char a, char b)
{
  if (!a && b == '*')
    return (1);
  else
    return (0);
}
