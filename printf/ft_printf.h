#include <stdarg.h>

# define BASE_16 "0123456789abcdef"
# define BASE_10 "0123456789"
# define BASE_8 "012345678"
# define BASE_2 "01"

void    ft_putnbr_base(int nb, char *base);
char	*get_string(va_list va);
char	*get_decimal(va_list va);
char	*get_octal(va_list va);
char	*get_hexa(va_list va);
char	*get_pointer(va_list va);
char	*get_char(va_list va);
char	*get_float(va_list va);
char	*ft_itoa_base(int value, int base);
int		ft_printf(const char *str, ...);
