#include <stdio.h>
#include <stdlib.h>

#include"answer06.h"

#define TRUE 1
#define FALSE 0


void printPartition(int *partition, int length)
{
	int i;
	printf("= ");
	for(i=0; i < length; i++){
		if (i != 0) printf(" + ");
		printf("%d", partition[i]);
	}
	printf("\n");
}

void partitionAllHelper(int budget, int *partition, int pos)
{
	//BASE CASE: when do we terminate 
	if (budget == 0){
		printPartition(partition, pos);
		return;
	}
	//INDUCTIVE CASE: what to do if we don't terminate 
	int spending; 
	for (spending = 1; spending <= budget; spending++){
		partition[pos] = spending;
		partitionAllHelper(budget - spending, partition, pos+1);
	}
}

void partitionAll(int value)
{
	int *partition = malloc(sizeof(int) * value);
	partitionAllHelper(value, partition, 0);
	free(partition);
}

void partitionIncreasingHelper(int budget, int *partition, int pos)
{
	//BASE CASE: when do we terminate 
	if (budget == 0){
		printPartition(partition, pos);
		return;
	}
	//INDUCTIVE CASE: what to do if we don't terminate 
	int spending; 
	int start = pos == 0 ? 1 : partition[pos - 1] + 1;
	for (spending = start; spending <= budget; spending++){
		partition[pos] = spending;
		partitionIncreasingHelper(budget - spending, partition, pos+1);
	}
}

void partitionIncreasing(int value)
{
	int *partition = malloc(sizeof(int) * value);
	partitionIncreasingHelper(value, partition, 0);
	free(partition);

}

void partitionDecreasingHelper(int budget, int *partition, int pos)
{
	//BASE CASE: when do we terminate 
	if (budget == 0){
		printPartition(partition, pos);
		return;
	}
	//INDUCTIVE CASE: what to do if we don't terminate 
	int spending; 
	int start = pos == 0 ? budget : partition[pos - 1] - 1;
	for (spending = start; spending > 0; spending--){
		partition[pos] = spending;
		partitionDecreasingHelper(budget - spending, partition, pos+1);
	}
}

void partitionDecreasing(int value)
{
	int *partition = malloc(sizeof(int) * value);
	partitionDecreasingHelper(value, partition, 0);
	free(partition);
}

void partitionOddHelper(int budget, int *partition, int pos)
{
	//BASE CASE: when do we terminate 
	if (budget == 0){
		printPartition(partition, pos);
		return;
	}
	//INDUCTIVE CASE: what to do if we don't terminate 
	int spending; 
	for (spending = 1; spending <= budget; spending += 2){
		partition[pos] = spending;
		partitionOddHelper(budget - spending, partition, pos+1);
	}
}

void partitionOdd(int value)
{
	int *partition = malloc(sizeof(int) * value);
	partitionOddHelper(value, partition, 0);
	free(partition);
}

void partitionEvenHelper(int budget, int *partition, int pos)
{
	//BASE CASE: when do we terminate 
	if (budget == 0){
		printPartition(partition, pos);
		return;
	}
	//INDUCTIVE CASE: what to do if we don't terminate 
	int spending; 
	for (spending = 2; spending <= budget; spending += 2){
		partition[pos] = spending;
		partitionEvenHelper(budget - spending, partition, pos+1);
	}
}

void partitionEven(int value)
{
	int *partition = malloc(sizeof(int) * value);
	partitionEvenHelper(value, partition, 0);
	free(partition);
}

int isEven(int number)
{
	if (number % 2 == 0){
		return TRUE;
	}
	
	return FALSE;
}

int isOdd(int number)
{
	if (number % 2 == 1){
		return TRUE;
	}
	
	return FALSE;
}

void partitionOddAndEvenHelper(int budget, int *partition, int pos)
{
	//BASE CASE: when do we terminate 
	if (budget == 0){
		printPartition(partition, pos);
		return;
	}
	//INDUCTIVE CASE: what to do if we don't terminate 
	int spending; 
	for (spending = 1; spending <= budget; spending++){
		partition[pos] = spending;
		if (pos != 0){
			if((isEven(partition[pos]) == isEven(partition[pos-1])) || (isOdd(partition[pos]) == isOdd(partition[pos-1]))) continue;
		}
		partitionOddAndEvenHelper(budget - spending, partition, pos+1);
	}
}

void partitionOddAndEven(int value)
{
	int *partition = malloc(sizeof(int) * value);
	partitionOddAndEvenHelper(value, partition, 0);
	free(partition);
}


int isPrime(int number)
{
	int i;
	for (i = 2; i < number; i++){
		if (number % i == 0) return FALSE;
	}
	return TRUE;
}

void partitionPrimeHelper(int budget, int *partition, int pos)
{
	//BASE CASE: when do we terminate 
	if (budget == 0){
		printPartition(partition, pos);
		return;
	}
	//INDUCTIVE CASE: what to do if we don't terminate 
	int spending; 
	for (spending = 2; spending <= budget; spending++){
		if (!isPrime(spending)) continue;
		partition[pos] = spending;
		partitionPrimeHelper(budget - spending, partition, pos+1);
	}
}

void partitionPrime(int value)
{
	int *partition = malloc(sizeof(int) * value);
	partitionPrimeHelper(value, partition, 0);
	free(partition);
}