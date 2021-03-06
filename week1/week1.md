# :memo: 系統程式第一周筆記
## :computer:何謂系統程式
課程名稱"系統程式"會被翻譯為system software 或 system programming，但這兩者卻並不相同。system software 稱作"系統軟體"，和他對應的正是application software，一個不負責任的說法就是:「system software是專門給程式設計師的軟體，application software是給大眾所使用的軟體」
從這可知道，組譯器、編譯器、虛擬機等等可稱作為system software，而office、adobe、browser則可稱作application software，但是如果是文字編輯器、資料庫管理這種軟體就不太能明確區分屬於system software 還是 application software了
## :book: 教學順序

<img src = ".\導引.JPG">

## 典型系統程式
* 輸入/輸出套裝副程式（Input/Output Subroutine Packages）
* 監督程式（Monitors）
* 作業系統（Operating Systems）
* 組譯程式（Assemblers）
* 巨集處理程式（Macro Processors）
* 解譯程式（Interpreters）
* 編譯程式（Compilers）
* 載入程式（Loaders）
* 編修程式（Editors）
* 除錯程式（Debuggers）
* 通訊軟體（Communication Software）
* 資料庫管理系統（Data Base Management System）

## GCC(GNU Compiler Collection) 開發環境 使用方式 
GCC 是開放原始碼 (open source) 的跨平台編譯器 (compiler) ，支援編譯 C 、 C++ 、 Objective-C 、 Fortran 、 Ada 及 Go 等程式語言
### GCC流程圖

<img src = ".\GCC 執行流程圖.png">
<img src = ".\流程.png">

1. .c檔:編譯檔
2. .o檔:目的檔
3. .s檔:組合語言

### 輸出a.out

<img src = ".\輸出.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/00-hello (master)
$ gcc hello.c

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/00-hello (master)
$ ./a
hello !
```
1. 預設編譯出執行檔的檔案名稱為 a 
2. Mac 及 Linux 系統的副檔名為 .out 
3. MS-Windows 系統的副檔名為 .exe 

### 參數-o 

<img src = ".\輸出命名.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/00-hello (master)
$ gcc hello.c -o hello

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/00-hello (master)
$ ./hello
hello 
```
如果要指定執行檔的名稱，這需要加上參數 -o 及檔案名稱，例如 hello.c 編譯成 hello

## Id -- Gcc Linker

### 直接編譯連結

<img src = ".\多檔案編譯連結.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/02-link (master)
$ gcc main.c sum.c -o run

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/02-link (master)
$ ./run
sum(10)=55
```
### 只編譯不連結

<img src = ".\編譯不連結.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/01-basic (master)
$ gcc fib.c
C:/Program Files/codeblock/MinGW/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o):crt0_c.c:(.text.startup+0x2e): undefined reference to `WinMain'
collect2.exe: error: ld returned 1 exit status

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/01-basic (master)
$ gcc -c fib.c -o fib
```
1. 參數 -c 為"只編譯不連結"
2. 輸出為一目的檔(二進位格式),通常不會這摸做,除非單純輸出函式庫給別人使用

### 產生組合語言

<img src = ".\輸出組合語言.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/01-basic (master)
$ gcc -S fib.c -o fib.s
```

1. 參數 -S 為"輸出組合語言"，可從.s檔看到C語言轉匯成組合語言的格式 <br> :warning:參數"-S"必須為大寫"S"

### 將組合語言轉換為目的碼 (Object Code)

<img src = ".\組合轉目標.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/03-toolchain (master)
$ gcc -c sum.s -o sum.o
```
1. 參數"-c"依舊代表"只編譯不連結"，因此不會把printf之類的函式庫，這樣目的檔比較小，比較利於觀察
### C++  g++

<img src = ".\c++.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/04-cpp (master)
$ g++ hello.cpp -o hello

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/04-cpp (master)
$ ./hello
hello!
```
1. 當輸出 c++ 檔時,請使用 g++

## Make
### Makefile 特殊符號

```
$@ : 該規則的目標文件 (Target file)
$* : 代表 targets 所指定的檔案，但不包含副檔名
$< : 依賴文件列表中的第一個依賴文件 (Dependencies file)
$^ : 依賴文件列表中的所有依賴文件
$? : 依賴文件列表中新於目標文件的文件列表

?= 語法 : 若變數未定義，則替它指定新的值。
:= 語法 : make 會將整個 Makefile 展開後，再決定變數的值。
```

### 範例 

```
%.o: %.c
    gcc -c $< -o $@

$< : 屬於第一條件，也就是 foo.c
$@ : 屬於目標條件，也就是 foo.o
```

### make 特殊個案(windows 系統)

<img src = ".\win make change.png">

1. C:\Program Files\codeblock\MinGW\bin\mingw32-make.exe 為預設名稱，因此使用make函數時，都必須打"mingw32-make"，若嫌麻煩，可找出此.exe檔，複製後重新命名即可

### rm函式必須於GIT BASH才可使用

<img src = ".\git bash.png">
<img src = ".\powershell.png">

### make 執行檔
<img src = ".\make exe.png">

```
sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/05-make/01-makeExe (master)
$ make
gcc -std=c99 -O0    sum.c main.c -o run

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/05-make/01-makeExe (master)
$ make clean
rm -f *.o *.exe *.a run

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/05-make/01-makeExe (master)
$ make
gcc -std=c99 -O0    sum.c main.c -o run
```

1. 📔 -std=c99:此為嚴格規定使用語言
2. 📔 "-O0 ~ -O3" 為編譯成組合語言是否最佳化(由低到高)
### make 函式庫

<img src = ".\make 庫.png">

```

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/05-make/02-makeLib (master)
$ make
gcc -std=c99 -O0 -c sum.c -o sum.o
ar -r libstat.a sum.o
ar: creating libstat.a
gcc -std=c99 -O0 -c main.c -o main.o
gcc -std=c99 -O0 libstat.a main.o -L ./ -lstat -o run

sky@MSI MINGW64 ~/Desktop/VSCode  (GITHUB)/系統程式/sp/02-gcc/05-make/02-makeLib (master)
$ ./run
sum(10)=55
```
<br>
<br>
<br>
<br>
🖊️editor:Sky Lien