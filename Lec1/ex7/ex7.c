#include<stdio.h>
#include<ctype.h>
#include<string.h>


int main(){
	FILE *input, *output;
	input = fopen("input.txt", "r" );
	output = fopen("output.txt", "w");
	
	
	if(input == NULL){
		printf("ERROR\n");
		return 1;
	}
	
	char ch;
		ch = toupper(fgetc(input));
	while(ch != EOF){
		fputc(ch, output);
		ch = toupper(fgetc(input));
	}
	
	fclose(input);
	fclose(output);
	
	
	return 0;
	
}
