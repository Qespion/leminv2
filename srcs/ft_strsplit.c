/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:32:35 by ratin             #+#    #+#             */
/*   Updated: 2019/05/07 10:40:50 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

static int	count_words(const char *str, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			words++;
		i++;
	}
	if (str[0] != '\0')
		words++;
	return (words);
}

static char	*ft_word(const char *str, char c, int *i)
{
	char	*word;
	int		j;

	if (!(word = (char *)malloc(sizeof(char) * (ft_strlen((char *)str) + 1))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		word[j] = str[*i];
		j++;
		*i += 1;
	}
	word[j] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (word);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		nb_words;
	char	**tab;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	nb_words = count_words(str, c);
	if (!(tab = (char **)malloc(sizeof(tab) * (nb_words + 1))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < nb_words && str[i])
	{
		tab[j] = ft_word(str, c, &i);
		j++;
	}
	tab[j] = 0;
	return (tab);
}