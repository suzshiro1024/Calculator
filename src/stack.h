#include <stdbool.h>
#include <stdlib.h>

//ノード構造体の定義
typedef struct node{
    char data;              //ノードの中身
    struct node* next_node; //次のノードへのポインタ
} node;

node* sp;                   //スタックのtopを指すポインタ(先頭のノードを指す)

//関数のプロトタイプ宣言
bool is_empty();
void push(char value);
char pop();
char peek();
int stack_size();