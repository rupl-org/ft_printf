#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

#include <stdio.h>

typedef struct	s_data
{
	long 	counter;
	long 	index;
	short	error;
	short	minus;
	short	plus;
	short	hash;
	short	zero;
	int		len;
	int		precision;
	short	l;
	short	ll;
	short	h;
	short	hh;
}			t_data;

//utilities
short	ft_is_conversion (char chr);
void	ft_read_number(char *format, t_data *data, int *num);

void	ft_conversion_c(va_list arg, const char *format, t_data *data);

void	ft_parsing_conversion(va_list arg, char *format, t_data *data);
void 	ft_parsing(va_list ap, char *format, t_data *data);
int		ft_printf(const char *format, ...);
#endif
