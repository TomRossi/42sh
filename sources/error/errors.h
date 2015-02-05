/*
** errors.h for 42sh in /home/bourga_y//At_home/PROJETS/42SH/Yoann
** 
** Made by yoann bourgault
** Login   <bourga_y@epitech.net>
** 
** Started on  Tue Apr 10 15:36:13 2012 yoann bourgault
** Last update Fri May 18 11:02:19 2012 yoann bourgault
*/

#ifndef ERRORS_H__
#define ERRORS_H__

#define E_INV		"Invalid null command.\n"
#define E_RED		"Missing name for redirect.\n"
#define E_CMD		": Command not found.\n"
#define E_FAT		"Fatal error: something went wrong, we are sorry.\n"
#define E_BRACKET_O	"Too many ('s.\n"
#define E_BRACKET_C	"Too many )'s.\n"
#define E_BADLY         "Badly placed ()'s.\n"
#define E_AMB           "Ambiguous output redirect.\n"

int             e_arguments(int *, int);
int             e_or_and_pipe(int *, int);
int             e_red_arguments(int *, int);
int             e_redirects(int *, int, int);
int             double_redirection(int *, int);
int             e_brackets(int *);
int             e_into_brackets(int *, int, int);
int             e_before_opening_bracket(int *, int);
int             error_management(int *, int);
void		pstr(char *, int);
void		pchar(char, int);

#endif
