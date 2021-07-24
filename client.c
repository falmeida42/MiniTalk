/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:38:31 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/24 19:00:09 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void   get_pid(char **argv)
{
    int pid;

    pid = ft_atoi(argv[1]);
    kill(pid, SIGUSR1);
    kill(pid, SIGUSR2);
} 

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    get_pid(argv);
}