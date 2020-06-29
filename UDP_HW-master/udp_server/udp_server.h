#ifndef __SERVER_H__
#define __SERVER_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "data.h"

#define CLIENT_PORT 4000

typedef struct udp_server_s udp_server_t;
struct udp_server_s{
	int SOCK;
	struct sockaddr_in* server_addr;
	data_t* data;
};
udp_server_t* udp_server_init();
void udp_server_connect(udp_server_t* server);
void udp_server_destroy(udp_server_t* server);
#endif
