
#include "data.h"

data_t* data_init(){
	data_t* data = malloc(sizeof(data));
	memset(data->DATA_BUFFER,0,BUFFER_SIZE);
	return data;
}

void data_destroy(data_t* data){
	free(data);
}
