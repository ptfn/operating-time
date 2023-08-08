#include <stdlib.h>
#include <string.h>
void ST(int n, char *c) {for (int i = 0; i < n; i++)strcat(c, "*");}
void SP(int n, char *c) {for (int i = 0; i < n; i++)strcat(c, " ");}
void NL(char *c) {strcat(c, "\n");}

#include <stdio.h>

char *diamond (int n)
{	
	if (!(n&1) || n <= 0) {return NULL;}
	char *result = calloc(n*n, sizeof(char));	
	for (int i = 0; i < n/2; i++) {SP(n/2-i, result); ST((i+1)+i, result); NL(result);}
	ST(n, result); NL(result);
	for (int i = n/2-1; i >= 0; i--) {SP(n/2-i, result); ST((i+1)+i, result); NL(result);}
	return result;
}

int main()
{
	printf("%s\n", diamond(3));
	printf("%s\n", diamond(5));
	printf("%s\n", diamond(7));

	return 0;
}
