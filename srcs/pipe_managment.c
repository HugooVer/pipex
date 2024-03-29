/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:38:10 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/13 15:01:49 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_creation(t_proc *proc)
{
	int	i;

	i = 0;
	while (i <= proc->cmd_nb - 1)
	{
		proc->pipes[i] = malloc(2 * sizeof(int));
		if (proc->pipes[i] == NULL)
			return (7);
		++i;
	}
	return (0);
}

int	pipe_initialisation(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < proc->cmd_nb)
	{
		if (pipe(proc->pipes[i]) == -1)
			return (3);
		++i;
	}
	return (0);
}

int	dup2close(int fd1, int fdd1, int fd2, int fdd2)
{
	dup2 (fdd1, fd1);
	if (fdd1 != -1)
		close (fdd1);
	dup2 (fdd2, fd2);
	if (fdd2 != -1)
		close (fdd2);
	return (0);
}

int	close_all_pipes(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < (proc->cmd_nb))
	{
		close(proc->pipes[i][READ_END]);
		close(proc->pipes[i][WRITE_END]);
		wait(NULL);
		++i;
	}
	return (0);
}
