/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:24:10 by cnascime          #+#    #+#             */
/*   Updated: 2023/02/03 12:08:46 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	ft_isnumeric(const char *str)
{
	int			length;
	static int	i;
	static int	operator_count;
	static int	separator_count;

	length = ft_strlen(str);
	while (i < length)
	{
		if (str[i] == '.' || str[i] == ',')
		{
			separator_count++;
			if (separator_count > 1)
				return (0);
		}
		if (str[i] == '-' || str[i] == '+')
		{
			operator_count++;
			if (operator_count > 1 || (i != 0 && str[i - 1] != 'e'))
				return (0);
		}
		else if (!ft_isdigit(str[i]) && str[i] != 'e')
			return (0);
		i++;
	}
	return (1);
}
