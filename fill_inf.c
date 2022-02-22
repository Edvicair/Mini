/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 21:34:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

char	*ft_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (&line[i]);
}

void	ft_fill_struct(t_msh *msh)
{
	int i;
	int j;
	t_lst *cpy;

	i = 0;
	j = 0;
	msh->pro = ft_space(msh->line);
	msh->s = ft_strtok(msh->pro);
	msh->first = malloc(sizeof(t_lst));
	if (!msh->first)
		return;
	cpy = msh->first;
	while (msh->s[i])
	{
		cpy->str = split_space(msh->s[i]);
		cpy = cpy->next;
		i++;
	}
	cpy->next = NULL;
}

void	ft_fill_env(t_msh *msh, char **env)
{
	int	line;

	line = 0;
	while (env[line])
		line++;
	msh->env = (char **)malloc(sizeof(char *) * line + 1);
	if (!msh->env)
		return ;
	line = 0;
	while (env[line])
	{
		msh->env[line] = ft_strdup(env[line]);
		line++;
	}
	msh->env[line] = NULL;
}
