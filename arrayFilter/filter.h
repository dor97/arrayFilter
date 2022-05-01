#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

int* filter(int* Numbers, int size, unsigned char* pred, int* new_size);
int* xorFilter(int* Numbers, int size, unsigned char* pred1, unsigned char* pred2, int* new_size);
void cheackAllocation(void* chack);