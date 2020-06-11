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
#define SOCK_AT_START (0x100000)

typedef struct socket_s socket_t;
typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

struct socket_s {
    sockaddr_in_t addr_in;
    int fd;
};

typedef int (*condition_t)(int rbytes, const char *buf);

socket_t *socket_create(uint32_t addr, uint32_t family, uint16_t port);
void socket_delete(socket_t *sock);

// net
int socket_accept(socket_t *sock, socket_t *peer);
int socket_bind(socket_t *sock, int type);
int socket_connect(socket_t *sock, int type);
int socket_listen(const socket_t *sock, int max);
int socket_close(socket_t *sock);

// io
int socket_download(const socket_t *sock, int fd, int flags);
int socket_receive(const socket_t *sock, char *buf, size_t len, int flags);
int socket_receivew(
    const socket_t *sock, char **buf, int flags, condition_t cond);
int socket_send(const socket_t *sock, const char *buf, size_t len, int flags);
int socket_upload(const socket_t *sock, int fd, int flags);

// util
int socket_port(const socket_t *sock);

#endif // EPI_SOCKET_2019_INCLUDE_SOCKET_H
