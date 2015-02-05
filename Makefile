##
## Makefile for sh in /home/rossi_t//random/projets/42sh
## 
## Made by tom rossi
## Login   <rossi_t@epitech.net>
## 
## Started on  Thu Apr 26 17:40:29 2012 tom rossi
## Last update Sat May 19 13:39:02 2012 tom rossi
##

NAME	= fgosh

RM	= rm -f

CC	= gcc

CFLAGS	= -I./includes/ -ltermcap -L. -g -Wall

DIR_PROJ	= ./sources/

DIR_HIST	= ./$(DIR_PROJ)history/

DIR_CALC	= ./$(DIR_PROJ)calc/

DIR_ENV		= ./$(DIR_PROJ)env/

DIR_EXECUTION	= ./$(DIR_PROJ)execution/

DIR_TERMCAP	= ./$(DIR_PROJ)termcap/

DIR_AUTO	= ./$(DIR_TERMCAP)autocompletion/

DIR_TOKEN	= ./$(DIR_PROJ)token/

DIR_ERROR	= ./$(DIR_PROJ)error/

DIR_TREE	= ./$(DIR_PROJ)tree/

DIR_GLOB	= ./$(DIR_PROJ)glob/

DIR_UTILS	= ./$(DIR_PROJ)utils/

DIR_ALIAS_M	= ./$(DIR_PROJ)alias/manage_list/

DIR_ALIAS_R	= ./$(DIR_PROJ)alias/replace_alias/

SRC		= ./$(DIR_PROJ)main.c \
		./$(DIR_PROJ)free.c \
		./$(DIR_PROJ)action.c

SRC_HIST        = $(DIR_HIST)add_in_history.c \
                $(DIR_HIST)aff_history.c \
                $(DIR_HIST)recup_file.c \
                $(DIR_HIST)recup_hist_tab.c \
		$(DIR_HIST)replace_in_hist.c \
		$(DIR_HIST)add_in_file.c \

SRC_GLOB	= $(DIR_GLOB)glob_sub.c \
		 $(DIR_GLOB)my_glob.c \

SRC_ALIAS	= $(DIR_ALIAS_M)alias.c \
		 $(DIR_ALIAS_M)error_manage.c \
		 $(DIR_ALIAS_M)unalias.c \
		 $(DIR_ALIAS_M)verif_add_alias.c \
		 $(DIR_ALIAS_M)my_str_to_wordtab_alias.c \
		 $(DIR_ALIAS_M)add_alias.c \
		 $(DIR_ALIAS_M)display_alias.c \
		 $(DIR_ALIAS_M)concat_arg_alias.c \
		 $(DIR_ALIAS_M)get_alias_name.c \
		 $(DIR_ALIAS_M)my_show_alias.c \
		 $(DIR_ALIAS_M)list_alias.c \
		 $(DIR_ALIAS_R)modif_wordtab_alias.c \
		 $(DIR_ALIAS_R)my_wordtab.c \
		 $(DIR_ALIAS_R)replace_alias.c \
		 $(DIR_ALIAS_R)copy_alias.c

SRC_CALC	= $(DIR_CALC)bin.c \
		$(DIR_CALC)bin_cmd_path.c \
		$(DIR_CALC)fill_pipe.c \
		$(DIR_CALC)red_access.c \
		$(DIR_CALC)red_set.c
#		$(DIR_CALC)redirect.c

SRC_ENV		= $(DIR_ENV)recup_env.c \
		$(DIR_ENV)show_hist.c \
		$(DIR_ENV)prompt.c \
		$(DIR_ENV)tabenv.c

SRC_EXECUTION	= $(DIR_EXECUTION)status.c \
		$(DIR_EXECUTION)builtins.c \
		$(DIR_EXECUTION)cd.c \
		$(DIR_EXECUTION)display.c \
		$(DIR_EXECUTION)path.c \
		$(DIR_EXECUTION)pwd.c \
		$(DIR_EXECUTION)echo.c \
		$(DIR_EXECUTION)startenv.c \
		$(DIR_EXECUTION)setenv.c

