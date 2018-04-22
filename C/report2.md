# 課題4

## プログラムソース
```c
#include <stdio.h>

int main(){
	struct bin{
	char name[30];
	int quantity;
	int cost;
	};
	
	struct bin printer_cable_box;
	struct bin terminal_cable_box;
	struct bin network_cable_box;
	
	printer_cable_box.cost = 500;
	printer_cable_box.quantity = 10;
	int printer_total_cost = printer_cable_box.cost * printer_cable_box.quantity;
	
	terminal_cable_box.cost = 700;
	terminal_cable_box.quantity = 20;
	int terminal_total_cost = terminal_cable_box.cost * terminal_cable_box.quantity;

	network_cable_box.cost = 300;
	network_cable_box.quantity = 25;
	int network_total_cost = network_cable_box.cost * network_cable_box.quantity;

	printf("Printer cable:\t%d\n", printer_total_cost);
	printf("Terminal cable:\t%d\n", terminal_total_cost);
	printf("Network cable:\t%d\n", network_total_cost);
}

```
## プログラムの説明
構造体を定義して、プリンターケーブル・ターミナルケーブル・ネットワークテーブルが格納されている箱と見立てる。  
そして各箱ごとに金額を計算するプログラムである。
## 実行結果
Printer cable:  5000
Terminal cable: 14000
Network cable:  7500
## 実行結果の特徴
無事に総額が計算されている
## 考察
構造体を用いることで違う型のものもまとめることができる。非常に使い勝手が良い。

# 課題5
## ソースコード
```c
#include <stdio.h>

typedef struct {
    char name[30];
    int quantity;
    int cost;
} BIN;

BIN amount (BIN, BIN, BIN);

int main(void) {
    BIN printer_cable_box = {"Printer cable", 10, 500};
    BIN terminal_cable_box = {"Terminal cable", 20, 700};
    BIN network_cable_box = {"Network cable", 25, 300};
    
    BIN total = amount(
        printer_cable_box,
        terminal_cable_box,
        network_cable_box
    );
    
    printf("quantity:\t%d\ncost:\t%d\n", total.quantity, total.cost);
    
    return 0;
}

BIN amount(BIN printer, BIN terminal, BIN network){
    int quantity_sum = printer.quantity + terminal.quantity + network.quantity;
    int cost_sum = printer.quantity * printer.cost 
    + terminal.quantity * terminal.cost 
    + network.quantity * network.cost;
    BIN total = {"Total", quantity_sum, cost_sum};
    return total;

}
```
## プログラムの説明
今回は課題4の総額の計算処理を関数化した。
## 実行結果
```
quantity:       55
cost:   26500
```
## 実行結果の特徴
関数化することで全体の計算処理の記述がしやすくなった
## 考察
関数で構造体を扱う方法を思い出すこととなった。

# 課題6
## プログラムソース
```c
#include <stdio.h>

typedef struct {
    char name[30];
    int quantity;
    int cost;
} BIN;

BIN amount(BIN *, BIN *, BIN *);

int main(void) {
    BIN printer_cable_box = {"Printer cable", 10, 500};
    BIN terminal_cable_box = {"Terminal cable", 20, 700};
    BIN network_cable_box = {"Network cable", 25, 300};
    
    BIN total = amount(
        &printer_cable_box,
        &terminal_cable_box,
        &network_cable_box
    );
    
    printf("quantity:\t%d\ncost:\t%d\n", total.quantity, total.cost);
    
    return 0;
}

BIN amount(BIN *printer, BIN *terminal, BIN *network){
    int quantity_sum = printer->quantity + terminal->quantity + network->quantity;
    int cost_sum = printer->quantity * printer->cost 
    + terminal->quantity * terminal->cost 
    + network->quantity * network->cost;
    BIN total = {"Total", quantity_sum, cost_sum};
    return total;

}
```
## プログラムの説明
課題5をポインタを使うように改良した。
## 実行結果
```
quantity:       55
cost:   26500
```
## 実行結果の特徴
当たり前だが、課題5と変わらない。
## 考察
ポインタを使うよう変更することでメモリを節約できていると考えられる。

