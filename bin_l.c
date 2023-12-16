#include "core.h"

long int bin_to_dec_conv(char* ptr){ //If it wont work - for prev part we need to add sign of the number
	long int number;
	number = strtol(ptr, NULL, 2);
	return number;
	/*if(signof == 0){
		for(int i = 0; i < strlen(ptr); i++){
			n = n + ( strtol(ptr[i] ) * ( 2 << (strlen(ptr) - i -  1 )); //Somnitelno, esli oshibki - peredelat vmesto sdviga ispolzovat pow() Takjhe - long int ** int - mozhet vizvat problemi

		}
	}else{
		for(int i = 1; i < strlen(ptr); i++){
			
			n = n + ( strtol(ptr[i] ) * ( 2 << (strlen(ptr) - i -  1 )); 
		}
		n *= -1;
	}
	return n;*/
}

void bin_printer(long int n){
	int a[64], i = 0;
	long int b = n;
	if(n == 0){
		printf("%d", n);
		goto deci; //GOTO HERE!!!
	}
	if(n >= 0){
		for(i=0; n>0; i++){    
           		a[i] = n % 2;    
            		n = n / 2;    
        	}
        	for(i = i - 1; i >= 0; i--){    
            		printf("%d", a[i]);    
        	}
    	}else{
        	n *= -1; 
        	printf("-");
        	for(i = 0;n > 0;i++){    
            		a[i] = n % 2;    
            		n = n / 2;    
        	}
        	for(i = i - 1;i >= 0;i--){    
           		 printf("%d", a[i]);    
        	}
	}
deci: printf(" (%ld)", b); //GOTO LABEL HERE!!!
        printf("\n");    
}
