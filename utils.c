/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:22 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/21 10:03:44 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strdup(char *src);
void	ft_putnbr(int n);
void	ft_print_moves(int n);
int		ft_countnbr(long n);
char	*ft_itoa(int n);

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == 0)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putnbr(int n)
{
	char	c;

	c = n % 10 + '0';
	if (n > 9)
	{
		n = n / 10;
		ft_putnbr(n);
	}
	write (1, &c, 1);
}

void	ft_print_moves(int n)
{
	write(1, "Moves= ", 7);
	ft_putnbr(n);
	write(1, "\n", 1);
}

int	ft_countnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = ft_countnbr(nb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[i] = '\0';
	i = i - 1;
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		i--;
		nb = nb / 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
