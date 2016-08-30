#include <stdio.h>

// The Kapehan coffee shop sells coffee beans at P850 per kilo
//plus the cost of shipping. Each order ships for P185 per kilo
//plus P250 fixed cost per shipment for overhead. This function
//calculates the cost of an order.

//float -> float
//Calculates the cost of an order given the number of kilos
//of coffee beans

/*stub
float costOfOrder(float kilos){
	return 0.0;
}*/


#define COFFEE_BEAN_PER_KILO 850
#define SHIPPING_COST_PER_KILO 185
#define SHIPPING_COST_FOR_OVERHEAD 250

/*template
float costOfOrder(float kilos){
	return ... COFFEE_BEAN_PER_KILO SHIPPING_COST_PER_KILO SHIPPING_COST_FOR_OVERHEAD kilos;
}
*/

float costOfOrder(float kilos){
    if (kilos > 0){
        return (COFFEE_BEAN_PER_KILO * kilos) + (SHIPPING_COST_PER_KILO * kilos) + SHIPPING_COST_FOR_OVERHEAD;
    }
	return 0;
}

int main() {
    printf("1285.00 == %.2f\n", costOfOrder(1));
    printf("0 == %.2f\n", costOfOrder(0));
    printf("767.50 == %.2f\n", costOfOrder(0.5));
    printf("2320.00 == %.2f\n", costOfOrder(2));
    return 0;
}