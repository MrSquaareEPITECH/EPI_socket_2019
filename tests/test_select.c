/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** test_select.c
*/

#include <criterion/criterion.h>

#include "select.h"

Test(select_create, valid)
{
    timeval_t *param1 = NULL;

    select_create(param1);
}

Test(select_delete, valid)
{
    select_t *param1 = select_create(NULL);

    select_delete(param1);
}

Test(select_delete, null)
{
    select_t *param1 = NULL;

    select_delete(param1);
}
