/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 17:01:27 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:32:44 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../printf/ft_printf.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

char *get_string(va_list va)
{
	return ((char *)va_arg(va, char *));
}

char	*get_decimal(va_list va)
{
	return (ft_itoa_base((int)va_arg (va, int), 10));
}

char	*get_octal(va_list va)
{
	return(ft_itoa_base((int)va_arg (va,  int), 8));
}


char	*get_hexa(va_list va)
{
	return(ft_itoa_base((int)va_arg(va,  int), 16));
}

char	*get_float(va_list va)
{
	double param = (double)va_arg(va, double);
	int entier = floor(param);
	int decimale = param - entier;
	char *s1 = ft_itoa_base(entier, 10);
	char *s2 = ft_itoa_base(decimale, 10);
	char *ret = malloc(sizeof(char) *  15);
	ret = strcpy(ret, s1);
	ret = strcat(ret, s2);
	return(ret);
}

char	*get_pointer(va_list va)
{
	char *ret;
	char *param;
	
	param = ft_itoa_base((int)va_arg(va,  int), 16);
	if (!(ret = (char *)malloc(sizeof(char) * (6 + strlen(param)) + 1)))
		return (NULL);
	ret = strcpy(ret, "0x7fff");
	return (strcat(ret, param));
}

char	*get_char(va_list va)
{
	char *ret;
	if (!(ret = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	ret[0] = (char)va_arg(va, int) + '0';
	ret[1] = '\0';
	return (ret);
}
