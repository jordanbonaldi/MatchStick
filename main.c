/*
** main.c for main in matchstick
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update	Thu Feb 23 15:23:58 2017 Jordan Bonaldi
*/

#include "project.h"

int					main(int argc, char **argv)
{
  t_game		*game;

  srand(time(NULL));
  if (argc != 3 || !my_str_isnum(argv[1])
      || !my_str_isnum(argv[2]) || my_getnbr(argv[1]) > 100)
    return (84);
  game = init_game(my_getnbr(argv[1]), my_getnbr(argv[2]));
  draw_map(game);
  handle_game(game);
  return (game->returnvalue);
}
