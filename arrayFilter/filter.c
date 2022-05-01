#include"filter.h"

//The function return an array of numbers from the numbers in a given array 
//that has it corresponding bit in pred array on
int* filter(int* Numbers, int size, unsigned char* pred, int* new_size)
{
    int phySize = 0, logSize = 1, i, j = -1;
    int* newArr = (int*)malloc(sizeof(int) * logSize);
    cheackAllocation(newArr);
    unsigned char mask, temp;

    for (i = 0; i < size; i++)
    {
        if (phySize == logSize)
        {
            logSize *= 2;
            newArr = (int*)realloc(newArr, sizeof(int) * logSize);
            cheackAllocation(newArr);
        }

        if (i % 8 == 0)
        {
            mask = 1;
            j++;
        }
        temp = pred[j] & mask;
        if (temp != 0)
        {
            newArr[phySize] = Numbers[i];
            phySize++;
        }
        mask <<= 1;
    }
    if (phySize < logSize)
    {
        newArr = (int*)realloc(newArr, sizeof(int) * phySize);
        cheackAllocation(newArr);
    }

    *new_size = phySize;
    return newArr;
}

//The function return an array of numbers from the numbers in a given array 
//that has only one of it corresponding bit in pred1 and pred2 arrays on
int* xorFilter(int* Numbers, int size, unsigned char* pred1, unsigned char* pred2, int* new_size)
{
    int i, resSize, * arr;
    for (i = 0; i < size / 8; i++)
        pred1[i] = pred1[i] ^ pred2[i];

    arr = filter(Numbers, size, pred1, &resSize);
    *new_size = resSize;
    return arr;
}

//The function cheacks allocation
void cheackAllocation(void* chack)
{
    if (chack == NULL)
    {
        printf("Memory allocation failure");
        exit(1);
    }
}