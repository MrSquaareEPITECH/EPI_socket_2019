/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** util.c
*/

#include "socket.h"

int socket_port(const socket_t *sock)
{
    uint32_t size = sizeof(sock->addr_in);

    getsockname(sock->fd, (sockaddr_t *)(&sock->addr_in), &size);

    int port = ntohs(sock->addr_in.sin_port);

    return (port);
}
