/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 03:01:48 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_msh
{
	char			*line;
	char			*pro;
	char			*last_pwd;
	char			**s;
	char			**env;
	struct s_lst	*first;
}			t_msh;

typedef struct s_lst
{
	char			**str;
//	char			**arg;
	struct s_lst	*next;
}				t_lst;

int		ft_strlen(char *s);
int		ft_strncmp(char const *s1, char const *s2, size_t n);

char	*ft_strdup(char *s);
char	*ft_space(char *line);

void	ft_pwd(t_msh *msh);
void	ft_print(t_msh *msh);
void	ft_exc_env(t_msh *msh);
void	ft_lst_back(t_msh *msh);
void	ft_exc_unset(t_msh *msh, int i, int verif);
void	ft_exc_cd(t_msh *msh, char **env);
void	ft_fill_env(t_msh *msh, char **env);
// PARSING
void	ft_fill_struct(t_msh *msh);
void	ft_lst_first(t_msh *msh);
int	parsing(t_msh *msg, char **env);
int	count_quote(char *s, int max);
int	check_quote(char c, int quote, int *boa);
char	**ft_strtok(char *str);
char	*ft_strdup_bis(char **str, int max);
char	**split_space(char *str);

#endif
