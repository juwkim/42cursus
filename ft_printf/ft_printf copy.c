#include "ft_printf.h"
#include <stdio.h>
int ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

static int skip_atoi(const char **s)
{
	int i = 0;

	while (ft_isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return i;
}

#define ZEROPAD	1		/* pad zero */
#define SIGN	2		/* unsigned/signed long */
#define PLUS	4		/* show plus */
#define SPACE	8		/* space if plus */
#define LEFT	16		/* left justified */
#define SMALL	32		/* Must be 32 == 0x20 */
#define SPECIAL	64		/* 0x */
#define ADDRESS 128

#define __do_div(n, base) ({ \
int __res; \
__res = ((unsigned long) n) % (unsigned) base; \
n = ((unsigned long) n) / (unsigned) base; \
__res; })


void number(long num, int base, int field_width, int precision, int flags, int *printed)
{
	/* we are called base 8, 10 or 16, only, thus don't need "G..."  */
	static const char digits[16] = "0123456789ABCDEF"; /* "GHIJKLMNOPQRSTUVWXYZ"; */

	char tmp[66];
	char c, sign, locase;
	int i;
	/* locase = 0 or 0x20. ORing digits or letters 'locase'
	 * produces same digits or (maybe lowercased) letters */
	locase = (flags & SMALL);
	if (flags & LEFT)
		flags &= ~ZEROPAD;

	c = (flags & ZEROPAD) ? '0' : ' ';
	sign = 0;
	if (flags & SIGN) {
		if (num < 0) {
			sign = '-';
			num = -num;
			field_width--;
		} else if (flags & PLUS) {
			sign = '+';
			field_width--;
		} else if (flags & SPACE) {
			sign = ' ';
			field_width--;
		}
	}
	if (flags & SPECIAL + ADDRESS) field_width -= 2;
	i = 0;
	if (num == 0)
		tmp[i++] = '0';
	else
		while (num != 0)
			tmp[i++] = (digits[__do_div(num, base)] | locase);
	
	if (field_width < precision)
		field_width = precision;
	if (ZERO && !PREC)
		precision = field_width;
	if (MINUS)
		ft_memset(t->out, '0', t->precision);
		ft_memcpy(t->out + t->precision - copy_len, copy, copy_len);
	else
		ft_memset(t->out + t->width - t->precision, '0', t->precision);
		ft_memcpy(t->out + t->width - copy_len, copy, copy_len);

	if (i > precision)
		precision = i;
	field_width -= precision;
	if (!(flags & (ZEROPAD + LEFT)))
		while (field_width-- > 0)
			*printed += write(1, " ", 1);
	if (sign)
		*printed += write(1, &sign, 1);

	if ((flags & ADDRESS) || (!(i == 1 && tmp[0] == '0') && (flags & SPECIAL))) {
		if (locase)
			*printed += write(1, "0x", 2);
		else
			*printed += write(1, "0X", 2);
	}
	if (!(flags & LEFT))
		while (field_width-- > 0)
			*printed += write(1, &c, 1);
	while (i < precision--)
		*printed += write(1, "0", 1);
	while (i-- > 0)
		*printed += write(1, tmp + i, 1);

	while (field_width-- > 0)
		*printed += write(1, " ", 1);
}

int ft_vprintf(const char *fmt, va_list args)
{
	int len;
	unsigned long num;
	int i, base;
	const char *s;

	int flags;		/* flags to number() */

	int field_width;	/* width of output field */
	int precision;		/* min. # of digits for integers; max
				   number of chars for from string */
    int printed;
	char c;

    while(*fmt)
	{
		if (*fmt != '%') {
			printed += write(1, fmt++, 1);
			continue;
		}

		/* process flags */
		flags = 0;
		while (1)
		{
			fmt++;		/* this also skips first '%' */
			if (*fmt == '-') flags |= LEFT;
			else if (*fmt == '+') flags |= PLUS;
			else if (*fmt == ' ') flags |= SPACE;
			else if (*fmt == '#') flags |= SPECIAL;
			else if (*fmt == '0') flags |= ZEROPAD;
			else break;
		}

		/* get field width */
		field_width = -1;
		if (ft_isdigit(*fmt))
			field_width = skip_atoi(&fmt);

		/* get the precision */
		precision = -1;
		if (*fmt == '.') {
			fmt++;
			if (ft_isdigit(*fmt))
				precision = skip_atoi(&fmt);
			if (precision < 0)
				precision = 0;
		}

		/* default base */
		base = 10;

		if (*fmt == 'c' || *fmt == '%')
		{
			if (!(flags & LEFT))
				while (--field_width > 0)
					printed += write(1, " ", 1);
			if (*fmt == 'c')
				c = va_arg(args, int);
			else
				c = '%';
			printed += write(1, &c, 1);
			while (--field_width > 0)
				printed += write(1, " ", 1);
			fmt++;
			continue;
		}
		else if (*fmt == 's')
		{
			s = va_arg(args, char *);
			if (s == NULL)
				s = "(null)";
			
			len = strnlen(s, precision);

			if (!(flags & LEFT))
				while (len < field_width--)
					printed += write(1, " ", 1);
			i = 0;
			while (i++ < len)
				printed += write(1, s++, 1);
			while (len < field_width--)
				printed += write(1, " ", 1);

			fmt++;
			continue;
		}
		else if (*fmt == 'p')
		{
			flags |= SMALL + ADDRESS;
			number((unsigned long)va_arg(args, void *), 16, field_width, precision, flags, &printed);
			fmt++;
			continue;
		}
		else if (*fmt == 'x')
		{
			/* integer number formats - set up the flags and "break" */
			flags |= SMALL;
			base = 16;
		}
		else if (*fmt == 'X')
			base = 16;
		else if (*fmt == 'd' || *fmt == 'i')
			flags |= SIGN;
		fmt++;

		if (flags & SIGN)
			num = va_arg(args, int);
		else
			num = va_arg(args, unsigned int);
		number(num, base, field_width, precision, flags, &printed);
	}
	return printed;
}

int ft_printf(const char *fmt, ...)
{
	va_list args;
	int printed;

	va_start(args, fmt);
	printed = ft_vprintf(fmt, args);
	va_end(args);
	return (printed);
}