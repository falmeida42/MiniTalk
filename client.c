/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:38:31 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/27 18:38:50 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_message(int binario[], int pid)
{
	int	i;

	i = 2;
	while (i < 10)
	{
		if (binario[i] == 1)
			kill(pid, SIGUSR1);
		else if (binario[i] == 0)
			kill(pid, SIGUSR2);
		i++;
		usleep(25);
	}
}

void	pass_tob(int num, int pid)
{
	int	binario[10];
	int	i;
	int	j;

	j = 0;
	i = 10 - 1;
	while (i > 1)
	{
		if (num % 2 == 0)
			binario[i] = 0;
		else
			binario[i] = 1;
		num = num / 2;
		i--;
	}
	send_message(binario, pid);
}

void	get_message(char *argv, int pid)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		pass_tob(argv[i], pid);
		i++;
	}
}

int	get_pid(char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	return (pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 1 || argc == 2 || argc > 3)
		return (0);
	pid = get_pid(argv);
	get_message(argv[2], pid);
}
