/*
** my_pow.c for calculator in /home/louaze_j//Colle2
** 
** Made by jean-baptiste louazel
** Login   <louaze_j@epitech.net>
** 
** Started on  Thu Apr 26 23:23:17 2012 jean-baptiste louazel
** Last update Thu Apr 26 23:28:17 2012 jean-baptiste louazel
*/

int	my_pow(int nb, int pow)
{
  int	res;

  res = 1;
  while (pow > 0)
    {
      res *= nb;
      pow--;
    }
  return (res);
}
