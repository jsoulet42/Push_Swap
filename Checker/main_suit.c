/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_suit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:56:28 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/25 16:57:05 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**make_argv(int argc, char **argv)
{
	int		i;
	char	**dest;

	i = 0;
	if (argc <= 2)
	{
		dest = ft_split(argv[1], ' ');
		argc = 0;
		if (dest[0] == NULL)
		{
			free(dest);
			return (0);
		}
	}
	else
	{
		dest = (char **) malloc((argc) * sizeof(char *));
		while (argv[i + 1])
		{
			dest[i] = ft_strdup(argv[i + 1]);
			i++ ;
		}
		dest[i] = NULL;
	}
	return (dest);
}

void	creat_list(t_list **a, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (!*a)
	{
		ft_printf("Error in creat_list\n");
		exit(0);
	}
}
