/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** io.c
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "socket.h"

int socket_download(socket_t *sock, int fd, int flags)
{
    char tmp[SOCK_SIZE];
    int rbytes, wbytes;

    do {
        memset(tmp, 0, SOCK_SIZE);
        rbytes = socket_receive(sock, tmp, SOCK_SIZE, flags);
        if (rbytes == -1)
            return (-1);
        wbytes = write(fd, tmp, rbytes);
        if (wbytes == -1)
            return (-1);
        if (flags & SOCK_AT_START)
            flags = 0;
    } while (rbytes > 0);
    return (0);
}

int socket_receive(socket_t *sock, char *buf, size_t len, int flags)
{
    int rbytes = recv(sock->fd, buf, len, flags);

    return (rbytes);
}

int socket_receivew(socket_t *sock, char **buf, condition_t cond, int flags)
{
    char tmp[SOCK_SIZE];
    int rbytes, len = 0;

    do {
        memset(tmp, 0, SOCK_SIZE);
        rbytes = socket_receive(sock, tmp, SOCK_SIZE, flags);
        if (rbytes == -1)
            return (-1);
        len += rbytes;
        *buf = realloc(*buf, len + 1);
        *buf = strncat(*buf, tmp, rbytes);
        (*buf)[len] = 0;
        if (flags & SOCK_AT_START)
            flags = 0;
    } while (!cond(rbytes, tmp));
    return (0);
}

int socket_send(socket_t *sock, const char *buf, size_t len, int flags)
{
    int wbytes = send(sock->fd, buf, len, flags);

    return (wbytes);
}

int socket_upload(socket_t *sock, int fd, int flags)
{
    char tmp[SOCK_SIZE];
    int rbytes, wbytes;

    do {
        memset(tmp, 0, SOCK_SIZE);
        rbytes = read(fd, tmp, SOCK_SIZE);
        if (rbytes == -1)
            return (-1);
        wbytes = socket_send(sock, tmp, rbytes, flags);
        if (wbytes == -1)
            return (-1);
        if (flags & SOCK_AT_START)
            flags = 0;
    } while (rbytes > 0);
    return (0);
}
