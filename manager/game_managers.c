/*
** game_managers.c for CPE_2016_matchstick
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Tue Feb 21 23:49:40 2017 Jordan Bonaldi
** Last update	Wed Feb 22 18:59:57 2017 Jordan Bonaldi
*/

# include "project.h"

boolean		is_valid_matches(t_game *game)
{
  if (!game->cnb->num(game->cnb))
    return (my_printf("Error: invalid input (positive number expected)\n"));
  if (game->cnb->toInt(game->cnb) > game->max)
    return (my_printf("Error: you cannot remove more than %d "
      "matches per turn\n", game->max));
  if (game->cnb->toInt(game->cnb) >
      game->map[game->cline->toInt(game->cline)]
      ->contains(game->map[game->cline->toInt(game->cline)], '|'))
    return (my_printf("Error: not enough matches on this line\n"));
  if (!game->cnb->toInt(game->cnb))
    return (my_printf("Error: you have to remove at least one match\n"));
  return (true);
}

boolean		is_valid_line(t_game *game)
{
  if (!game->cline->num(game->cline))
    return (my_printf("Error: invalid input (positive number expected)\n"));
  if (game->cline->toInt(game->cline) > game->line ||
        !game->cline->toInt(game->cline) ||
          !game->map[game->cline->toInt(game->cline)]
            ->contains(game->map[game->cline->toInt(game->cline)], '|'))
    return (my_printf("Error: this line is out of range\n"));
  return (true);
}

boolean	check_win(t_game *game, int winner)
{
  int		i;
  int		j;

  j = -1;
  while (game->map[++j] && (i = -1))
    while (game->map[j]->str[++i])
      if (game->map[j]->str[i] == '|')
        return (false);
  if (winner && (game->returnvalue = 2))
    my_printf("You lost, too bad...\n");
  else if ((game->returnvalue = 1))
    my_printf("I lost... snif... but I’ll get you next time!!\n");
  game->end = true;
  return (true);
}

void		remove_matches(t_game *game)
{
  boolean pipe;
  int		line;
  int		match;
  int		i;

  i = -1;
  pipe = false;
  match = 1 + game->cnb->toInt(game->cnb);
  line = game->cline->toInt(game->cline);
  while (game->map[line]->str[++i])
    {
      if (game->map[line]->str[i] == '|' && (pipe = true)) {}
      if (pipe && game->map[line]->str[i] == '|' &&
          (game->map[line]->str[i + 1] == ' ' ||
            game->map[line]->str[i + 1] == '*'))
        break;
    }
  while (--match > 0)
    game->map[line]->str[i--] = ' ';
}
