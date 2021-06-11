#include "ft_printf.h"

void ft_parsing_conversion(va_list arg, char *format, t_data *data)
{
	ft_conversion_c(arg, format, data);
//	if ((format[i] == 'd') || (format[i] == 'i') || (format[i] == 'u'))
//	{
//		if (flags->l)
//			make_magic(processing_diu(va_arg(ap, long)), flags);
//		else if (flags->ll)
//			make_magic(processing_diu(va_arg(ap, long long)), flags);
//		else if (flags->hh)
//			make_magic(processing_diu_hh(va_arg(ap, int)), flags);
//		else
//		make_magic(processing_diu(va_arg(ap, int)), flags);
//	}
//	if (format[i] == 'c')
//		make_magic(processing_c(ap), flags);
//	if (format[i] == 's')
//		make_magic(processing_s(ap), flags);
//	if (format[i] == 'x')
//		make_magic(processing_xX(ap), flags);
//	if (format[i] == 'X')
//		make_magic(capitalize(processing_xX(ap)), flags);
//	if (format[i] == 'p')
//		make_magic(processing_p(ap), flags);
//	if (format[i] == 'f')
//		make_magic(processing_f(va_arg(ap, double), flags->precision), flags);
//	if (format[i] == 'g')
//		make_magic(processing_g(va_arg(ap, double), flags->precision), flags);
//	if (format[i] == 'e')
//		make_magic(processing_e(va_arg(ap, double), flags->precision), flags);
}
