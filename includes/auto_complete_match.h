/*
** auto_complete_match.h for 42 in /home/quemen_g//Projects/42SH/Ted/AUTO_COMPLETION
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Wed May  2 17:02:59 2012 guillaume quemener
** Last update Fri May  4 14:09:39 2012 guillaume quemener
*/

#ifndef		__AUTO_COMPLETE_MATCH_H__
#define		__AUTO_COMPLETE_MATCH_H__

char		*find_match_id(t_list *list, int sav);
char		*matching_file(char *word, t_list *list, int i, int j);

#endif
