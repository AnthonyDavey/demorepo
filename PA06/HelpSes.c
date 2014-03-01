#include<stdio.h>
#include<stdlib.h>

/*Every recursive function has two cases:
	*(1) Base Case -- which is trivial 
	*(2) Inductive -- which asssumes that you know the answer to the smaller problem 
*/	

/*partition(0) = {}
partition(n) = 1 + partition(n-1)
			   2 + partition(n-2)
			   ....
			   n + partition(0)

*/

int factorial(int n)
{
	if(n==0) return 1; // 0! == 1
	return n * factorial(n-1);
}

void partition(int n, int write_pos)
{
	//(1) Base Case: n == 0 ==> {}
	if(n == 0){
		//print out the results 
		return;
	}
	
	//(2) Inductive case: 1+p(n-1), 2+p(n-2), ...., n
	int x;
	for(x = 1; x <= n; ++x){
		printf("About to try '%d' in position '%d'\n\n", x, write_pos);
		
		//store 'x' in the result
		partition(n-x, write_pos+1);
	}
}

void tabs(int n)
{
	int ind;
	for(ind = 0; ind < n; ++ind)
		printf(" ");
		
	//(1) Base Case: if n == 5, we're done
	if(n == 5){
		printf("Base Case\n");
		return;
	}
	
	// (2) Inductive case
	printf("recur\n");
	tabs(n+1);
	
	for(ind = 0; ind < n; ind++)
		printf(" ");
	printf("sion\n");
}

int main(int argc, char**argv)
{
	printf("Hello World\n");
	//int fact = factorial(5);
	//printf("Factorial(5) = %d\n", fact);
	//tabs(0);
	partition(5,0);
	
	return EXIT_SUCCESS;
}