/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 03:01:24 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

#define PROMPT "EL SHELLO $ "
/*
static void	ft_choose_algo(t_msh *msh, char **env)
{
//	msh->pro = ft_space(msh->line);
//	ft_fill_struct(msh);
	if (!(ft_strncmp(msh->first->str, "pwd", 2)))
		ft_pwd(msh);
	else if (!(ft_strncmp(msh->first->str, "cd", 1)))
		ft_exc_cd(msh, env);
	else if (!(ft_strncmp(msh->first->str, "env", 2)))
		ft_exc_env(msh);
	else if (!(ft_strncmp(msh->first->str, "unset", 4)))
		ft_exc_unset(msh, 0, 0);
//	else if (!(ft_strncmp(msh->first->str, "export", 5)))
//		ft_exc_export(msh);
	else
		write(1, "command not found\n", 18);
}
*/

int	ft_count_lst(t_lst *lst)
{
	int i;

	i = 0;
	while(lst->next)
	{
		printf("%s\n", lst->str[0]);
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	printf("alors str[%d] = %s\n", i, str[i]);
	while (str[i])
	{
		printf("alors str[%d] = %s\n", i, str[i]);
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	printf("alors str[%d] = %s\n", i, str[i]);
	free(str[i]);
	str[i] = NULL;
}

void	ft_free_lst(t_msh *msh)
{
	int	i;
	t_lst	*cpy;

	i = ft_count_lst(msh->first);
	printf("%d\n", i);
	while (i >= 0)
	{	
		printf("dqsdqsdqsd= %s\n", msh->first->str[0]);
		cpy = msh->first->next;
		if (msh->first->str[0] != NULL)
		{
			printf("free double ok\n");
			ft_free_double(msh->first->str);
			printf("dqsdqsdqsd= %s\n", msh->first->str[0]);
			printf("free double ok\n");
			if (msh->first->str == NULL)
			{
				printf("ici?\n");
				free(msh->first->str);
			}
		}
		if (cpy)
		{
			printf("ici ?\n");
			msh->first = cpy;
		}
		i--;
	}
//	printf("%d\n", ft_count_lst(msh->first));
	printf("free first\n");
	free(msh->first);
}

int	main(int ac, char **av, char **env)
{
	t_msh	msh;
	int		i;

	(void)ac;
	(void)av;
	i = 0;
	ft_fill_env(&msh, env);
	while (1)
	{
		msh.line = readline(PROMPT);
		ft_fill_struct(&msh);
		add_history(msh.line);
		/*
		if (!parsing(&msh, env))
			printf("ERROOOOOOOOOOR\n");
		else
			ft_choose_algo(&msh, env);
			*/
		while (msh.first)
		{
			while (msh.first->str[i])
			{
				printf("str[%d] = %s\n", i, msh.first->str[i]);
				i++;
			}
			i = 0;
			msh.first = msh.first->next;
		}
	//	ft_free_lst(&msh);
	}
	return (0);
}
