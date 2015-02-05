/*
** status.c for mysh in /home/rossi_t//random/projets/minishell
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Dec 21 14:39:01 2011 tom rossi
** Last update Sat May 19 10:24:56 2012 tom rossi
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <token.h>
#include <str.h>
#include <tree.h>

void	fill_signals(char **tab)
{
  tab[SIGHUP] = "Hangup\n";
  tab[SIGKILL] = "Killed\n";
  tab[SIGINT] = "\n";
  tab[SIGILL] = "Illegal instruction (core dumped)\n";
  tab[SIGABRT] = "Abort (core dumped)\n";
  tab[SIGFPE] = "Floating exception (core dumped)\n";
  tab[SIGSEGV] = "Segmentation fault (core dumped)\n";
  tab[SIGPIPE] = "Broken pipe\n";
  tab[SIGALRM] = "Alarm clock\n";
  tab[SIGTERM] = "Terminated\n";
  tab[SIGCHLD] = "\nSuspended\n";
  tab[SIGCONT] = "\nSuspended (signal)\n";
  tab[SIGTTIN] = "\nSuspended (tty input)\n";
  tab[SIGTTOU] = "\nSuspended (tty output)\n";
  tab[SIGXCPU] = "Cputime limit exceeded (core dumped)\n";
  tab[SIGXFSZ] = "Filesize limit exceeded (core dumped)\n";
  tab[SIGBUS] = "Bus error (core dumped)\n";
  tab[SIGTRAP] = "Trace/BPT trap (core dumped)\n";
  tab[SIGVTALRM] = "Virtual time alarm\n";
  tab[SIGSYS] = "Bad system call (core dumped)\n";

}

int	display_status(int *status, int from)
{
  int	i;
  char	*tab[33];

  i = 0;
  if (!status)
    return (RETURN_ERROR);
  while (i <= 32)
    tab[i++] = NULL;
  fill_signals(tab);
  if (WIFSIGNALED(*status))
    if (tab[WTERMSIG(*status)])
      {
	my_putstr(tab[WTERMSIG(*status)]);
	return (EXEC_FAIL);
      }
  if (WIFEXITED(*status))
    {
      if (WEXITSTATUS(*status) == EXIT_SUCCESS || !WEXITSTATUS(*status))
	return (RETURN_SUCCESS);
      if (from && WEXITSTATUS(*status) == BYE)
	return (BYE);
    }
  return (EXEC_FAIL);
}
