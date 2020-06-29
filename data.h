#ifndef __DATA_H__
#define __DATA_H__
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 50

typedef struct data_s data_t;

struct data_s{
	int SIZE_OF_DATA;
	char DATA_BUFFER[50];
}

data_t* data_init();
void data_destroy();
#endif
