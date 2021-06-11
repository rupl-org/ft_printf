#include "ft_printf.h"

static char	*ft_processing_c(char c)
{
	char *rtn;

	rtn = malloc(sizeof(char) * 2);
	rtn[0] = c;
	rtn[1] = '\0';
	return (rtn);
}

static void	ft_magic_c(char *str, t_data *data)
{
	if (!data->minus)
	{
		while (data->len-- > 1)
			data->counter += write(1, " ", 1);
	}
	data->counter += write(1, str, 1);
	if (data->minus)
	{
		while (data->len-- > 1)
			data->counter += write(1, " ", 1);
	}
	free(str);
}

void	ft_conversion_c(va_list arg, const char *format, t_data *data)
{
	if (format[data->index] == 'c')
	{
		if (!data->plus && !data->hash && !data->zero && data->precision ==
		-1 && !data->ll && !data->h && !data->hh)
			ft_magic_c(ft_processing_c(va_arg(arg, long int)), data);
		else
			data->error = 1;
	}
}
