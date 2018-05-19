#include <stdio.h>
#define STRING_WIDTH 20
int main(){
	char string[STRING_WIDTH];
	fgets(string, STRING_WIDTH, stdin);
	fputs(string, stdout);
	return 0;
}
