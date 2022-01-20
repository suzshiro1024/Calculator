#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "parse.h"
#include "calc.h"

#define STR_LENGTH 128

int main(void){
    char str[STR_LENGTH];
    FILE* fp;

    fp = fopen("calc.txt","r");

    if(fp == NULL){
        puts("ERROR File Not Found");
        exit(1);
    }else{
        fscanf(fp,"%s",str);
    }

    fclose(fp);

    char* buffer = parse(str, sizeof(str)/sizeof(char*));

    //逆ポーランド記法になった文字列バッファの長さを取得
    int length = strlen(buffer);

    //計算させる
    int result = calc(buffer, length);

    fp = fopen("calc.txt","a");

    if(fp==NULL){
        puts("ERROR File Not Found");
        exit(1);
    }else{
        fprintf(fp,"=%d\n",result);
    }
}