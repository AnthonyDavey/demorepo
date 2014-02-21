#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void printHelp()
{
	printf("Usage: cat-lite [--help] [FILE]...\n"
		   "With no FILE, or when FILE is -, read standard input.\n"
		   "\n"
           "Examples:\n"
           "	cat-lite README   Print the file README to standard output.\n"
           "	cat-lite f - g    Print f's contents, then standard input, then g's contents.\n"
           "	cat-lite          Copy standard input to standard output.\n");
}

int catFile(const char *filename, FILE *fout)
{
	FILE *fin;
	int isStdin = strcmp(filename, "-") == 0;
	if (isStdin) fin = stdin;
	else fin = fopen(filename, "r"); //'r' stands for read
	if(fin == NULL) return FALSE;
	
	//at this point you are able to open the file for reading
	int ch; 
	while((ch = fgetc(fin)) != EOF){
		fputc(ch, fout);
	}
	
	if (!isStdin) fclose(fin); //if you open a file you must close it 
	return TRUE;
}


int main(int argc, char **argv)
{
	if (argc == 1){
		catFile("-", stdout);
		return EXIT_FAILURE;
	}
	
	//checked for the --help flag 
	int i;
	for(i=1; i < argc; i++){
		if(strcmp(argv[i], "--help") == 0){
			printHelp();
			return EXIT_SUCCESS;
		}
	}
	
	//Concatenate one file at a time
	for(i=1; i < argc; i++){
		if (catFile(argv[i], stdout) == FALSE){
			fprintf(stderr, "cat cannot open %s\n", argv[i]);
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}