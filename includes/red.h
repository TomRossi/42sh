/*
** red.h for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sun Apr  1 11:56:03 2012 tom rossi
** Last update Tue Apr 10 15:34:44 2012 tom rossi
*/

#ifndef __RED_H__
#define	__RED_H__

#define	NONE	0
#define	SIMPLE	1
#define	DOUBLE	2

#define	INPUT	0
#define	OUTPUT	1

typedef struct s_red
{
  int	out_type;
  int	in_type;
  int	out_fd;
  int	in_fd;
  char	*in;
} t_red;

#endif
