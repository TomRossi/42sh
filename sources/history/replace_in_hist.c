/*
** replace_in_hist.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/history
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May 16 13:58:49 2012 maxime lespagnol
** Last update Wed May 16 14:49:53 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<str.h>
#include	<env.h>
#include	<term_man.h>

char	*return_val_hist(char **hist, int val)
{
  int	k;
  char	*ret;

  if (val < 0 && (len_tab(hist) + val) >= 0)
    {
      k = len_tab(hist) - 1;
      while (val > 0)
	{
	  k--;
	  val--;
	}
      ret = my_strdup(hist[k]);
    }
  else if (val >= 0 && (len_tab(hist) >= val))
    ret = my_strdup(hist[val]);
  else
    return (NULL);
  return (ret);
}

char	*recup_hist_val(char *str, int k, char **hist)
{
  int	i;
  char	*val;
  int	h_val;
  char	*ret;

  i = k;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    i++;
  if ((val = malloc(sizeof(*val) * (i - k + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[k] != '\0' && str[i] != ' ' && str[i] != '\t')
    val[i++] = str[k++];
  val[i] = '\0';
  if ((check_val(val)) != 0)
    {
      xfree(val);
      return (NULL);
    }
  h_val = my_getnbr(val);
  xfree(val);
  ret = return_val_hist(hist, h_val);
  return (ret);
}

int	new_size_str(char *str, int k, char *hist_v)
{
  int	i;
  int	size_less;
  int	size;

  i = k;
  size_less = 0;
  while (str[i] != '\0' && str[i]!= ' ' && str[i] != '\t')
    {
      i++;
      size_less++;
    }
  size = my_strlen(str) + my_strlen(hist_v) + 1 - size_less;
  return (size);
}

char	*add_hist_value(t_term *ptr, char **hist, int k, int i)
{
  char	*hist_val;
  char	*new_str;
  int	size;
  int	j;

  hist_val = recup_hist_val(ptr->str, (k + 1), hist);
  size = new_size_str(ptr->str, k, hist_val);
  if ((new_str = malloc(sizeof(*new_str) * (size))) == NULL)
    return (NULL);
  j = 0;
  while (ptr->str[i] != '\0' && i < k)
    new_str[j++] = ptr->str[i++];
  while (ptr->str[i] != '\0' && ptr->str[i] != '\t' && ptr->str[i] != ' ')
    i++;
  k = 0;
  while (hist_val != NULL && hist_val[k] != '\0')
    new_str[j++] = hist_val[k++];
  while (ptr->str[i] != '\0')
    new_str[j++] = ptr->str[i++];
  new_str[j] = '\0';
  xfree(hist_val);
  return (new_str);
}

int	replace_in_hist(t_term *ptr, char **hist)
{
  int	k;
  char	*tmp;

  k = 0;
  while (ptr->str != NULL && ptr->str[k] != '\0')
    {
      if (ptr->str[k] == '!')
	{
	  tmp = add_hist_value(ptr, hist, k, 0);
	  xfree(ptr->str);
	  ptr->str = my_strdup(tmp);
	  xfree(tmp);
	  while (ptr->str[k] != '\0' && ptr->str[k] != '\t'
		 && ptr->str[k] != ' ')
	    k++;
	}
      if (ptr->str[k] != '\0')
	k++;
    }
  return (0);
}
