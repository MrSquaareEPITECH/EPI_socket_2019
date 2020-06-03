/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** io.c
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "socket.h"

int socket_download(const socket_t *sock, int fd, int flags)
{
    char tmp[SOCK_SIZE + 1];
    int rbytes, wbytes;

    do {
        memset(tmp, 0, sizeof(tmp));
        rbytes = socket_receive(sock, tmp, SOCK_SIZE, flags);
        if (rbytes == -1)
            return (-1);
        wbytes = write(fd, tmp, rbytes);
        if (wbytes == -1)
            return (-1);
        if (flags & SOCK_AT_START)
            flags = 0;
    } while (rbytes > 0);
    return (rbytes);
}

int socket_receive(const socket_t *sock, char *buf, size_t len, int flags)
{
    int rbytes = recv(sock->fd, buf, len, flags);

    return (rbytes);
}

int socket_receivew(
    const socket_t *sock, char **buf, int flags, condition_t condition)
{
    char tmp[2];
    int rbytes, len = 0;

    do {
        memset(tmp, 0, sizeof(tmp));
        rbytes = socket_receive(sock, tmp, 1, flags);
        if (rbytes == -1)
            return (-1);
        len += rbytes;
        *buf = realloc(*buf, len + 1);
        memset(&(*buf)[len - rbytes], 0, rbytes + 1);
        *buf = strncat(*buf, tmp, rbytes);
        if (flags & SOCK_AT_START)
            flags = 0;
    } while (!condition(rbytes, *buf) && (rbytes > 0));
    return (rbytes);
}

int socket_send(const socket_t *sock, const char *buf, size_t len, int flags)
{
    int wbytes = send(sock->fd, buf, len, flags);

    return (wbytes);
}

int socket_upload(const socket_t *sock, int fd, int flags)
{
    char tmp[SOCK_SIZE + 1];
    int rbytes, wbytes;

    do {
        memset(tmp, 0, sizeof(tmp));
        rbytes = read(fd, tmp, SOCK_SIZE);
        if (rbytes == -1)
            return (-1);
        wbytes = socket_send(sock, tmp, rbytes, flags);
        if (wbytes == -1)
            return (-1);
        if (flags & SOCK_AT_START)
            flags = 0;
    } while (rbytes > 0);
    return (wbytes);
}
