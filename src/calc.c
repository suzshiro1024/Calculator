#include <stdio.h>
#include <ctype.h>
#include "stack.h"
#include "parse.h"
#include "calc.h"

//数字の桁数を計算
int cal_digit(int num){
    int digit = 0;
    while(num != 0){
        num /= 10;
        digit++;
    }
    return digit;
}

//文字列の数字を逆順pushする関数
int num_push(char* buffer,int i){
    int count = 0;
    int index = i;
    //区切り用の空白をpush
    if(peek() != ' '){
        push(' ');
    }

    //負数かどうか確認
    if(buffer[i]=='-'){
        i++;
        count++;
    }

    //桁数のカウントを行う
    while(isdigit(buffer[i++])){
        count++;
    }

    //index+桁数-1で数字の1の位が格納されているindexになる
    for(int j = index + count - 1; j >= index; j--){
        push(buffer[j]);
    }

    //ヘッダの位置を動かし、pushした数字の部分を飛ばさせる
    return index + count;
}

//文字列の数字をpopする関数
int num_pop(){
    //数字を格納
    char* num = calloc(stack_size()+1,sizeof(char));

    //NULLチェック
    if(num == NULL){
        puts("ERROR calloc Failed");
        exit(1);
    }

    //数字をバッファに取り出し
    int index = 0;
    if(!isdigit(peek())&&peek()!='-'){
        //空白を取り除く
        char tmp = pop();
    }
    while(isdigit(peek()) || peek() == '-'){
        num[index] = pop();
        index++;
    }

    //文字列を数字に置換
    int return_num = atoi(num);
    //メモリ領域を解放
    free(num);

    return return_num;
}

//構文解析と計算
int calc(char* buffer,int length){
    char token;    //スタックからpopした文字
    int indexbuf = 0;

    for(int i = 0; i < length; i++){
        if(isdigit(buffer[i])){
            //数字が出てきたら数字をpushする関数を呼び出し(2桁以上の数を1の位から逆順にpushする必要があるため)
            //ヘッダの位置を動かし、pushした数字の部分を飛ばさせる
            i = num_push(buffer,i);
        }else{
            //演算子が出てきた場合はスタックから数字二つを呼び出してatoiして計算を行う。終わったらそれを文字列に変えて再び格納
            int num1 = num_pop();
            int num2 = num_pop();
            //結果を格納する数字
            int num = 0;

            //演算部
            if(buffer[i]=='+'){
                num = num2+num1;
            }else if(buffer[i]=='-'){
                num = num2-num1;
            }else if(buffer[i]=='*'){
                num = num2*num1;
            }else if(buffer[i]=='/'){
                num = num2/num1;
            }

            //結果の数字の桁数を計算
            int digit = cal_digit(num);
            //桁数分の文字列を確保
            char* push_num = calloc(digit+2,sizeof(char));
            //数字を文字列に置換
            int n = snprintf(push_num,digit+2,"%d",num);
            if(n < 0){
                printf("ERROR: Overflow");
                exit(1);
            }
            //数字をnum_pushで逆順push
            //返り値は破棄するので適当な変数に格納しておく
            int tmp = num_push(push_num,0);
            free(push_num);
        }
    }

    int result = num_pop();
    free(buffer);
    return result;
}