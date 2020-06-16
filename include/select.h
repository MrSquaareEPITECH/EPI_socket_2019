/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** select.h
*/

#ifndef EPI_SOCKET_2019_INCLUDE_SELECT_H
#define EPI_SOCKET_2019_INCLUDE_SELECT_H

#include <sys/select.h>

#include "socket.h"

#define SELECT_READ (0x1)
#define SELECT_WRITE (0x2)
#define SELECT_EXCEPT (0x4)

typedef struct select_s select_t;
typedef struct timeval timeval_t;

struct select_s {
    fd_set read, mread;
    fd_set write, mwrite;
    fd_set except, mexcept;
    timeval_t *timeout, mtimeout;
};

select_t *select_create(timeval_t *timeout);
void select_set(select_t *sel, const socket_t *sock, int classes);
int select_is_set(const select_t *sel, const socket_t *sock, int classes);
void select_clear(select_t *sel, const socket_t *sock, int classes);
int select_monitor(select_t *sel);
void select_delete(select_t *select);

#endif // EPI_SOCKET_2019_INCLUDE_SELECT_H
