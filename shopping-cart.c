#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
	int code;
	char desc[30];
	float price;
} Item;

typedef struct{
	Item* name;
	int quantity;
} ShoppingItem;

typedef struct{
	int itemCount;
	ShoppingItem items[100];
} ShoppingCart;

//cart.items[i].name->code

//ShoppingItem -> int
//Accepts an item of type ShoppingItem and calculates
//the cost of the said item

/*int shoppingItemCOst(ShoppingItem item){
	return ... item.name.code, item.name.desc, item.name.price, item.quantity;
}*/

float shoppingItemCost(ShoppingItem item){
	return (item.name->price * item.quantity);
}

//ShoppingCart -> float
//Accepts a cart of type ShoppingCart and calculates
//the cost of the said cart

/*float totalCost(ShoppingCart cart){
	return ... cart.itemCount, ShoppingItem items[i].name,
}
*/
float totalCost(ShoppingCart cart){
	float total = 0;
	for (int i = 0; i < cart.itemCount; i++){
		total += shoppingItemCost(cart.items[i]);
	}
	return total;
}

/*//stub
Item* cheapestItem(ShoppingCart cart){
	return &cheapest;
}

//template
Item* cheapestItem(ShoppingCart cart){
	return ... cart.itemCount cart.items[i].name->price cart.items[i];
}*/

//ShoppingCart -> Item*
//Returns the address of the item with the least amount of price
Item* cheapestItem(ShoppingCart cart){
	Item* cheapest = cart.items[0].name; //No need '&' kay pointer naman siya daan
	for (int i = 0; i < cart.itemCount; i++){
		if ((cart.items[i].name->price) < cheapest->price){
			cheapest = cart.items[i].name;
		}
	}

	return cheapest;
}

/*//stub
Item* priciestItem(ShoppingCart cart){
	Item* priciest;
	return priciest;
}

//template
Item* priciestItem(ShoppingCart cart){
	Item* priciest;
	for (int i = 0; i < cart.itemCount; i++){
		...
	}
	return priciest;
}
*/

//ShoppingCart -> Item*
//Returns the address of the item (not shopping item) with the least greatest of price

Item* priciestItem(ShoppingCart cart){
	Item* priciest = cart.items[0].name;
	for (int i = 0; i < cart.itemCount; i++){
		if ((*(cart.items[i].name)).price > (*(priciest)).price){
			priciest = cart.items[i].name;
		}
	}
	return priciest;
}

/*//stub
float averagePrice(ShoppingCart cart){
	return 0.0;
}

//template
float averagePrice(ShoppingCart cart){
	return ... cart.itemCount cart.items[i] cart.items[i].name->price;
}
*/

//Shopping -> int
//Calculates the average price of the given cart
//by dividing the total price of the items (not the shopping item)
//over the number of itemCount
float averagePrice(ShoppingCart cart){
	float totalPrice = 0;
	for (int i = 0; i < cart.itemCount; i++){
		totalPrice += cart.items[i].name->price;
	}

	return (totalPrice / cart.itemCount);
}



int main(){
	Item LuckyMe = {235688, "Lucky Me Beef", 11.2};
	Item Condensada = {344568, "Angel Condensada, 300 ml", 35.6};
	Item HeadNShoulder = {3455889, "Head and Shoulder, 1 dozen", 46.89};
	Item CornedBeef = {1116732, "Argentina Corned Beef, 100 ml", 25.75};

	ShoppingItem LM1 = {&LuckyMe, 6};
	ShoppingItem LM2 = {&LuckyMe, 4};
	
	ShoppingItem Condensada1 = {&Condensada, 5};
	ShoppingItem Condensada2 = {&Condensada, 8};
	
	ShoppingItem HNS1 = {&HeadNShoulder, 7};
	ShoppingItem HNS2 = {&HeadNShoulder, 12};

	ShoppingItem CB1 = {&CornedBeef, 3};
	ShoppingItem CB2 = {&CornedBeef, 9};

	ShoppingCart Krishia = {4, {LM1, Condensada1, HNS1, CB1}};
	ShoppingCart SirJJ = {4, {LM2, Condensada2, HNS2, CB2}};

	printf("This is a test for function shoppingItemCost:\n");
	printf("%.2f\n", shoppingItemCost(LM1));
	printf("%.2f\n", shoppingItemCost(LM2));
	printf("%.2f\n", shoppingItemCost(Condensada1));
	printf("%.2f\n", shoppingItemCost(Condensada2));
	printf("%.2f\n", shoppingItemCost(HNS1));
	printf("%.2f\n", shoppingItemCost(HNS2));
	printf("%.2f\n", shoppingItemCost(CB1));
	printf("%.2f\n", shoppingItemCost(CB2));

	printf("This is a test for function totalCost;\n");
	printf("%.2f Php\n", totalCost(Krishia));
	printf("%.2f Php\n", totalCost(SirJJ));

	printf("This is a test for function cheapestItem:\n");
	printf("%p\n", cheapestItem(Krishia));
	printf("%.2f\n", (cheapestItem(Krishia))->price);

	printf("This is a test for function averagePrice:\n");
	printf("29.86 == %.2f\n", averagePrice(Krishia));
	printf("29.86 == %.2f\n", averagePrice(SirJJ));

	printf("This is a test for function priciestItem:\n");
	printf("%p\n", priciestItem(Krishia));
	printf("%.2f\n", (priciestItem(Krishia))->price);
	 
	return 0;
}