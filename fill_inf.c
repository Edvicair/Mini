/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 03:54:46 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

char	*ft_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (ft_strdup(&line[i]));
}

static t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

static void	ft_lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst *last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

void	ft_fill_struct(t_msh *msh)
{
	int 	i;
	t_lst *cpy;
	t_lst *add;

	i = 0;
	msh->pro = ft_space(msh->line);
	msh->s = ft_strtok(msh->pro);
	cpy = malloc(sizeof(t_lst));
	if (!cpy)
		return;
	cpy->str = split_space(msh->s[i]);
	cpy->next = NULL;
	i++;
	while (msh->s[i])
	{
		add = malloc(sizeof(t_lst));
		if (!add)
			return;
	//	printf("MSH[%d] = %s\n", msh->s[i]);
		if (msh->s[i][0])
		{
			add->str = split_space(msh->s[i]);
			add->next = NULL;
			i++;
			ft_lstadd_back(&cpy, add);
		}
		else
			i++;
	}
	msh->first = cpy;
}

void	ft_fill_env(t_msh *msh, char **env)
{
	int	line;

	line = 0;
	while (env[line])
		line++;
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
