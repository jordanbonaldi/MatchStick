/*
** utils_coeff.c for matchstick
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Wed Feb 15 22:22:08 2017 Jordan Bonaldi
** Last update	Thu Feb 23 15:26:03 2017 Jordan Bonaldi
*/

# include "project.h"

static t_string		*empty_map(int line)
{
  int				i;
  t_string	*str;

  i = -1;
  str = init_string("*");
  while (++i < get_top_stick(line))
    str->recreate(str, my_strcatc(str->str, ' '));
  str->recreate(str, my_strcatc(str->str, '*'));
  return (str);
}

t_string		*fill_stick(int lineno, int line)
{
  t_string	*empty;
  int				i;

  empty = empty_map(line);
  line -= lineno;
  i = line - 1;
  while (++i < empty->size - (line))
    empty->str[i] = '|';
  return (empty);
}

t_string		*header_footer(int line)
{
  int				i;
  t_string	*str;

  i = -1;
  str = init_string("*");
  while (++i < get_top_stick(line) + 1)
    str->recreate(str, my_strcatc(str->str, '*'));
  return (str);
}

int		get_random(int min, int max)
{
  min < max ? ++max : ++min;
  return ((rand() % (max - min)) + min);
}

int		get_top_stick(int a)
{
  return (a > 0 ? get_top_stick(--a) + 2 : -1);
}
