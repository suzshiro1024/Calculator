//演算子の優先順位を決定する定数
#define FIRST 1
#define SECOND 2
#define THIRD 3

//関数のプロトタイプ宣言
int rank(char operator);
char* parse(char str[], int length);