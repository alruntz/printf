/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 18:02:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:33:05 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../libft/libft.h"
#include <unistd.h>

void    ft_putnbr_base(int nb, char *base)
{
	char base_len;
	int i;
	int nbr_final[100];

	i = 0;
	base_len = ft_strlen(base);
	if (nb < 0 && base_len == 10)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while(nb)
	{
		nbr_final[i] = nb % base_len;
		nb = nb / base_len;
		i++;
	}
	while(--i >= 0)
		write(1, &base[nbr_final[i]], 1);
}
