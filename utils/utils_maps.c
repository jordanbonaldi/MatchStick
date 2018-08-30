/*
** utils_maps.c for matchstick
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Wed Feb 15 22:21:30 2017 Jordan Bonaldi
** Last update	Thu Feb 23 15:44:33 2017 Jordan Bonaldi
*/

#include "project.h"

void					create_map(t_game *game)
{
  int					i;

  i = 0;
  if (!(game->map = malloc(sizeof(t_string *) * (game->line + 3))))
    return;
  *game->map = header_footer(game->line);
  game->map[game->line + 1] = header_footer(game->line);
  while (++i < game->line + 1)
    game->map[i] = fill_stick(i - 1, game->line);
  game->map[++i] = NULL;
}

t_game		*init_game(int line, int max)
{
  t_game	*game;

  if (!(game = malloc(sizeof(*game))))
    return (game);
  game->win = false;
  game->returnvalue = 0;
  game->end = false;
  game->top = get_top_stick(line);
  game->line = line;
  game->max = max;
  create_map(game);
  return (game);
}

int			calc(t_game *game)
{
  return (game->map[game->cline->toInt(game->cline)]->
      contains(game->map[game->cline->toInt(game->cline)], '|') >= game->max ?
      game->max : game->map[game->cline->toInt(game->cline)]->
      contains(game->map[game->cline->toInt(game->cline)], '|'));
}

void		draw_map(t_game *game)
{
  int		i;

  i = -1;
  while (++i < game->line + 2)
    my_printf("%s\n", game->map[i]->str);
}
