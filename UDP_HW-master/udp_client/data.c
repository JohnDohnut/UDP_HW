
#include "data.h"

data_t* data_init(){
	data_t* data = malloc(sizeof(data));
	memset(data,0,sizeof(data_t));
	data->SIZE_OF_DATA = BUFFER_SIZE;
	return data;
}

void data_destroy(data_t* data){
	free(data);
}
