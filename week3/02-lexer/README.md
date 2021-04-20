# 詞彙解析 Lexer

## 語法

```
Token = String | Number | Id | Char
String = ".*"
Number = [0-9]+
Id = [_a-z][_a-z0-9]*
Char = .
```

## 執行

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp109b/week3/02-lexer
$ gcc lexer.c -o lexer

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp109b/week3/02-lexer
$ ./lexer sum.c
#include "sum.h"

int main() {
  int t = sum(10);
  printf("sum(10)=%d\n", t);
}
token=#
token=include
token="sum.h"
token=int
token=main
token=(
token=)
token={
token=int
token=t
token==
token=sum
token=(
token=10
token=)
token=;
token=printf
token=(
token="sum(10)=%d\n"
token=,
token=t
token=)
token=;
token=}
0:#
1:include
2:"sum.h"
3:int
4:main
5:(
6:)
7:{
8:int
9:t
10:=
11:sum
12:(
13:10
14:)
15:;
16:printf
17:(
18:"sum(10)=%d\n"
19:,
20:t
21:)
22:;
23:}
```