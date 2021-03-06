#include "rlib.h"

// === EBNF Grammar =====
// S = NP VP 句子 = 名詞短語 + 動詞短語
// NP = DET N 名詞短語 = 定詞 + 名詞
// VP = V NP 動詞短語 = 動詞 + 名詞短語
// N = dog | cat 名詞只有dog或cat
// V = chase | eat 動詞只有chase或eat
// DET = a | the 定詞只有a或the

char* n[] = {"dog", "cat"};
char* v[] = {"chase", "eat"};
char* det[] = {"a", "the"};

void N() {
  printf("%s", randSelect(n, 2));
}

void V() {
  printf("%s", randSelect(v, 2));
}

void DET() {
  printf("%s", randSelect(det, 2));
}

void NP() {
  DET(); //第23行
  printf(" ");
  N(); //第15行
}

void VP() {
  V(); //第8行
  printf(" ");
  NP(); 
}

void S() {
  NP(); //第27行
  printf(" ");
  VP(); //第33行
  printf("\n");    
  
}

int main() {
  timeSeed(); //rlib.c
  S(); //第3行解釋與第39行程式
}

