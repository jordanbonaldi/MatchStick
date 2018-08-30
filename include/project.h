/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update	Thu Feb 23 15:45:03 2017 Jordan Bonaldi
*/

#ifndef H_CHECK
# define H_CHECK

# include <time.h>
# include "lib.h"

typedef struct		s_game
{
  boolean					win;
  int							top;
  int							line;
  int							max;
  int						  returnvalue;
  boolean					end;
  t_string				*cline;
  t_string				*cnb;
  t_string				**map;
}									t_game;

int				calc(t_game *);
boolean		check_win(t_game *game, int);
boolean		is_valid_line(t_game *);
boolean   is_valid_matches(t_game *);
void			remove_matches(t_game *);
void			handle_game(t_game *);
t_game		*init_game(int, int);
t_string	*fill_stick(int, int);
t_string	*header_footer(int);
int				get_top_stick(int);
int				get_random(int, int);
void			draw_map(t_game *);

#endif
