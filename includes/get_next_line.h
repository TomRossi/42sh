/*
** get_next_line.h for get_next_line in 
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Mon Nov 14 16:16:40 2011 tom rossi
** Last update Tue May  1 11:47:49 2012 tom rossi
*/

#ifndef		__GET_NEXT_LINE_H__
#define		__GET_NEXT_LINE_H__

#define		G_READ		100

char		*get_next_line(const int fd);
char            *init(char *buf, int *a);
char		*push(char *str, char *str_out);

#endif
