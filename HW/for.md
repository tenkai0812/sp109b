## FOR
### code
```
void FOR() { 
  int forBegin = nextLabel(); //開始的label
  int forEnd = nextLabel();   //結束的label
  emit("(L%d)\n",forBegin);
  skip("for");
  skip("(");
  ASSIGN();                  //i = 0; 
  int e2 = E();              //i <= 10; 
  emit("if not t%d goto L%d\n",e2,forEnd);
  skip(";");
  int e3 = E();
  skip(")");
  STMT();
  emit("goto L%d\n",forBegin);
  emit("(L%d)\n",forEnd);
}
```

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