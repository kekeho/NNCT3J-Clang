// 未完成

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
