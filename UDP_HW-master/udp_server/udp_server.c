#include "udp_server.h"

udp_server_t* udp_server_init(){
	udp_server_t* server = malloc(sizeof(udp_server_t));
	server->SOCK = socket(PF_INET,SOCK_DGRAM,0);
	if(server->SOCK == -1){
		printf("socket() failed\n");
		exit(0);	
	}
	server->data = data_init();
	server->server_addr = malloc(sizeof(struct sockaddr_in));
	memset(server->server_addr,0,sizeof(struct sockaddr_in));
	server->server_addr->sin_family = AF_INET;
	server->server_addr->sin_port = htons(4000);
	server->server_addr->sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(server->SOCK, (struct sockaddr*)server->server_addr, sizeof(struct sockaddr))==-1){
		printf("bind() faild\n");
		close(server->SOCK);
		free(server);
		exit(1);
	}
	printf("server socket binded\n");
	printf("connection ready...\n");	
	return server;
}

void udp_server_connect(udp_server_t* server){
	printf("connecting...\n");
	printf("SOCK no : %d\n",server->SOCK);
	printf("%s\n",server->data->DATA_BUFFER);
	if(server->SOCK <=0){
		free(server);
		printf("socket fd error while connection\n");
		exit(1);
	}
	struct sockaddr_in client_addr;
	int addr_len = sizeof(struct sockaddr);
	ssize_t recv_bytes;
	memset(&client_addr,0,sizeof(client_addr));
	printf("client addr struct init done...\n");
	while(1){
		server->data->SIZE_OF_DATA = recvfrom(server->SOCK, server->data->DATA_BUFFER,server->data->SIZE_OF_DATA,0,(struct sockaddr*)&client_addr,&addr_len);
		if(server->data->SIZE_OF_DATA<=0){
			printf("failed to recv data from client\n");
			exit(1);
		}
		else{
			printf("Message from client : %s",server->data->DATA_BUFFER);
			sendto(server->SOCK,"ACK\n",5, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
		}
		sleep(5);
		
	}
		
}

void udp_server_destroy(udp_server_t* server){
	printf("Shutdown server...");
	close(server->SOCK);		
	free(server);
}

