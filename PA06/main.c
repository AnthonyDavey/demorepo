#include <stdio.h>
#include <stdlib.h>

#include "answer06.h"

int main(int argc, char **argv)
{
	if(argc != 2) return EXIT_FAILURE;
	int val = atoi(argv[1]);
	partitionAll(val);
	//partitionIncreasing(val);
	//partitionDecreasing(val);
	//partitionOdd(val);
	//partitionEven(val);
	//partitionOddAndEven(val);
	//partitionPrime(val);
	return EXIT_SUCCESS;
}