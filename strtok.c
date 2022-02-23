#include "built.h"

int	is_sep(char *str, int i)
{
	if ((str[i] == '|' || str[i] == ';') && (count_quote(str, i) % 2) == 0)
		return (1);
	return (0);
}

char	*ft_strdup_bis(char **str, int max)
{
	int			i;
	int			j;
	char			*tmp;
	char			*s;

	i = 0;
	j = 0;
	printf("s = %c\n", str[0][i]);
	if (str[0][i] == '|')
	{
		i++;
		while (str[0][i] == ' ')
			i++;
		s = malloc(sizeof(char) * (max - i) + 1);
	}
	else
		s = malloc(sizeof(char) * (max + 1));
	if (!s)
		return (0);
	while (str[0][i] && i < max)
	{
		while (str[0][i] == '|')
		{
			i++;
			while (str[0][i] == ' ')
				i++;
		}
		if (str[0][i])
		{
			s[j] = str[0][i];
			i++;
			j++;
		}
	}
	s[j] = '\0';
	tmp = *str;
	printf("strdup_b s = %s\n", s);
	*str = ft_strdup(&str[0][i]);
	printf("strdup_b str = %s\n", str[0]);
	free(tmp);
	return (s);
}

char	**ft_strtok(char *str)
{
	int i;
	int j;
	char **s;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((is_sep(str, i) && i != 0))
			j++;
		i++;
	}
	if (str[i] == '\0' && (str[i - 1] != ';' && str[i - 1] != '|'))
		j++;
	s = (char **)malloc(sizeof(char *) * (j + 2));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((is_sep(str, i) && i != 0))
		{
			while (str[i] == ' ')
				i++;
			s[j] = ft_strdup_bis(&str, i);
			j++;
			i = 0;
		}
		i++;
	}
	if (str[i] == '\0' && ft_strlen(str) > 0)
	{
		s[j] = ft_strdup_bis(&str, i);
		printf("ue = %s\n", s[j]);
		j++;
	}
	s[j] = NULL;
	return (s);
}

