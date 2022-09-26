/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:47:36 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/25 13:08:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start;
	char	c;

	start = dest;
	while (*dest)
		dest++;
	while (nb--)
	{
		c = *src;
		*dest++ = *src++;
		if (c == '\0')
			return (start);
	}
	*dest = '\0';
	return (start);
}
