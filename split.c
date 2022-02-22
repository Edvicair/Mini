#include "built.h"

int	ft_count_word(char *str)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == ' ' && i != 0 && str[i - 1] != ' ' && (count_quote(str, i) % 2) == 0)
			word++;
		i++;
	}
	word++;
	return (word);
}

int	ft_strlen_bis(char *str)
{
	int i;

	i = 0;
	if (str[0] == ' ')
		i++;
       		while (str[i] && (str[i] != ' ' || (count_quote(str, i) % 2)))
	       		i++;
	if (str[0] == ' ')
		i--;
       return (i);
}

char	**split_space(char *str)
{
	char **s;
	int i;
	int j;
	int k;
	int word;

	i = 0;
	j = 0;
	k = 0;
	word = ft_count_word(str);
	s = (char **)malloc(sizeof(char *) * word + 1);
	if (!s)
		return (NULL);
	s[i] = (char *)malloc(sizeof(char) * ft_strlen_bis(str) + 1);
	if (!s[i])
		return (NULL);
	if (str[0] == ' ')
		k++;
	while (str[k] && i <= word)
	{
		if (str[k] == ' ' && (count_quote(str, i) % 2 == 0))
		{
			s[i][j] = '\0';
			i++;
			k++;
			if (i < word)
			{
				s[i] = (char *)malloc(sizeof(char) * ft_strlen_bis(&str[k]) + 1);
				if (!s[i])
					return (NULL);
			}
			j = 0;
		}
		s[i][j] = str[k];
		j++;
		k++;
	}
	if (str[k] == '\0' && str[k - 1] != ' ')
	{
		s[i][j] = '\0';
		i++;
	}
	s[i] = NULL;
	return (s);
}

