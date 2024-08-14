#include<stdio.h>
#include<string.h>

int main(){
	
	char s[100];
	int cnt[1000] = {0};
	int i;
	gets(s);
	for(i = 0 ; i < 1000; i++){
		cnt[i] =0;
	}
	
	int len = strlen(s); //Tranh goi lai strlen sau moi vong for
	//printf("%d\n", strlen(s));

	//Count
	for(i = 0 ; i < len; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			cnt[s[i]]++;
		}
	}
	
	//Print
	//FIXED: Loi in
	for(i = 'a'; i < 'z';i++){
			if( cnt[i] > 0 ){
		printf("the letter '%c' appears %d times\n", i, cnt[i]);	
		}
	}
	
	/*
	char str[255];
	fgets(str ,255, stdin);
	int c,i;
	int len = strlen(str);
	
	for(c = 'a' ; c <= 'z'; c++){
		int demC = 0, i;
		for(i = 0, demC = 0 ; i <= len ; i++){
			
			if(str[i] == c){
				demC++;
			}
			if(demC != 0){
				printf("the letter %c appears %d times\n", c, demC);
			}
		}
	}

	*/
	return 0;
	
	
}
