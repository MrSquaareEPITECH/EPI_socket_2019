/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** monitor.c
*/

#include <stddef.h>

#include "select.h"

void select_set(select_t *sel, const socket_t *sock, int classes)
{
    if (classes & SELECT_READ)
        FD_SET(sock->fd, &sel->read);
    if (classes & SELECT_WRITE)
        FD_SET(sock->fd, &sel->write);
    if (classes & SELECT_EXCEPT)
        FD_SET(sock->fd, &sel->except);
}

int select_is_set(const select_t *sel, const socket_t *sock, int classes)
{
    int is_set = 1;

    if (classes & SELECT_READ)
        is_set &= FD_ISSET(sock->fd, &sel->mread);
    if (classes & SELECT_WRITE)
        is_set &= FD_ISSET(sock->fd, &sel->mwrite);
    if (classes & SELECT_EXCEPT)
        is_set &= FD_ISSET(sock->fd, &sel->mexcept);

    return (is_set);
}

void select_clear(select_t *sel, const socket_t *sock, int classes)
{
    if (classes & SELECT_READ)
        FD_CLR(sock->fd, &sel->read);
    if (classes & SELECT_WRITE)
        FD_CLR(sock->fd, &sel->write);
    if (classes & SELECT_EXCEPT)
        FD_CLR(sock->fd, &sel->except);
}

int select_monitor(select_t *sel)
{
    int code = 0;
    timeval_t *timeout = NULL;

    sel->mread = sel->read;
    sel->mwrite = sel->write;
    sel->mexcept = sel->except;
    if (sel->timeout) {
        sel->mtimeout = *sel->timeout;
        timeout = &sel->mtimeout;
    }

    code = \
        select(FD_SETSIZE, &sel->mread, &sel->mwrite, &sel->mexcept, timeout);

    return (code);
}
