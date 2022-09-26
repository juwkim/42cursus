/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:46:36 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/24 18:52:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*p;
	int		cnt;

	p = src;
	cnt = 0;
	while (*p++)
		cnt++;
	if (size)
	{
		while (*src && --size)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (cnt);
}
