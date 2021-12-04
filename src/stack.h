#include <stdbool.h>
#include <stdlib.h>

//ノード構造体の定義
typedef struct node{
    char data;              //ノードの中身
    struct node* next_node; //次のノードへのポインタ
} node;

node* sp;                   //スタックのtopを指すポインタ(先頭のノードを指す)

bool is_empty();            //isEmpty
void push(char value);      //push
char pop();                 //pop
char peek();                //peek