#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 256


void BlockReadWrite(FILE *fin, FILE *fout){
    int num;
    char buff[MAX_LEN + 1];
    
    while(!feof(fin)){
        num = fread(buff, sizeof(char), 100, fin);
        fwrite(buff, sizeof(char), num, fout);
    }

}


int main(){
    FILE *f1, *f2;
    f1 = fopen("lab1.txt", "r");
    f2 = fopen("lab1a.txt", "w");

    if(f1 == NULL || f2 == NULL){
        perror("ERROR NOT FOUND FILE");
        exit(1);
    }

    BlockReadWrite(f1, f2);

    fclose(f1);
    fclose(f2);

    return 0;
}