# :memo: 系統程式第二周筆記
## 本周重點:編譯器(Compiler)
編譯器大部分認知都是編譯出執行黨或是目的檔，其實也可以輸出組合語言，而上禮拜使用的gcc不單單只是個編譯器，gcc是一個工具箱，可供編譯組譯或是執行系統整合
## 系統程式4大重點
1. 編譯器(Compiler)
2. 組譯器(Assembler)
3. 虛擬機(Virtual Machine)
4. 作業系統(Operating System)
## 編譯組譯圖

<img src = '.\編譯組譯圖.PNG'>

## 虛擬機用圖
使用虛擬機去實作ARM、RISC-V、x86的指令集，這是避免寫的程式會造成電腦實質傷害，而且有機會用不同架構寫法時轉換速度慢，因此使用虛擬機
## Compiler 順序

<img src = '.\compiler.PNG'>

<img src = '.\compiler2.PNG'>

## 高階語言時間表

<img src = '.\高階語言.PNG' >

## BNF & EBNF
BNF(Backus-Naur Form)是一種用於表示上下文無關文法的語言，上下文無關文法描述了一類形式語言。儘管巴科斯範式也能表示一部分自然語言的語法，它還是更廣泛地使用於程式設計語言、指令集、通信協議的語法表示中。大多數程式設計語言或者形式語義方面的教科書都採用巴科斯範式。
為何這邊我們使用EBNF必較適合?原因是BNF會最基本的機體問題，凡是寫出左遞迴式，程式只會一直呼叫接下來就呼叫到當機。
<img src = '.\bnfebnf.PNG'>

## test
[00-gen](./00-gen/gen.md)<br>
[01-exp0](./01-exp0/exp0.md)<br>

## 遞迴下降法












<br><br><br><br>
🖊️editor:Sky Lien