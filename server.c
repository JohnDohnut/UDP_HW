#include "server.h"

server_t* server_init(){
	server->SOCK = socket(PF_INET,SOCK_DGRAM,0);
	if(server->SOCK == -1){
		print("socket() failed\n");
		exit(0);	
	}
	server_t* server = malloc(sizeof(server_t));
	data_init(server->data));
	server->server_addr = malloc(sizeof(sockaddr_in));
	memset(server->server_addr,0,sizeof(sockaddr_in));
	server->server_addr->sin_family = AF_INET;
	server->server_addr->sin_port = htons(2222);
	server->server_addr->sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(server->SOCK, server->server_addr, sizeof(sockaddr_in)==-1){
		printf("bind() faild\n");
		close(server->SOCK);
		free(server);
		exit(1);
	}
	printf("server socket binded\n");
	printf("try to connect...\n");	
	return server;
}

void server_connect(server_t* server){
	printf("connecting...\n");
	if(server->SOCK <=0){
		free(server);
		printf("socket fd error while connection\n");
		exit(1);
	}
	struct sockaddr_in client_addr;
	int addr_len = sizeof(struct sockaddr);
	ssize_t recv_bytes;
	memset(&clientaddr,0,sizeof(sockaadr_in));
	while(1){
		server->data->SIZE_OF_DATA = recvfrom(server->SOCK, server->data->DATA_BUFFER,server->data->SIZE_OF_DATA,0,(struct sockaddr*)&clientaddr,&addr_len);
		if(SIZE_OF_DATA<=0){
			print("failed to recv data from client\n");
			exit(1);
		}
		else{
			printf("Message from client : %s",server->data->DATA_BUFFER);
		}
		
	}
		
}

