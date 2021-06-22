# :memo: 系統程式第八周筆記
### UNIX演變
<img src = './unix.gif'>

## glib 
<img src = './erf.PNG'>
<br><br>
<img src = './list.PNG'>

## POSIX (Portable Operating System Interface)
POSIX 表示可移植操作系統接口（Portable Operating System Interface，POSIX）。電氣和電子工程師協會（Institute of Electrical and Electronics Engineers，IEEE）最初開發 POSIX 標準，是為了提高 UNIX 環境下應用程序的可移植性。

具體的說 POSIX 是 IEEE 為要在各種 UNIX 操作系統上運行的軟件定義 API 所規定的一系列互相關聯的標準的總稱，而 X 則表明其對 Unix API 的傳承。
Linux 基本上逐步實現了 POSIX 兼容，但並沒有參加正式的 POSIX 認證。
當前的 POSIX 文檔分為三個部分：POSIX Kernel API，POSIX 命令和工具集，及 POSIX 一致性測試。
Posix 線程（POSIX threads，又稱 Pthreads）是負責 POSIX 的 IEEE 委員會開發的一套線程接口。
Linux 最初用的線程模型是 LinuxThread, 它不兼容 POSIX，而且存在一些性能問題，所以目前 Linux 摒棄了它，採用了基於 Pthreads 的 NPTL（Native POSIX Threads Library for Linux）模型， NPTL 修復了 LinuxThread 的許多缺點，並提供了更好的性能。

相對進程而言，執行緒是一個更加接近於執行體的概念，它可以與同進程中的其他執行緒共用資料，但擁有自己的棧空間，擁有獨立的執行序列。在串列程式基礎上引入執行緒和進程是為了提高程式的併發度，從而提高程式運行效率和回應時間。

執行緒和進程在使用上各有優缺點：

執行緒執行開銷小，但不利於資源的管理和保護；
而進程正相反。同時，執行緒適合於在SMP機器上運行，而進程則可以跨機器遷移