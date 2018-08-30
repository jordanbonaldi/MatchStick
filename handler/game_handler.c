/*
** game_handler.c for CPE_2016_matchstick
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Tue Feb 21 23:49:04 2017 Jordan Bonaldi
** Last update	Thu Feb 23 15:59:11 2017 Jordan Bonaldi
*/

# include "project.h"

static void				get_player_choose(t_game *game)
{
  my_printf("\nYour turn:\n");
  game->cline = NULL;
  game->cnb = NULL;
  while (true)
    {
      my_printf("Line: ");
      if (!(game->cline = init_string(get_next_line(0))) &&
          (game->end = true))
        break;
      if (!is_valid_line(game))
        continue;
      my_printf("Matches: ");
      if (!(game->cnb = init_string(get_next_line(0))) &&
          (game->end = true))
        break;
      if (!is_valid_matches(game))
        continue;
      break;
    }
  if (game->cline && game->cnb)
    my_printf("Player removed %d match(es) from line %d\n",
      game->cline->toInt(game->cnb), game->cnb->toInt(game->cline));
}

void		ia(t_game *game)
{
  if (!my_printf("\nAI's turn...\n") && game->cline)
    game->cline->recreate(game->cline, "lol");
  else if ((game->cline = init_string("lol"))) {}
  while (true)
    {
      game->cline->toString(game->cline, get_random(1, game->line));
      if (!game->map[game->cline->toInt(game->cline)]->
        contains(game->map[game->cline->toInt(game->cline)], '|'))
        continue;
      break;
    }
  if (game->cnb)
    game->cnb->recreate(game->cnb, "lol");
  else if ((game->cnb = init_string("lol"))) {}
  if (game->map[game->cline->toInt(game->cline)]->
  contains(game->map[game->cline->toInt(game->cline)], '|') == 1)
    game->cnb->toString(game->cnb, 1);
  else
    game->cnb->toString(game->cnb, game->max == 1 ? 1 :
      get_random(1, calc(game)));
  remove_matches(game);
  my_printf("AI removed %d match(es) from line %d\n",
    game->cnb->toInt(game->cnb), game->cline->toInt(game->cline));
  draw_map(game);
  check_win(game, false);
}

void		handle_game(t_game *game)
{
  while (!game->end)
    {
      get_player_choose(game);
      if (game->end)
        break;
      if (game->cline || game->cnb)
        remove_matches(game);
      draw_map(game);
      if (check_win(game, true))
        return;
      ia(game);
    }
}
