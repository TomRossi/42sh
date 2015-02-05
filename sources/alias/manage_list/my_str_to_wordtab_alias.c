/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/letexi_a//Documents/annee_1/Projets/BSQ
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed Dec  7 14:24:25 2011 alexis letexier
** Last update Wed May  9 17:41:58 2012 alexis letexier
*/

#include        <alias.h>

int     my_count_words(char *str, int i)
{
  int a;

  a = 0;
  while (str[i])
    {
      if ((str[i] != '\t' && str[i] != ' ' && str[i] != '\'')
	  && str[i] != '\0')
        {
          a++;
          while ((str[i] != '\t' && str[i] != ' '  && str[i] != '\'')
		 && str[i] != '\0')
	    i++;
        }
      if (str[i] == '\'')
	{
	  a++;
	  i++;
	  while (str[i] != '\'' && str[i] != '\0')
	    i++;
	  i++;
	}
      while ((str[i] == '\t' || str[i] == ' ') && str[i] != '\0')
	i++;
    }
  return (a);
}

int     nb_lettres(char *str, int n)
{
  int   compt;

  compt = 0;
  while ((str[n] == '\t' || str[n] == ' ') && str[n] != '\0')
    n++;
  if (str[n] == '\'')
    {
      n++;
      while (str[n] != '\'' && str[n] != '\0')
	{
	  n++;
	  compt++;
	}
      n++;
    }
  while (str[n] != '\t' && str[n] != ' ' && str[n] != '\0')
    {
      compt++;
      n++;
    }
  return (compt);
}

int     count(char *str, char *tab_a, int i)
{
  int   n;
  int   a;

  n = i;
  a = 0;
  while (str[n])
    {
      while ((str[n] == '\t' || str[n] == ' ') && str[n] != '\0')
        n++;
      if (str[n] == '\'')
        {
	  n++;
          while (str[n] != '\'' && str[n] != '\0')
	    tab_a[a++] = str[n++];
	  n++;
        }
      while (str[n] != '\t' && str[n] != ' ' && str[n] != '\0')
	tab_a[a++] = str[n++];
      tab_a[a] = '\0';
      return (n);
    }
  return (0);
}

char    **my_str_to_wordtab_alias(char *str)
{
  int   n;
  char  **tab_a;
  int   a;
  int   b;

  b = 0;
  n = 0;
  a = 0;
  tab_a = malloc(sizeof (tab_a) * (my_count_words(str, 0) + 1));
  if (tab_a == NULL)
    return (NULL);
  while (n < my_count_words(str, 0))
    {
      a = nb_lettres(str, b);
      tab_a[n] = malloc((sizeof (*tab_a) * a) + 1);
      if (tab_a[n] == NULL)
	return (NULL);
      b = count(str, tab_a[n], b);
      n = n + 1;
    }
  tab_a[n] = NULL;
  return (tab_a);
}
