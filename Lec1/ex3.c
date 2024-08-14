#include<stdio.h>
#include<string.h>
#define MAX (255)

void Replace(char input[MAX], char a, char b){
	int i;
	for(i = 0 ; i < strlen(input) ; i++){
		if(input[i] == a){
			input[i] = b;
		}
	}
	
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
