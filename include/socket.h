/*
** EPITECH PROJECT, 2020
** EPI_socket_2019
** File description:
** socket.h
*/

#ifndef EPI_SOCKET_2019_INCLUDE_SOCKET_H
#define EPI_SOCKET_2019_INCLUDE_SOCKET_H

#include <netinet/in.h>
#include <stdint.h>

#ifndef SOCK_SIZE
#define SOCK_SIZE (512)
#endif // SOCK_SIZE

#define SOCK_AUTO (0)
#define SOCK_AT_START (42)

typedef struct socket_s socket_t;
typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

struct socket_s {
    sockaddr_in_t addr_in;
    int fd;
};

typedef int (*condition_t)(int rbytes, const char *buf);

#define sockaddr(addr) ((sockaddr_t *)(addr))

socket_t *socket_create(uint32_t addr, uint32_t family, uint16_t port);
int socket_accept(socket_t *sock, socket_t *peer);
int socket_bind(socket_t *sock, int type);
int socket_connect(socket_t *sock, int type);
int socket_listen(socket_t *sock, int max);
int socket_download(socket_t *sock, int fd, int flags);
int socket_receive(socket_t *sock, char *buf, size_t len, int flags);
int socket_receivew(socket_t *sock, char **buf, condition_t cond, int flags);
int socket_send(socket_t *sock, const char *buf, size_t len, int flags);
int socket_upload(socket_t *sock, int fd, int flags);
void socket_delete(socket_t *sock);

#endif // EPI_SOCKET_2019_INCLUDE_SOCKET_H
