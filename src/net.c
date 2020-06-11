/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** net.c
*/

#include <unistd.h>

#include "socket.h"

int socket_accept(socket_t *sock, socket_t *peer)
{
    uint32_t size = sizeof(sock->addr_in);

    sock->fd = accept(peer->fd, (sockaddr_t *)(&sock->addr_in), &size);
    if (sock->fd == -1)
        return (-1);
    return (0);
}

int socket_bind(socket_t *sock, int type)
{
    sock->fd = socket(sock->addr_in.sin_family, type, 0);
    if (sock->fd == -1)
        return (-1);

    uint32_t size = sizeof(sock->addr_in);

    if (bind(sock->fd, (sockaddr_t *)(&sock->addr_in), size) == -1)
        return (-1);
    return (0);
}

int socket_connect(socket_t *sock, int type)
{
    sock->fd = socket(sock->addr_in.sin_family, type, 0);
    if (sock->fd == -1)
        return (-1);

    uint32_t size = sizeof(sock->addr_in);

    if (connect(sock->fd, (sockaddr_t *)(&sock->addr_in), size) == -1)
        return (-1);
    return (0);
}

int socket_listen(const socket_t *sock, int max)
{
    if (listen(sock->fd, max) == -1)
        return (-1);
    return (0);
}

int socket_close(socket_t *sock)
{
    int rc = close(sock->fd);

    return (rc);
}
