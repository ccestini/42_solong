/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:12:34 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/20 13:07:45 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_queue	*ft_queue_new(int index);
void	ft_q_add_back(t_queue **queue, t_queue *new);
void	ft_queue_delete(t_queue **lst);
int		ft_strlen(char *s);

t_queue	*ft_queue_new(int index)
{
	t_queue	*new;

	new = NULL;
	new = (t_queue *)malloc(sizeof(t_queue));
	if (!new)
		return (NULL);
	else
	{
		new->index = index;
		new->next = NULL;
		return (new);
	}
}

void	ft_q_add_back(t_queue **queue, t_queue *new)
{
	t_queue	*temp;

	if (!new)
		return ;
	if (!*queue)
		*queue = new;
	else
	{
		temp = *queue;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_queue_delete(t_queue **lst)
{
	t_queue	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free (temp);
	}
	*lst = NULL;
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
