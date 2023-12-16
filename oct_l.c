#include "core.h"

long int oct_to_dec_conv(char* ptr){
	long int number;
	number = strtol(ptr, NULL, 8);
	return number;
}

void oct_printer(long int num){
	if(num >= 0){
		printf("0%o (%d)\n", num, num);
	}else{
		printf("-0%o (%d)\n", -1 * num, num);
	}
}
