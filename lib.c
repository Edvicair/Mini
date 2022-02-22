/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 21:34:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0 && s1[i] == s2[i])
	{
		i++;
		return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
	}
	while (s1[i] && s2[i] && s1[i] == s2[i] && i <= n)
		i++;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ret)
		return (NULL);
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
