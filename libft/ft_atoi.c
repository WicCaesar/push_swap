/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:20:07 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/13 16:36:24 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts a numeric character in a string to an integer by subtracting 0 from
// the corresponding ASCII decimal value to get a valid numerical value, then
// multiplies by 10 to calculate the following digit. It skips spaces and tabs.
int	ft_atoi(const char *str)
{
	int		i;
	int		operator;
	long	num;

	i = 0;
	num = 0;
	operator = 1;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				operator = -operator;
			i++;
		}
		while (str[i] != '\0' && ft_isdigit(str[i]))
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		return (num * operator);
	}
	return (0);
}

long long	ft_atolli(char *str)
{
	int					i;
	int					operator;
	unsigned long long	num;

	i = 0;
	num = 0;
	operator = 1;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				operator = -operator;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		return (num * operator);
	}
	return (0);
}
