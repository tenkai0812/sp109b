# :memo: 系統程式第一周筆記
## :computer:何謂系統程式
課程名稱"系統程式"會被翻譯為system software 或 system programming，但這兩者卻並不相同。system software 稱作"系統軟體"，和他對應的正是application software，一個不負責任的說法就是:「system software是專門給程式設計師的軟體，application software是給大眾所使用的軟體」
從這可知道，組譯器、編譯器、虛擬機等等可稱作為system software，而office、adobe、browser則可稱作application software，但是如果是文字編輯器、資料庫管理這種軟體就不太能明確區分屬於system software 還是 application software了
## :book: 教學順序
<img src = "./順序.jpg">

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


### 輸出a.out

```
PS C:\Users\sky\Desktop\VSCode  (GITHUB)\系統程式\sp\02-gcc\00-hello> gcc hello.c
PS C:\Users\sky\Desktop\VSCode  (GITHUB)\系統程式\sp\02-gcc\00-hello> ./a.exe
hello !
```
1. 預設編譯出執行檔的檔案名稱為 a 
2. Mac 及 Linux 系統的副檔名為 .out 
3. MS-Windows 系統的副檔名為 .exe 
### 參數-o 

```
PS C:\Users\sky\Desktop\VSCode  (GITHUB)\系統程式\sp\02-gcc\00-hello> gcc hello.c -o hello
PS C:\Users\sky\Desktop\VSCode  (GITHUB)\系統程式\sp\02-gcc\00-hello> ./hello.exe
hello !
```
如果要指定執行檔的名稱，這需要加上參數 -o 及檔案名稱，例如 hello.c 編譯成 hello

