/*
** my_wordtab.c for my_wordtab in /home/letexi_a//Documents/Tek1/Projets/42sh/alias/replace_alias
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed May  2 09:16:36 2012 alexis letexier
** Last update Tue May 15 14:30:41 2012 alexis letexier
*/

#include	<alias.h>

int     my_count_words_wordtab(char *str)
{
  int i;
  int a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      if ((str[i] != '\t' && str[i] != ' ') && str[i] != '\0')
        {
          a++;
          while ((str[i] != '\t' && str[i] != ' ')
                 && str[i] != '\0')
            i++;
        }
      if (str[i] != '\0')
	i++;
    }
  return (a);
}

int     nb_lettres_wordtab(char *str, int n)
{
  int   compt;

  while (str[n] != '\0')
    {
      compt = 0;
      while ((str[n] == '\t' || str[n] == ' ')
             && str[n] != '\0')
	n++;
      while ((str[n] != '\t' && str[n] != ' ')
             && str[n] != '\0')
        {
          compt = compt + 1;
          n++;
        }
      return (compt);
    }
  return (0);
}

int     count_wordtab(char *str, char *tab_a, int n)
{
  int   a;

  a = 0;
  while (str[n] != '\0')
    {
      while ((str[n] == '\t' || str[n] == ' ')
             && str[n] != '\0')
        n++;
      while ((str[n] != '\t' && str[n] != ' ')
             && str[n] != '\0')
        {
          tab_a[a] = str[n];
          n++;
          a++;
        }
      tab_a[a] = '\0';
      return (n);
    }
  return (0);
}

char    **my_wordtab(char *str)
{
  int   n;
  char  **tab_a;
  int   a;
  int   b;

  b = 0;
  n = 0;
  a = 0;
  tab_a = malloc(sizeof (tab_a) * (my_count_words_wordtab(str) + 1));
  if (tab_a == NULL)
    return (NULL);
  while (n < my_count_words_wordtab(str))
    {
      a = nb_lettres_wordtab(str, b);
      tab_a[n] = malloc((sizeof (*tab_a) * a) + 1);
      if (tab_a[n] == NULL)
        return (NULL);
      b = count_wordtab(str, tab_a[n], b);
      n++;
    }
  tab_a[n] = NULL;
  return (tab_a);
}
