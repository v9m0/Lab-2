#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "core.h"

//Global variables
bool sign1, sign2;
int base1, base2;

int main(){
    long int number1, number2;
    char *vvod = NULL;
    int r;
    char *arr[4];
    size_t buffsize;
    int tok_cnt = 0;
    int cnt = 0;
    char *p;
    r = getline(&vvod, &buffsize, stdin);
    if(r == -1){
        printf("Memory allocation failure!");
        exit(3);
    }
    p = strtok(vvod, " ");
    //strcpy(arr[0], p);
    while(p != NULL){
        arr[cnt++] = p;
	p = strtok(NULL, " ");
        tok_cnt++;
    }

    //printf("%d", tok_cnt);

    if(tok_cnt == 1){
    	inverse_check(arr[0]);
    }else{
	    if(tok_cnt == 3){
    	 	base_checker(arr[0], arr[2]);
		number1 = converter_hub(arr[0]);
		number2 = converter_hub(arr[2]);
		check_op(number1, number2, arr[1]);
	    }else{
	    	printf("Something went wrong in the main func");
		exit(3);
	    }
    }
    free(vvod);
}

void base_checker(char *num1, char *num2){
	if(num1[0] == '-'){
		sign1 = 1;
		if(num1[1] == '0'){
			if(num1[2] == 'x'){
				base1 = 16;
			}else{
				base1 = 8;
			}
		}else{
			base1 = 2;
		}
	}else{
		sign1 = 0;
		if(num1[0] == '0'){
			if(num1[1] == 'x'){
				base1 = 16;
			}else{
				base1 = 8;
			}
		}else{
			base1 = 2;
		}
	}
//////////////////	
	
	if(num2[0] == '-'){
		sign2 = 1;
		if(num2[1] == '0'){
			if(num2[2] == 'x'){
				base2  = 16;
			}else{
				base2 = 8;
			}
		}else{
			base2 = 2;
		}
	}else{
		sign2 = 0;
		if(num2[0] == '0'){
			if(num2[1] == 'x'){
				base2 = 16;
			}else{
				base2 = 8;
			}
		}else{
			base2 = 2;
		}
	}
////////////////////
	if(base1 != base2){
		printf("You've messed up the base! Try again.\n");
		exit(3);
	}
}


void inverse_check(char *ptr){
	const char s2 = '~';
	//if(strcmp(ptr[0], *s2) == 0){
	if(ptr[0] != '~'){
		printf("Error in inverse check!\n");
		exit(3);
	}
	long int num;
	base_checker(ptr, ptr);
	switch(base1){
		case 2:
			num = bin_to_dec_conv((ptr + 1));
			break;
		case 8:
			num = oct_to_dec_conv((ptr + 1));
			break;
		case 16:
			num = hex_to_dec_conv((ptr + 1));
			break;
		default:
			printf("Smth went wrong in inverse_check func\n");
	}
	inverter(num);
}

void inverter(long int number){
	long int c;
	c = ~number;
	output_hub(c);
}

long int converter_hub(char* ptr){
	int a;
	a = base2;
	long int num;
	switch(a){
		case 2:
			num = bin_to_dec_conv(ptr);
			break;
		case 8:
			num = oct_to_dec_conv(ptr);
			break;
		case 16:
			num = hex_to_dec_conv(ptr);
			break;
		//default:
		//	printf("Smth went wrong in the converter hub\n");
		//	exit(3);
		//	break;
	}
	return num;
}

void output_hub(long int num){
	int a;
	a = base1;
	switch(a){
		case 2:
			bin_printer(num);
			break;
		case 8:
			oct_printer(num);
			break;
		case 16:
			hex_printer(num);
			break;
		default:
			printf("Something went wrong!/n");
			exit(3);
			break;
	}
}

void check_op(long int num1, long int num2, char* ch){
	if(ch[0] == '&'){
		if((sign1 == 1) || (sign2 == 1)){
			printf("Error\n");
			exit(3);
		}else{
			and_op(num1, num2);
		}
    	}
    	if(ch[0] == '|'){
		if((sign1 == 1) || (sign2 == 1)){
			printf("Error\n");
			exit(3);
		}else{
			or_op(num1, num2);
		}
    	}
    	if(ch[0] == '^'){
    		if((sign1 == 1) || (sign2 == 1)){
			printf("Error\n");
			exit(3);
		}else{
			xor_op(num1, num2);
		}
    	}
    	
    	if(ch[0] == '+'){

		plus_op(num1, num2);
    	}
    	if(ch[0] == '-'){

		minus_op(num1, num2);
    	}
    	if(ch[0] == '*'){

		div_op(num1, num2);
    	}
     	if(ch[0] == '%'){

		mod_op(num1, num2);
    	}	
}

void plus_op(long int num1, long int num2){
	long int c;
	c = num1 + num2;
	output_hub(c);
}

void minus_op(long int num1, long int num2){
	long int c;
	c = num1 - num2;
	output_hub(c);
}


void div_op(long int num1, long int num2){
	long int c;
	c = num1 * num2;
	output_hub(c);
}


void mod_op(long int num1, long int num2){
	long int c;
	c = num1 % num2;
	output_hub(c);
}

void and_op(long int num1, long int num2){
	long int c;
	c = num1 & num2;
	output_hub(c);
}

void or_op(long int num1, long int num2){
	long int c;
	c = num1 | num2;
	output_hub(c);
}

void xor_op(long int num1, long int num2){
	long int c;
	c = num1 ^ num2;
	output_hub(c);
}


