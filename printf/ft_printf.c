/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 16:06:11 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 19:13:06 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "./../libft/libft.h"

char g_identifiers[] = "sdioxpcf\0";
char g_flags[] = " #0+-";

char *(*g_prints_identifiers[])(va_list) = {&get_string, &get_decimal, get_decimal, &get_octal, &get_hexa, &get_pointer, &get_char, get_float, 0};


void	print_spaces(char *str_flag, int n, int *ret)
{
	int  i;
	int nb;
	char c;

	i = 0;
	nb = 0;
	c = ' ';
	while (str_flag[i])
	{
		if (str_flag[i] == '0')
			c = '0';
		if (str_flag[i] >= '1' && str_flag[i] <= '9')
		{
		 	nb = atoi(str_flag + i) - n;
			break;
		}
		i++;
	}
	while (nb)
	{
		write(1, &c, 1);
		*ret = *ret + 1;
		nb--;
	}
}


int	str_contain(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	print_plus(char *str_flag, int n, int *ret)
{
	if (str_contain(str_flag, '+') && n > 0)
	{
		*ret = *ret + 1;
		write(1, "+", 1);
	}
}

void	print_dieze(char *str_flag, int *ret)
{
	if (str_contain(str_flag, '#'))
	{
		if (str_flag[strlen(str_flag)] == 'o')
		{
			*ret = *ret + 1;
			write(1, "0", 1);
		}
		if (str_flag[strlen(str_flag)] == 'x' 
			|| str_flag[strlen(str_flag)] == 'X')
		{
			*ret = *ret + 2;
			write(1, "0x", 2);
		}
	}
}

void	check_flags(char *str_flag, va_list va, int *i, int *ret)
{
	int j;
	int n;
	char *str_convert;
	
	n = 0;
	n = (str_contain(str_flag, '+')) ? 1 : 0;
	printf("=>%d<=", *i);
	while (str_flag[*i])
	{
		j = 0;
		while (g_identifiers[j])
		{
			if (g_identifiers[j] == str_flag[*i])
				str_convert = g_prints_identifiers[j](va);
			j++;
		}
		*i = *i + 1;
	}
	*ret = *ret + ft_strlen(str_convert);
	n = (atoi(str_convert) > 0) ? n : 0;
	if (str_contain(str_flag, '-'))
	{
		print_plus(str_flag, atoi(str_convert), ret);	
		print_dieze(str_flag, ret);
		ft_putstr(str_convert);
	}
	print_spaces(str_flag, strlen(str_convert) + n, ret);
	if (!str_contain(str_flag, '-'))
	{
		print_plus(str_flag, atoi(str_convert), ret);
		print_dieze(str_flag, ret);
		ft_putstr(str_convert);
	}
}

char	*get_flags(char *str)
{
	int i;
	int j;
	int b;

	i = 0;
	while (str[i])
	{
		b = 0;
		j = 0;
		while (g_flags[j])
		{
			if (str[i] == g_flags[j])
			{
				b = 1;;
				break;
			}
			j++;
		}
		j = 0;
		while (g_identifiers[j])
		{
			if (str[i] == g_identifiers[j])
			{
				b = 0;
				break;
			}
			j++;
		}
		if (!b && (!(str[i] >= '0' && str[i] <= '9')))
			return (strndup(str, i + 1));    
		i++;
	}
	return (NULL);
}

int		ft_printf(const char *str, ...)
{
	int i;
	va_list va;
	int ret;

	i = 0;
	ret = 0;
	va_start(va , str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check_flags(get_flags((char *)str), va, &i, &ret);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			ret++;
			i++;
		}
	}
	return (ret);
}
