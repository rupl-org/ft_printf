#include "ft_printf.h"

short	ft_is_conversion (char chr)
{
	int		i;
	char	*conversions;

	i = 0;
	conversions = "cspdiuxXnfge\0";
	while (conversions[i])
	{
		if (chr == conversions[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_read_number(char *format, t_data *data, int *num)
{
	while (format[data->index] >= '0' && format[data->index] <= '9')
	{
		*num *= 10;
		*num += format[data->index] - '0';
		data->index++;
	}
	data->index--;
}

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

short	digits_in_number(long long num, short base)
{
	short	i;

	i = 0;
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}


char	*capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
