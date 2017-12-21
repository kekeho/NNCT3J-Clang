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
