#include <stdlib.h>
#include "answer02.h"

size_t my_strlen(const char * str)
{
	int counter = 0;
	while(*str != '\0')
	{
		counter++;
		str++;
	}
   return counter;
}

int my_countchar(const char * str, char ch)
{
	int counter = 0;
	while(*str++)
	{
		if(*str == ch) counter++;
	}
	return counter;
}

char * my_strchr(const char * str, int ch)
{
	while(*str++)
	{
		if(*str == c) return (char*) str;
	}
	return string("NULL"); //if not found return NULL, how do I return a string?
}

char * my_strrchr(const char * str, int ch)
{
	int i;
	
	for (i = '\0' i != ; 
	return 0;
}

char * my_strstr(const char * haystack, const char * needle)
{
	while(*haystack++)
	{
		if(*haystack == *needle) return (char*) haystack;
	}
	return 0;
}

char * my_strcpy(char * dest, const char * src)
{
	while(*src){
		*dest = *src;
		dest++;
		src++;
	}
	
	return dest;
}

char * my_strcat(char * dest, const char * src)
{
	return 0;
}

int my_isspace(int ch)
{
	char i;
	
	for(i = '1'; i <= '127'; i++){
		if(i == (char)ch) return 0;
	}
	return 1;
}

int my_atoi(const char * str)
{
	return 0;
}