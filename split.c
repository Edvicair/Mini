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
	if (str[i] == '\0' && str[i - 1] != ' ')
	{
		word++;
		return (word);
	}
	if (str[i - 1] != ' ' && str[i] == '\0')
		word++;
	return (word);
}

int	ft_strlen_bis(char *str)
{
	int i;

	i = 0;
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
	printf("STR == ******%s***\n", str);
	printf("WORD == ******%d***\n", word);
	s = (char **)malloc(sizeof(char *) * (word + 1));
	if (!s)
		return (NULL);
	s[i] = (char *)malloc(sizeof(char) * (ft_strlen_bis(str) + 2));
	if (!s[i])
		return (NULL);
	if (str[0] == ' ')
		k++;
	while (str[k] && i <= word)
	{
		printf("1STR[%d] == ******%c***\n", k, str[k]);
		if (str[k] == ' ' && (count_quote(str, i) % 2 == 0))
		{
			s[i][j] = '\0';
			printf("s == ***%s***\n", s[i]);
			i++;
			k++;
			if (i < word)
			{
				printf("				%d\n", ft_strlen_bis(&str[k]));
				s[i] = (char *)malloc(sizeof(char) * (ft_strlen_bis(&str[k]) + 2));
				if (!s[i])
					return (NULL);
			}
			j = 0;
		}
		while (str[k] == ' ')
		{
			printf("2STR[%d] == ******%c***\n", k, str[k]);
			k++;
		}
		if (str[k])
		{
			printf("3STR[%d] == ******%c***\n", k, str[k]);
			s[i][j] = str[k];
			j++;
			k++;
		}
	}
//	if (str[k -1] == '\0' && str[k - 2] == '|')
//		return (s);
//		printf("HELOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	if (str[k - 1] == '\0')
	{
		s[i][j] = '\0';
		i++;
		s[i] = NULL;
		return (s);
	}
	if (str[k] == '\0' && str[k - 1] != ' ')
	{
		s[i][j] = '\0';
		i++;
	}
	s[i] = NULL;
	return (s);
}

