#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "parse.h"
#include "stack.h"

//演算記号の優先順位を決定する関数
int rank(char operator){
    if(operator == '*' || operator == '/'){
        //'*','/'は優先順位1を与える
        return FIRST;
    }else if(operator == '+' || operator == '-'){
        //'+','-'は優先順位2を与える
        return SECOND;
    }else{
        //その他は優先順位3を与える
        return THIRD;
    }
}

/*
中値記法を逆ポーランド記法に変換するアルゴリズム
*/
char* parse(char str[], int length){
    char token;    //スタックからpopした文字

    //返り値となる文字列を格納するバッファ
    char* buffer = calloc(length+1, sizeof(char));
    int indexbuf = 0;

    for(int i = 0; i < length; i++){
        if(isdigit(str[i])){
            //ヘッダの先が文字が数字であるならばそのままバッファに格納
            buffer[indexbuf++] = str[i];
        }else if(str[i] == ')'){
            /*
            '('までスタックをpopし、バッファへ送る
            条件は スタックがカラでない && '('に到達した
            */
            while((token = pop()) != NULL && token != '('){
                buffer[indexbuf++] = token;
            }
            if(token == NULL){
                puts("ERROR: '(' is missing");
                exit(1);
            }
        }else if(str[i] == '('){
            //'('が来たらスタックにpush
            push(str[i]);
        }else if(peek() == NULL){
            /*
            スタックのtopがNULL => スタックがカラならヘッダの先の文字をスタックに格納
            ここに来るまでに数字,'(',')'の3種類は消えているので、ここで格納されるのは演算記号のみ
            */
            push(str[i]);
        }else{
            while(peek() != NULL){
                if(rank(str[i]) > rank(peek())){
                    //スタックのtopの演算子の優先順位がヘッダの先の塩酸氏の優先順位より低い場合
                    buffer[indexbuf++] = pop();
                }else{
                    //逆の場合
                    push(str[i]);
                    break;
                }
            }
        }
    }

    while((token = pop()) != NULL){
        buffer[indexbuf++] = token;
    }
    buffer[indexbuf++] = NULL;
    return buffer;
}