#include "ft_printf.h"

static char	*ft_processing_s(char *str, t_data *data)
{
	char	*rtn;
	long		i;

	rtn = malloc(sizeof(char) * (ft_strlen(str)));
	if (!rtn)
	{
		data->error = 1;
		return (0);
	}
	i = 0;
	while (str[i])
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

static void	ft_write_str(char *str, t_data *data)
{
	if (ft_strlen(str) > data->precision)
			data->counter += write(1, str, data->precision);
	else
			data->counter += write(1, str, ft_strlen(str));
}

static void	ft_magic_s(char *str, t_data *data)
{
	if (data->len < 0)
	{
		data->minus = 1;
		data->len *= -1;
	}
	if (!data->minus)
	{
		while (data->len-- > data->precision)
			data->counter += write(1, " ", 1);
	}
	ft_write_str(str, data);
	if (data->minus)
	{
		while (data->len-- > data->precision)
			data->counter += write(1, " ", 1);
	}
	ft_write_str(str, data);
	free(str);
}

void	ft_conversion_s(va_list arg, const char *format, t_data *data)
{
	if (format[data->index] == 's')
	{
		if (!data->plus && !data->hash && !data->zero && !data->l && !data->ll
		&& !data->h && !data->hh)
			ft_magic_s(ft_processing_s(va_arg(arg, char *), data), data);
		else
			data->error = 1;
	}
}
