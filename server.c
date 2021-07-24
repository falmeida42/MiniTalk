/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:56:13 by falmeida          #+#    #+#             */
/*   Updated: 2021/07/24 18:57:10 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void    getsignal(int i)
{
    if (i == SIGUSR1)
        printf("sinal 1\n");
    if (i == SIGUSR2)
        printf("sinal 2\n");
}

int main(void)
{
    pid_t pid;
    
    int i;
    i = 1;
    pid = getpid();
    signal(SIGUSR1, getsignal);
    signal(SIGUSR2, getsignal);
    printf("%d\n", pid);
    while (1)
        pause();
}