# 課題7
## プログラムソース
```c
#include <stdio.h>
#define True 1
#define False 0
#define MAX 4

typedef struct{
    int hour;
    int minute;
    int second;
} time;

int main(){
    time lap[MAX] = {0, 0, 0};
    time sum = {0, 0, 0};
    int hour_buffer;
    int min_buffer;
    int sec_buffer;

    for(int i = 0; i < MAX; i++){
        printf("INPUT TIME (hour minute second): ");
        scanf("%d %d %d", &hour_buffer, &min_buffer, &sec_buffer);

        //time formatting
        if(sec_buffer >= 60){
            min_buffer += sec_buffer / 60;
            sec_buffer = sec_buffer % 60;
        }
        if(min_buffer >= 60){
            hour_buffer += min_buffer / 60;
            min_buffer = min_buffer % 60;
        }

        lap[i].hour = hour_buffer;
        lap[i].minute = min_buffer;
        lap[i].second = sec_buffer;
        
        sum.hour += hour_buffer;
        sum.minute += min_buffer;
        sum.second += sec_buffer;
    }

    //time formatting
    if(sum.second >= 60){
        sum.minute += sum.second / 60;
        sum.second = sum.second % 60;
    }
    if(sum.minute >= 60){
        sum.hour += sum.minute / 60;
        sum.minute = sum.minute % 60;
    }
    printf("H:\t%d\nM:\t%d\nS:\t%d\n", sum.hour, sum.minute, sum.second);

}
```

## プログラムの説明
構造体を用いてラップタイマーを作成する

## 実行結果
```
INPUT TIME (hour minute second): 1 1 312
INPUT TIME (hour minute second): 1 1 1
INPUT TIME (hour minute second): 1 1 3
INPUT TIME (hour minute second): 0 32 1
H:      3
M:      40
S:      17
```

## 実行結果の特徴
分・秒において繰り上げ計算も自分で作成したので、自動的に繰り上がりが行われている。

## 考察
構造体配列の使い方を思い出すことが出来た。

# 課題8
## プログラムソース
```c
#include <stdio.h>
#define True 1
#define False 0
#define MAX 4

typedef struct{
    int hour;
    int minute;
    int second;
} TIME;

TIME sumcal(TIME *);

int main(){
    TIME lap[MAX] = {0, 0, 0};
    int hour_buffer;
    int min_buffer;
    int sec_buffer;

    for(int i = 0; i < MAX; i++){
        printf("INPUT TIME (hour minute second): ");
        scanf("%d %d %d", &hour_buffer, &min_buffer, &sec_buffer);

        //time formatting
        if(sec_buffer >= 60){
            min_buffer += sec_buffer / 60;
            sec_buffer = sec_buffer % 60;
        }
        if(min_buffer >= 60){
            hour_buffer += min_buffer / 60;
            min_buffer = min_buffer % 60;
        }

        lap[i].hour = hour_buffer;
        lap[i].minute = min_buffer;
        lap[i].second = sec_buffer;
    }

    TIME sum = sumcal(lap);
    printf("H:\t%d\nM:\t%d\nS:\t%d\n", sum.hour, sum.minute, sum.second);

}

TIME sumcal(TIME lap[]){
    TIME sum = {0, 0, 0};

    for(int i = 0; i < MAX; i++){
        sum.hour += lap[i].hour;
        sum.minute += lap[i].minute;
        sum.second += lap[i].second;
    }
    
    //time formatting
    if(sum.second >= 60){
        sum.minute += sum.second / 60;
        sum.second = sum.second % 60;
    }
    if(sum.minute >= 60){
        sum.hour += sum.minute / 60;
        sum.minute = sum.minute % 60;
    }
    return sum;
}
```

## プログラムの説明
課題7の合計タイムの計算を関数化した

## 実行結果
```
INPUT TIME (hour minute second): 1 1 312
INPUT TIME (hour minute second): 1 1 1
INPUT TIME (hour minute second): 1 1 3
INPUT TIME (hour minute second): 0 32 1
H:      3
M:      40
S:      17
```

## 実行結果の特徴
当たり前だが課題7の実行結果と同じになっている。

## 考察
構造体配列を引数に取る関数の作成を久しぶりに思い出せた。