/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:55:36 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/24 15:24:26 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*get_next_line_utils(t_list *list);
void				create_list(t_list **list, int fd);
int					get_new_line(t_list *list);
t_list				*ft_lstlast(t_list *lst);
int					count_char(t_list *list);
void				rest_of_str(t_list **list);
void				free_everything(t_list **list, char *line, t_list *new);

#endif