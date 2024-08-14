#include<stdio.h>
#include<string.h>
#define MAX (255)

void Replace(char *input, char a, char b){
	
//	int i;
//	int len = strlen(input);
//	for(i = 0 ; i < len ; i++){
//		if(*(input + i) == a){
//			*(input + i) = b;
//		}
//	}
//	
	
	
	while(*input){
		if(*input == a)
			*input = b;
		input++;
	}
	printf("%c\n", *(input-1));
}

int main(){
	char str[MAX];
	char a,b;
	printf("Input string: ");
	gets(str);
	fflush(stdin);
	printf("Input char A and char B: ");
	scanf("%c %c", &a, &b);
	Replace(str, a,b);
	
	printf("After replacing A with B: %s\n" , str);
	
	return 0;
	
	
	
}
