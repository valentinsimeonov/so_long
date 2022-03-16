/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:50:16 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/16 21:40:48 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_line(t_list **lines)
{
	int		i;

	i = 0;
	while ((*lines)->line[i] != '\0' && (*lines)->line[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen_line_1(char *s)
{
	int		i;

	i = 0;
	while ((s[i] != '\0' && s[i] != '\n'))
		i++;
	return (i);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	*str;
// 	int		len;

// 	i = 0;
// 	str = (char *)s;
// 	len = ft_strlen(s);
// 	while (i <= len)
// 	{
// 		if (*(str + i) == c)
// 			return (str + i);
// 		i++;
// 	}
// 	if (c == 0)
// 		return (str + len + 1);
// 	return (NULL);
// }

int	ft_strchr_first_line(const char *s, char c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i < len)
	{
		if ((i == len - 1)  && str[i] != '\n')
			return (0);
		else if ((i < len -1) && str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strchr_second_line(const char *s, char c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i < len)
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || (*(str + i) == ' '))
	{
		i++;
	}
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((*(str + i) >= 48 && *(str + i) <= 57))
	{
		num = (num * 10) + (*(str + i) - '0');
		i++;
	}
	return (num * sign);
}

static int	ft_count_int_lenght(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*temp;
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count_int_lenght(n);
	temp = ft_calloc(sizeof(char), (len + 1));
	if (!temp)
		return (NULL);
	str = temp;
	if (n < 0)
	{
		*temp = '-';
		n *= -1;
	}
	temp += len;
	while (n >= 10)
	{
		temp--;
		*temp = ((n % 10) + '0');
		n /= 10;
	}
	*(--temp) = (n % 10) + '0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;
	int		i;

	len = 0;
	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < len)
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*current;
// 	t_list	*temp;

// 	current = *lst;
// 	while (current != NULL && del)
// 	{
// 		temp = current->next;
// 		del(current->content);
// 		free(current);
// 		current = temp;
// 	}
// 	*lst = NULL;
// }

