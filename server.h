#ifndef __SERVER_H__
#define __SERVER_H__

#include <sys/type.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

#define CLIENT_PORT 2222
typedef struct server_s server_t;
struct server_t{
	int SOCK;
	struct sockaddr_in* server_addr;
	data_t* data;
}
server_t* server_init();
void server_connect(server_t* server);
void server_wait(server_t* server);
void server_destroy(server_t* server);
#endif
