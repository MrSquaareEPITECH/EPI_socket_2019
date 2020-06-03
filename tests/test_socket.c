/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** test_socket.c
*/

#include <criterion/criterion.h>

#include "socket.h"

Test(socket_create, valid)
{
    uint32_t param1 = INADDR_ANY;
    uint32_t param2 = PF_INET;
    uint16_t param3 = 4242;

    socket_create(param1, param2, param3);
}

Test(socket_delete, valid)
{
    socket_t *param1 = socket_create(INADDR_ANY, PF_INET, 4242);

    socket_delete(param1);
}

Test(socket_delete, null)
{
    socket_t *param1 = NULL;

    socket_delete(param1);
}
