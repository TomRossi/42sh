/*
** my_show_alias.c for my_show_alias in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Tue Mar 27 16:10:04 2012 alexis letexier
** Last update Wed May  9 17:41:44 2012 alexis letexier
*/

#include	<list_alias.h>
#include	<alias.h>

void	my_show_alias(t_alias *alias)
{
  while (alias != NULL)
    {
      my_putstr(alias->name);
      my_putstr("\t");
      my_putstr(alias->arg);
      my_putchar('\n');
      alias = alias->next;
    }
}
