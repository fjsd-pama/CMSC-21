#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


typedef struct 
{
	int code;
	float price;
	char desc[20];	
} Item;

typedef struct
{
	int quantity;
	Item* item;
} ShoppingItem;

typedef struct 
{
	int item_count;
	ShoppingItem items[100];
} ShoppingCart;

float shop_item_cost(ShoppingItem shopItem)
{
	return shopItem.quantity * shopItem.item->price;
}

float total_cost(ShoppingCart cart)
{
	int total_cost = 0;
	for (int i = 0; i < cart.item_count; ++i)
	{
		ShoppingItem shop_item = (ShoppingItem)cart.items[i];
		float cost = shop_item_cost(shop_item);
		total_cost += cost;
	}
	return total_cost;
}

int main()
{
	Item laptop = {123, 20, "Macbook"};
	Item car = {234, 50, "Tesla 3"};

	ShoppingItem laptops = {2, &laptop};//40
	ShoppingItem cars = { 3, &car};//150->180
	ShoppingItem toys = { 2, &car};//100->120

	ShoppingCart cart = {3, {laptops, cars, toys}};//290

	printf("%.0f\n", total_cost(cart));

	car.price = 60;

	printf("%.0f\n", total_cost(cart));//should have changed to 340
}
