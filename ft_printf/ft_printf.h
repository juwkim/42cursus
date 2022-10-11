#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

typedef enum e_option
{
	NONE	= 0,
	FOUND	= 1 << 0,
	BLANK	= 1 << 1,
	PLUS	= 1 << 2,
	MINUS	= 1 << 3,
	ZERO	= 1 << 4,
	PREC	= 1 << 5
}			t_option;

typedef struct s_token
{
	char		*in;
	char		*out;
	char		type;
	int			width;
	int			precision;
	t_option	opt;
}				t_token;

int		ft_printf(const char *format, ...);
#endif
