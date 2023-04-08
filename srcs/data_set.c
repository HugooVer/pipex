/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:49:40 by hvercell          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:27 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	arg_to_t_arg(int argc, char **argv, char **envp, t_arg *arg)
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	return (0);
}

int	data_preset(t_proc *proc, t_path *path, t_arg *arg)
{
	if (argument_number(arg->argc) == 1)
		return (1);
	proc->cmd_nb = arg->argc - 3;
	proc->pids = malloc((proc->cmd_nb + 1) * sizeof(pid_t));
	if (proc->pids == NULL)
		return (5);
	proc->pipes = malloc(proc->cmd_nb * sizeof(int *));
	if (proc->pipes == NULL)
		return (6);
	pipe_creation(proc);
	path->path = envp_finder(arg->envp, "PATH=");
	if (path->path == NULL)
		return (ft_printf("Env Error\n"), 2);
	pipe_initialisation(proc);
	proc->outfile = (arg->argv[arg->argc - 1]);
	proc->infile = (arg->argv[1]);
	proc->child = 0;
	return (0);
}