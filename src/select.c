/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** select.c
*/

#include <stdlib.h>

#include "select.h"

select_t *select_create(timeval_t *timeout)
{
    select_t *select = malloc(sizeof(select_t));

    if (select == NULL)
        return (NULL);
    FD_ZERO(&select->read);
    FD_ZERO(&select->write);
    FD_ZERO(&select->except);
    select->timeout = timeout;
    return (select);
}

void select_delete(select_t *select)
{
    if (select == NULL)
        return;
    free(select);
}
