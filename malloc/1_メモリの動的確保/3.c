#include <stdio.h>
#include <stdlib.h>

int main(){
	char *str;
	str = (char*)malloc(sizeof(char) * 100);
	if(str == NULL){
		printf("out of memory");
		exit(1);
	}

	scanf("%s", str);
	printf("%s\n", str);

	free(str);
	return 0;
}
