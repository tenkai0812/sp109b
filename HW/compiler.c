#include <assert.h>
#include "compiler.h"

int E();
void STMT();
void IF();
void BLOCK();
void For();
int tempIdx = 0, labelIdx = 0;

#define nextTemp() (tempIdx++)
#define nextLabel() (labelIdx++)
#define emit printf

int isNext(char *set) {
  char eset[SMAX], etoken[SMAX];
  sprintf(eset, " %s ", set);
  sprintf(etoken, " %s ", tokens[tokenIdx]);
  return (tokenIdx < tokenTop && strstr(eset, etoken) != NULL);
}

int isEnd() {
  return tokenIdx >= tokenTop;
}

char *next() {
  // printf("token[%d]=%s\n", tokenIdx, tokens[tokenIdx]);
  return tokens[tokenIdx++];
}

char *skip(char *set) {
  if (isNext(set)) {
    return next();
  } else {
    printf("skip(%s) got %s fail!\n", set, next());
    assert(0);
  }
}

// F = (E) | Number | Id
int F() {
  int f;
  if (isNext("(")) { // '(' E ')'
    next(); // (
    f = E();
    next(); // )
  } else { // Number | Id
    f = nextTemp();
    char *item = next();
    emit("t%d = %s\n", f, item);
  }
  return f;
}

// E = F (op E)*
int E() {
  int i1 = F();
  while (isNext("+ - * / & | ! < > = <= >= == !=")) {
    char *op = next();
    int i2 = E();
    int i = nextTemp();
    emit("t%d = t%d %s t%d\n", i, i1, op, i2);
    i1 = i;
  }
  return i1;
}

// ASSIGN = id '=' E;
void ASSIGN() {
  char *id = next();
  skip("=");
  int e = E();
  skip(";");
  emit("%s = t%d\n", id, e);
}

// WHILE = while (E) STMT
void WHILE() {
  int whileBegin = nextLabel();
  int whileEnd = nextLabel();
  emit("(L%d)\n", whileBegin);
  skip("while");
  skip("(");
  int e = E();
  emit("if not T%d goto L%d\n", e, whileEnd);
  skip(")");
  STMT();
  emit("goto L%d\n", whileBegin);
  emit("(L%d)\n", whileEnd);
}

// if (EXP) STMT (else STMT)?
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
void FOR() { 
  int forBegin = nextLabel(); //開始的label
  int forEnd = nextLabel();   //結束的label
  emit("(L%d)\n",forBegin);
  skip("for");
  skip("(");
  ASSIGN();                  //i = 0; 在這邊沒有skip(";");是因為在ASSUGN()這個函式中已經有做了
  int e2 = E();              //i <= 10; 處理裡面的符號
  emit("if not t%d goto L%d\n",e2,forEnd);
  skip(";");
  int e3 = E();
  skip(")");
  STMT();
  emit("goto L%d\n",forBegin);
  emit("(L%d)\n",forEnd);
}
// STMT = WHILE | BLOCK | ASSIGN
void STMT() {
  if (isNext("while"))
    return WHILE();
  else if (isNext("if"))
    IF();
  else if (isNext("{"))
    BLOCK();
  else
    ASSIGN();
}

// STMTS = STMT*
void STMTS() {
  while (!isEnd() && !isNext("}")) {
    STMT();
  }
}

// BLOCK = { STMTS }
void BLOCK() {
  skip("{");
  STMTS();
  skip("}");
}

// PROG = STMTS
void PROG() {
  STMTS();
}

void parse() {
  printf("============ parse =============\n");
  tokenIdx = 0;
  PROG();
}