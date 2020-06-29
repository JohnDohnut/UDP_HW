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
typedef struct udp_client_s udp_client_t;
struct udp_client_s{
	int SOCK;
	struct sockaddr_in* server_addr;
	struct sockaddr_in* client_addr;
	data_t* data;
};
udp_client_t* udp_client_init();
void udp_client_connect();
void udp_client_destroy(udp_client_t*);

#endif
