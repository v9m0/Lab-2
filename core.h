#ifndef CORE_H
#define CORE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void base_checker(char *ptr1, char *ptr3);

void inverse_check(char *ptr);

void inverter(long int number);

long int hex_to_dec_conv(char* ptr);

long int oct_to_dec_conv(char* ptr);

long int bin_to_dec_conv(char* ptr);

long int converter_hub(char* ptr);

void hex_printer(long int num);

void oct_printer(long int num);

void bin_printer(long int num);

void output_hub(long int num);

void check_op(long int num1, long int num2, char* ptr);

void plus_op(long int num1, long int num2);

void minus_op(long int num1, long int num2);

void div_op(long int num1, long int num2);

void mod_op(long int num1, long int num2);

void and_op(long int num1, long int num2);

void or_op(long int num1, long int num2);

void xor_op(long int num1, long int num2);
#endif 
