## IF
### code
```
void IF() {
  int ifBigin = nextLabel();//開始的label
  int ifMid = nextLabel();
  int ifEnd = nextLabel();//結束的label
  emit("(L%d)\n",ifBigin);
  skip("if");
  skip("(");
  int e= E();
  emit("if not t%d goto L%d\n",e,ifMid);
  skip(")");
  STMT();
  emit("goto L%d\n",ifEnd);
  emit("(L%d)\n", ifMid);
  if (isNext("else")) {
    skip("else");
    //emit("if L%d goto L%d\n",ifMid,ifEnd);
    STMT();
    emit("(L%d)\n",ifEnd);
  }
}
```
### result
```
PS C:\Users\rick2\sp109b\03b-compiler2> make
gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler
PS C:\Users\rick2\sp109b\03b-compiler2> ./compiler test/if.c   
if (a>3) {      
  t=1;
} else if(a<=0){
  t=2;
} else{
  t=3;
}
========== lex ==============
token=if
token=(
token=a
token=>
token=3
token=)
token={
token=t
token==
token=1
token=;
token=}
token=else
token=if
token=(
token=a
token=<=
token=0
token=)
token={
token=t
token==
token=2
token=;
token=}
token=else
token={
token=t
token==
token=3
token=;
token=}
========== dump ==============
0:if
1:(
2:a
3:>
4:3
5:)
6:{
7:t
8:=
9:1
10:;
11:}
12:else
13:if
14:(
15:a
16:<=
17:0
18:)
19:{
20:t
21:=
22:2
23:;
24:}
25:else
26:{
27:t
28:=
29:3
30:;
31:}
============ parse =============
(L0)
t0 = a
t1 = 3
t2 = t0 > t1
if not T2 goto L1
t3 = 1
t = t3
goto L2
(L1)
(L3)
t4 = a
t5 = 0
t6 = t4 <= t5
if not T6 goto L4
t7 = 2
t = t7
goto L5
(L4)
t8 = 3
t = t8
(L5)
(L2)
```