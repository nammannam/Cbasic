#include<stdio.h>
#include<stdlib.h>

enum{SUCCESS, FAIL, MAX_ELEMENT = 20};

typedef struct phoneaddress(){
    char name[20];
    char tel[10];
    char email[25];
}phoneaddress;

void info(){
    if((fp = fopen("phonebook.dat", "rb")) == NULL){
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;

    }
    irc = fread(phonearr, sizeof(phoneaddress), n, fp);
    printf(" fread return code = %d\n", irc);
    for( i = 0 ; i <= n; i++){
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s-", phonearr[i].email);
    }
    fclose(f);
    return reval;
}

int main(){



}