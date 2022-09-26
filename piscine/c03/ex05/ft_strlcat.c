/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:00:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/01 23:39:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*p)
		p++;
	return (p - str);
}

unsigned int	ft_strnlen(char *str, unsigned int maxlen)
{
	char	*p;

	p = str;
	while (*p && maxlen--)
		p++;
	return (p - str);
}

void	*ft_memcpy(void *dest, const void *source, unsigned int num)
{
	char	*cp;
	char	*sp;

	cp = (char *) dest;
	sp = (char *) source;
	while (num--)
		*cp++ = *sp++;
	return (dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	srclen;
	unsigned int	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dest, size);
	if (dstlen == size)
		return (size + srclen);
	if (srclen < size - dstlen)
		ft_memcpy(dest + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + dstlen, src, size - dstlen - 1);
		dest[dstlen + size - dstlen - 1] = '\0';
	}
	return (dstlen + srclen);
}
