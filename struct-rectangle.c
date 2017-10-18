#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct{
	int x;
	int y;
} Point;

typedef struct{
	Point upper_left;
	Point lower_right;
} Rectangle;

int area(Rectangle r){
	int horizontal_length = fabs(r.upper_left.y - r.lower_right.y);
	int vertical_length = fabs(r.upper_left.x - r.lower_right.x);

	return (horizontal_length * vertical_length);
}

Point center(Rectangle r) {
    float x = (r.upper_left.x + r.lower_right.x) / 2;
    float y = (r.upper_left.y + r.lower_right.y) / 2;
    
    return (Point){x, y};
}

Rectangle translate(Rectangle r, int x, int y) {
    Point newUpperLeft = {r.upper_left.x + x, r.upper_left.y + y};
    Point newLowerRight = {r.lower_right.x + x, r.lower_right.y + y};
    
    return (Rectangle){newUpperLeft, newLowerRight};
}


int min(int num1, int num2){
	if (num1 < num2){
		return num1;
	}

	return num2;
}

int max(int num1, int num2){
	if (num1 > num2){
		return num1;
	}

	return num2;
}


bool withinRectangle(Rectangle r, Point p) {
    bool isXTrue = (p.x >= min(r.lower_right.x, r.upper_left.x) && p.x <= max(r.upper_left.x, r.lower_right.x));
    bool isYTrue = (p.y >= min(r.lower_right.y, r.upper_left.y) && p.y <= max(r.upper_left.y, r.lower_right.y));
    
    return (isXTrue && isYTrue);
}

int main(){

	return 0;
}
