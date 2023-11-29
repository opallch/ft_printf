/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:42:59 by oleung            #+#    #+#             */
/*   Updated: 2023/11/27 11:46:42 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_n_tokens(char *s, char delimiter)
{
	size_t	i;
	size_t	n_tokens;
	size_t	token_len;

	i = 0;
	n_tokens = 0;
	token_len = 0;
	while (ft_strlen(s) > 0 && (s[i] || i == ft_strlen(s)))
	{
		if ((s[i] == delimiter || i == ft_strlen(s)) && token_len > 0)
		{
			n_tokens++;
			token_len = 0;
		}
		else if (s[i] != delimiter)
		{
			token_len++;
		}
		i++;
	}
	return (n_tokens);
}

static char	*slice(const char *str, size_t token_len, size_t i)
{
	size_t	j;
	char	*token;

	j = 0;
	token = malloc(token_len * sizeof(char) + 1);
	if (!token)
		return (NULL);
	i -= token_len;
	while (j < token_len)
		token[j++] = str[i++];
	token[j] = '\0';
	return (token);
}

// static char **free_tokens(char **tokens, size_t n_tokens)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n_tokens)
// 	{
// 		free(tokens[i]);
// 		i++;
// 	}
// 	free(tokens);
// 	return (NULL);
// }

static char	**ft_split_aux(char const *s, char c, char **tokens,
		size_t n_tokens)
{
	size_t	i;
	size_t	token_len;
	char	*token;

	i = 0;
	token_len = 0;
	while (ft_strlen(s) > 0 && (s[i] || i == ft_strlen(s)))
	{
		if (s[i] == c || !s[i])
		{
			token = slice(s, token_len, i);
			if (ft_strlen(token) > 0)
			{
				tokens[n_tokens++] = token;
				token_len = 0;
			}
			else
				free(token);
		}
		else
			token_len++;
		i++;
	}
	tokens[n_tokens] = NULL;
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens;
	size_t	n_tokens;

	if (ft_strlen(s) == 0)
	{
		tokens = malloc(1 * sizeof(char *));
		if (!tokens)
			return (NULL);
		tokens[0] = NULL;
	}
	else
	{
		n_tokens = get_n_tokens((char *)s, c);
		tokens = malloc((n_tokens + 1) * sizeof(char *));
		if (!tokens)
			return (NULL);
		n_tokens = 0;
		ft_split_aux(s, c, tokens, n_tokens);
	}
	return (tokens);
}
