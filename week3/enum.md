## 列舉ENUM
列舉 (enum 或 enumeration) 是另一種複合型別，主要是用在宣告僅有少數值的型別，像是一星期內的日期 (day of week) 或是一年內的月份等。透過列舉，我們可以在程式中定義數個獨一無二的符號 (symbol)
## 宣告列舉
使用 enum 保留字可以宣告列舉，如下例：
```
enum direction {
    North,
    South,
    East,
    West
};

int main(void)
{
    enum direction dest = East;
    
    return 0;
}
```
列舉同樣可用 typedef 簡化型別名稱，如下例:
```
/* Foreward declaration. */
typedef enum direction Direction;

enum direction {
    North,
    South,
    East,
    West
};

int main(void)
{
    Direction dest = East;
    
    return 0;
}
```
由於 C 語言的列舉本身沒有前綴，可以自行加入前綴，如下例:
```
typedef enum direction Direction;

/* Enum with prefix. */
enum direction {
    Direction_North,
    Direction_South,
    Direction_East,
    Direction_West
};

int main(void)
{
    Direction dest = Direction_East;
    
    return 0;
}
```
雖然前綴不是強制規定，許多程式設計者偏好此種風格，以減少命名空間衝突。

有些程式設計者會將列舉用全大寫來表示：
```
enum direction {
    DIRECTION_NORTH,
    DIRECTION_SOUTH,
    DIRECTION_EAST,
    DIRECTION_WEST
};
```
這種觀點將列舉視為一種常數 (constant)，實際上也是如此。這種寫法不是硬性規定，而是一種撰碼風格，讀者可自由選用。