/*
** term_man.h for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/includes
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Thu Apr 26 18:04:29 2012 maxime lespagnol
** Last update Wed May 16 14:37:44 2012 maxime lespagnol
*/

#ifndef		__TERM_MAN_H__
#define		__TERM_MAN_H__

#define	CTRL_RIGHT	19
#define	CTRL_LEFT	18
#define	ALT_A		17
#define	DONT		16
#define	STR_ENTER	15
#define	PASTE		14
#define	COPY_W		13
#define	COPY		12
#define	TAB		11
#define	END		10
#define	BEGIN		9
#define	CLEAR		8
#define	BACKSPACE	7
#define	DELETE		6
#define	RIGHT_T		5
#define	LEFT_T		4
#define	DOWN		3
#define	UP		2
#define	NOTH		1
#define	ENTER		0
#define	MY_QUIT		-42

typedef struct  s_term
{
  char  *copy;
  char  *prompt;
  char  *str;
  char  *buff;
  char  *str_cr;
  int   flag_cr;
  int   flag;
  int   pos;
  int   s_pr;
  int   col;
  int   row;
}       t_term;

char    *manage_new_copy_term(t_term *ptr);
int     determ_flag(char *buff);
int     manage_buff(t_term *ptr);
int     replace_in_hist(t_term *ptr, char **hist);
void    manage_next_word(t_term *ptr);
void    go_begin(t_term *ptr);
void    aff_copy(t_term *ptr);
void    just_aff(t_term *ptr);
void    delete_aff(t_term *ptr);
void    move_left(t_term *ptr);
void    move_left_or_right(t_term *ptr);
void    move_right(t_term *ptr);
void    manage_copy_and_paste(t_term *ptr);
void    manage_clear_beg_end(t_term *ptr);
void    instance_paste(t_term *ptr);
void    add_into_struct(char *cpy, t_term *ptr);
void    my_putstr_spe(char *str, t_term *ptr, int i);
void    xfree(void *ptr);

#endif
