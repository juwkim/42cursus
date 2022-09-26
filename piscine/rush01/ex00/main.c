/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:08:10 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/24 22:30:23 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		check_valid_input(char *str);
int		check_valid_allocate(char *mem);
void	ft_split(char *str, char *input);
void	ft_init_map(char *map);
int		ft_tracking(int depth, char *map, char *input);

int	main(int argc, char **argv)
{
	char	*str;
	char	*input;
	char	*map;

	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	str = argv[1];
	if (!check_valid_input(str))
		return (0);
	input = (char *)malloc(sizeof(char) * 16 + 1);
	if (!check_valid_allocate(input))
		return (0);
	ft_split(str, input);
	map = (char *)malloc(sizeof(char) * 16 + 1);
	if (!check_valid_allocate(map))
		return (0);
	ft_init_map(map);
	if (ft_tracking(0, map, input) == 0)
		write (1, "Error\n", 6);
	free(input);
	free(map);
	return (0);
}
