#include "built.h"
/*
char	*is_space(char *c)
{
	int	i;

	i = 0;
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

int	is_pipe(char c)
{
	if (c == '|' || c == ';')
		return (1);
	return (0);
}
*/

int	count_quote(char *s, int max)
{
	int	i;
	int	quote;

	quote = 0;
	i = 0;
	while (s[i] && i < max)
	{
		if (s[i] == '\'' || s[i] == '\"')
			quote++;
		i++;
	}
	return (quote);
}

int	check_quote(char c, int quote, int *boa)
{

	if (c == '\"')
	{
		if (quote == 1)
		{
			*boa = 0;
			return (0);
		}
		if (quote == 0)
			return (1);
	}
	if (c == '\'')
	{
		if (quote == 2)
			return (0);
		if (quote == 0)
			return (2);
	}
	return (0);
}

int	parsing(t_msh *msh, char **env)
{
	(void)env;
	
	msh->pro = ft_space(msh->line);
	ft_fill_struct(msh);
//	printf("STR = %s\n", msh->first->str);
	return (0);
}
