#include "core.h"

long int hex_to_dec_conv(char* ptr){
	long int number;
	number = strtol(ptr, NULL, 16);
	return number;
}

void hex_printer(long int num){
	if(num >= 0){
		printf("0x%x (%d)\n", num, num);
	}else{
		printf("-0x%x (%d)\n", -1 * num, num);
	}
}
