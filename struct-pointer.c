#include "stdio.h"

typedef struct {
  int code;
  char desc[30];
  float price;
} Item;

typedef struct {
  Item* itemptr;
  int quantity;
} ShoppingItem;

typedef struct {
  int itemCount;
  ShoppingItem items[100];
} ShoppingCart;


float shoppingItemCost(ShoppingItem item) {
  return item.itemptr->price * item.quantity;
}

float totalCost(ShoppingCart cart) {
  float total = 0.0;
  for (int i = 0; i < cart.itemCount; i++) {
	total = total + shoppingItemCost(cart.items[i]);
  }
  return total;
}
Item* Cheapest(ShoppingCart cart) {
	Item* cheapItem = cart.items[0].itemptr;
	for (int i = 0; i < cart.itemCount; i++) {
		if (cheapItem->price > cart.items[i].itemptr->price) {
			cheapItem = cart.items[i].itemptr;
		}
	}
	return cheapItem;
}

Item* Priciest(ShoppingCart cart) {
	Item* cheapItem = cart.items[0].itemptr;
	for (int i = 0; i < cart.itemCount; i++) {
		if (cheapItem->price < cart.items[i].itemptr->price) {
			cheapItem = cart.items[i].itemptr;
		}
	}
	return cheapItem;
}

float averagePrice(ShoppingCart cart) {
	float totalPrice = 0.0;
	for (int i = 0; i < cart.itemCount; i++) {
		totalPrice = totalPrice + cart.items[i].itemptr->price;
	}
	return totalPrice / cart.itemCount;
}

int totalNumOfItems(ShoppingCart cart) {
	int count = 0;
	for (int i = 0; i < cart.itemCount; i++) {
		count = count + cart.items[i].quantity;
	}
	return count;
}

float averageCost(ShoppingCart cart) {
	return (totalCost(cart) / totalNumOfItems(cart));
}

int main() {
	Item Creamsilk = {0001,"Conditioner",7.0};
	Item Safeguard = {0002,"Germicidal Soap",5.0};
	ShoppingItem Conditioner = {&Creamsilk, 6};
	ShoppingItem Soap = {&Safeguard, 1};
	ShoppingCart Cart1 = {1, {Conditioner}};
	ShoppingCart Cart2 = {1, {Soap}};
	ShoppingCart Cart3 = {2, {Conditioner, Soap}};

	printf("%f == %f\n", shoppingItemCost(Conditioner), 7.0 * 6);
	printf("%f == %f\n", shoppingItemCost(Soap), 7.0 * 1);
	printf("%f == %f\n", totalCost(Cart2), 7.0 * 1);
	printf("%f == %f\n", totalCost(Cart1), 7.0 * 6);
	printf("%f\n", totalCost(Cart3));
	printf("%p == %p\n", Cheapest(Cart1), &Creamsilk);
	printf("%p == %p\n", Cheapest(Cart2), &Safeguard);
	printf("%p == %p\n", Cheapest(Cart3), &Safeguard);
	printf("%p == %p\n", Priciest(Cart1), &Creamsilk);
	printf("%p == %p\n", Priciest(Cart2), &Safeguard);
	printf("%p == %p\n", Priciest(Cart3), &Creamsilk);
	printf("%f == %f\n", averagePrice(Cart1), Creamsilk.price);
	printf("%f == %f\n", averagePrice(Cart2), Safeguard.price);
	printf("%f == %f\n", averagePrice(Cart3), (Creamsilk.price + Safeguard.price) / 2);
	printf("%d == 7\n", totalNumOfItems(Cart3));
	printf("%f == 6.714\n", averageCost(Cart3));
  return 0;
}