SRC_TERMCAP     = $(DIR_TERMCAP)xfunc.c \
                $(DIR_TERMCAP)aff_copy.c \
                $(DIR_TERMCAP)epur_hist.c \
                $(DIR_TERMCAP)create_new.c \
                $(DIR_TERMCAP)delete_aff.c \
                $(DIR_TERMCAP)change_mode.c \
                $(DIR_TERMCAP)determ_flag.c \
                $(DIR_TERMCAP)instance_paste.c \
                $(DIR_TERMCAP)manage_aff.c \
                $(DIR_TERMCAP)mod_hist.c \
                $(DIR_TERMCAP)manage_clear_beg_end.c \
                $(DIR_TERMCAP)manage_buff.c \
                $(DIR_TERMCAP)manage_next_word.c \
                $(DIR_TERMCAP)manage_new_str.c \
                $(DIR_TERMCAP)manage_hist.c \
                $(DIR_TERMCAP)manage_copy_and_paste.c \
                $(DIR_TERMCAP)manage_tab.c \
                $(DIR_TERMCAP)move_aff.c \
                $(DIR_TERMCAP)new_hist.c \

SRC_AUTO	= $(DIR_AUTO)auto_complete.c \
		$(DIR_AUTO)auto_glob.c \
		$(DIR_AUTO)list.c \
                $(DIR_AUTO)auto_complete_match.c \
                $(DIR_AUTO)auto_complete_utils.c \
                $(DIR_AUTO)auto_complete_utils_2.c \
                $(DIR_AUTO)auto_complete_bin.c


SRC_TOKEN	= $(DIR_TOKEN)ref_tab.c \
		$(DIR_TOKEN)token.c \
		$(DIR_TOKEN)token_clean.c \
		$(DIR_TOKEN)token_utils.c \
		$(DIR_TOKEN)token_size.c \
		$(DIR_TOKEN)token_div.c \
		$(DIR_TOKEN)token_list.c \
		$(DIR_TOKEN)token_set.c \
		$(DIR_TOKEN)token_envsub.c \
		$(DIR_TOKEN)token_substitute.c \
		$(DIR_TOKEN)token_redirect.c

SRC_TREE	= $(DIR_TREE)tree_build.c \
                $(DIR_TREE)tree_explore.c \
                $(DIR_TREE)tree_kill.c \
                $(DIR_TREE)tree_fork.c \
                $(DIR_TREE)tree_pass.c \
                $(DIR_TREE)tree_group.c \
                $(DIR_TREE)tree_pipe.c \
                $(DIR_TREE)tree_free.c \
                $(DIR_TREE)tree_redirect.c \
                $(DIR_TREE)tree_set.c \
                $(DIR_TREE)tree_input.c \
                $(DIR_TREE)tree_utils.c \
                $(DIR_TREE)tree_env.c \
                $(DIR_TREE)tree_execute.c

SRC_ERROR	= $(DIR_ERROR)e_arguments.c \
		$(DIR_ERROR)e_or_and_pipe.c \
		$(DIR_ERROR)e_brackets.c \
		$(DIR_ERROR)e_brackets_others.c \
		$(DIR_ERROR)e_red_arguments.c \
		$(DIR_ERROR)e_redirects.c \
		$(DIR_ERROR)error_management.c \
		$(DIR_ERROR)pstr.c

SRC_UTILS	= $(DIR_UTILS)str.c \
		$(DIR_UTILS)my_strcmp.c \
		$(DIR_UTILS)my_strcat.c \
		$(DIR_UTILS)delete_space.c \
		$(DIR_UTILS)display.c \
		$(DIR_UTILS)is_valid.c \
		$(DIR_UTILS)my_getstr.c \
		$(DIR_UTILS)my_strdup.c \
		$(DIR_UTILS)my_putnbr.c \
		$(DIR_UTILS)my_strncmp.c \
		$(DIR_UTILS)quotes.c \
		$(DIR_UTILS)match2.c \
		$(DIR_UTILS)get_next_line.c \
		$(DIR_UTILS)my_pow.c \
		$(DIR_UTILS)match.c \
		$(DIR_UTILS)my_str_to_wordtab.c

OBJ		= $(SRC:.c=.o) \
		$(SRC_HIST:.c=.o) \
		$(SRC_CALC:.c=.o) \
		$(SRC_GLOB:.c=.o) \
		$(SRC_TOKEN:.c=.o) \
		$(SRC_TREE:.c=.o) \
		$(SRC_ERROR:.c=.o) \
		$(SRC_UTILS:.c=.o) \
		$(SRC_ENV:.c=.o) \
		$(SRC_TERMCAP:.c=.o) \
		$(SRC_AUTO:.c=.o) \
		$(SRC_EXECUTION:.c=.o) \
		$(SRC_ALIAS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 @$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
