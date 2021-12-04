#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

bool is_empty(){
    return sp == NULL;  //もしスタックのtopを指すポインタの中身がNULLであるならばスタックは空
}

void push(char data){
    node* node_new; // 新しいノードを指すポインタを用意する

    //メモリ領域の確保
    node_new = (node*)malloc(sizeof(node));

    //メモリ領域の確保に失敗した場合はここでtrueとなってエラーを出して終了
    if(node_new == NULL){
        puts("ERROR malloc Failed");
        exit(1);
    }

    //新しいノードへの中身の代入(ポインタの先の構造体なのでアロー演算子->を用いた間接参照を利用)
    node_new->data = data;
    //スタックがカラだったかそうでないかで条件分岐する
    if(is_empty()){
        //スタックがカラだった場合、スタックのtopを今作ったノードとし、次のノードは存在しないのでポインタの先はNULLにしておく
        sp = node_new;
        node_new->next_node = NULL;
    }else{
        //スタックがカラでなかった場合、スタックのtopは今作ったノードに置き換える。そのあと、今作ったノードの次のノードに今までtopだったノードを置く
        node* tmp = sp;
        sp = node_new;
        node_new->next_node = tmp;
    }
}

char pop(){
    //スタックがカラの場合NULLを返す
    if(is_empty()){
        return NULL;
    }
    //スタックのtopをpopする
    node* node_pop = sp;        //popするノードを指すポインタ
    char data = node_pop->data; //データを返り値用の変数に格納
    sp = node_pop->next_node;   //topをpopするノードの次のノードに変更
    free(node_pop);             //今popしたノードが確保していたメモリ領域はもう必要ないので解放

    return data;
}

char peek(){
    //スタックがカラの場合NULLを返す
    if(is_empty()){
        return NULL;
    }
    //スタックのtopを返す。スタック自体は変化しない
    node* node_peek = sp;       //peekするノードを指すポインタ
    char data = node_peek->data;//データを返り値用の変数に格納

    return data;
}