/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** socket.c
*/

#include "socket.h"

#include <stdlib.h>
#include <unistd.h>

socket_t *socket_create(uint32_t addr, uint32_t family, uint16_t port)
{
    socket_t *sock = malloc(sizeof(socket_t));

    if (sock == NULL)
        return (NULL);
    sock->addr_in.sin_addr.s_addr = addr;
    sock->addr_in.sin_family = family;
    sock->addr_in.sin_port = htons(port);
    return (sock);
}

void socket_delete(socket_t *sock)
{
    if (sock == NULL)
        return;
    close(sock->fd);
    free(sock);
}
