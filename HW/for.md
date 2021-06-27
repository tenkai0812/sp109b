## FOR
### code
```
void FOR(){
  int ForBegin = nextLabel();
  int ForEnd = nextLabel();
  // 跳過for和(
  skip("for");
  skip("(");
  // a是初始項
  int a = E();
  skip(";");
  // 這裡是迴圈執行的起點
  emit("(L%d)\n", ForBegin);
  // b是條件項
  int b = E();
  skip(";");
  emit("if T%d goto L%d\n", b, ForEnd);
  isTempIr = 1;                
  // c是循環項，先放著
  int c = E();                
  isTempIr = 0;                
  char C[10000];
  strcpy(C, tempIr);       
  skip(")");
  // 取得執行項
  STMT();
  // 印出c部分
  emit("%s\n", C);        
  emit("goto L%d\n", ForBegin);
  emit("(L%d)\n",ForEnd);
}

### result
```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp109b/HW (main)
$ make
gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp109b/HW (main)
$ ./compiler test/for.c
for(i=0; i<10; i++){
    a = a + 1;
}
========== lex ==============
token=for
token=(
token=i
token==
token=0
token=;
token=i
token=<
token=10
token=;
token=i
token=++
token=)
token={
token=a
token==
token=a
token=+
token=1
token=;
token=}
========== dump ==============
0:for
1:(
2:i
3:=
4:0
5:;
6:i
7:<
8:10
9:;
10:i
11:++
12:)
13:{
14:a
15:=
16:a
17:+
18:1
19:;
20:}
============ parse =============
(L0)
t0 = 0
i = t0
t1 = i
t2 = 10
t3 = t1 < t2
if not T3 goto L1
t5 = a
t6 = 1
t7 = t5 + t6
a = t7
i = i + 1
t4 = i

goto L0
(L1)
============ parse =============
compiler.c, line 36
```