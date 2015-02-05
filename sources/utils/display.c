/*
** display.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Thu Mar 29 17:25:32 2012 tom rossi
** Last update Mon Apr 30 17:36:24 2012 tom rossi
*/

#include <stdio.h>

void    display_tab(int *tab)
{
  int   i;

  i = 0;
  while (tab[i]);
    printf("%d\n", tab[i++]);
}
