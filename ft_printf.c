#include "ft_printf.h"

void print_data(t_data *data)
{
	printf("\n**********\n");
	printf("***minus - %d\n", data->minus);
	printf("***plus - %d\n", data->plus);
	printf("***hash - %d\n", data->hash);
	printf("***zero - %d\n", data->zero);
	printf("***l - %d\n", data->l);
	printf("***ll - %d\n", data->ll);
	printf("***h - %d\n", data->h);
	printf("***hh - %d\n", data->hh);
	printf("***len - %d\n", data->len);
	printf("***precision - %d\n", data->precision);
	printf("***counter - %ld\n", data->counter);
	printf("***index - %ld\n", data->index);
//	printf("###ARG - %s\n", str);
	printf("**********\n\n");
}
static void	ft_reset_flags(t_data *data)
{
	data->error = 0;
	data->minus = 0;
	data->plus = 0;
	data->hash = 0;
	data->zero = 0;
	data->len = 0;
	data->precision = -1;
	data->l = 0;
	data->ll = 0;
	data->h = 0;
	data->hh = 0;
}

static int	ft_lets_go(va_list arg, char *format, t_data *data)
{
	while (format[data->index] && !data->error)
	{
		if (format[data->index] == '%')
		{
			ft_reset_flags(data);
			data->index++;
			ft_parsing(arg, (char *)format, data);
		}
		else
		{
			write(1, &format[data->index], 1);
			data->counter++;
		}
		data->index++;
	}
	if (data->error)
		return (-1);
	else
		return (data->counter);
}


int	ft_printf(const char *format, ...)
{
	int		rtn;
	t_data	*data;
	va_list	arg;

	va_start(arg, format);
	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	data->counter = 0;
	data->index = 0;
	rtn = ft_lets_go(arg, (char *)format, data);
	va_end(arg);
	free(data);
	return (rtn);
}
//
