#include "udp_client.h"

udp_client_t* udp_client_init(){
	udp_client_t* client = malloc(sizeof(udp_client_t));
	client->data = data_init();
	client->SOCK = socket(PF_INET,SOCK_STREAM,0);
	//sock() client addr
	memset(client->client_addr,0,sizeof(struct sockaddr_in));
	client->client_addr.sin_family = AF_INET;
	client->client_addr.sin_port = htons(4000);
	client->client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client->server_addr.sin_family = AF_INET;
	client->server_addr.sin_port = htons(4000);
	client->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	
}

void udp_client_connect(udp_client_t* client){
	ssize_t sendbytes;
	ssize_t recvbytes;
	while(1){
		fgets(client->data->DATA_BUFFER, BUFFER_SIZE-1,stdin);
		for(int i=0; i++ i<BUFFER_SIZE){
			if(client->data->DATA_BUFFER[i] == '\n'){
				DATA_BUFFER[i] = '\0';
				break;			
			}
		}
		sendbytes = sendto(client->SOCK,client->DATA_BUFFER,BUFFER_SIZE,0,(struct sockaddr*));
		if(sendbytes == -1){
			printf("send msg failed.\n1 : continue\n2 : terminate client\n");
			
		}
	}
}
