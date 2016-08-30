#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct {
	char name[20];
	int age;
	int studentNum;
} Student;

typedef struct {
	int x;
	int y;
} Point;

typedef struct{
	Point a;
	Point b;
} Line;

typedef struct{
	Line a;
	Line b;
} Polygon;

//Point, Point -> float
//Computes the distance between 2 points

/*//stub
float distance(Point one, Point two){
	return 0.0;
}

//template
float distance(Point one, Point two){
	return ... one.x one.y two.x two.y;
}
*/
float distance(Point one, Point two){
	return sqrt(pow((two.y - one.y), 2) + pow((two.x - one.x), 2));
}


//Line, Line -> bool
//Determines if two lines are parallel

/*//stub
bool isParallel(Line one, Line two){
	return false;
}

//template
bool isParallel(Line one, Line two){
	return ... one.a.x one.a.y one.b.x one.b.y
	    two.a.x two.a.y two.b.x two.b.y;
}*/

bool isParallel(Line one, Line two){
	return (((one.b.y - one.a.y)/(one.b.x - one.a.x)) == ((two.b.y - two.a.y)/(two.b.x - two.a.x)));
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


bool isWithinPolygon(Polygon r , Point p) {
    bool isXTrue = (p.x >= min(r.a.a.x, r.b.b.x) && p.x <= max(r.a.a.x, r.b.b.x));
    bool isYTrue = (p.y >= min(r.a.a.y, r.b.b.y) && p.y <= max(r.a.a.y, r.b.b.y));
    
    return (isXTrue && isYTrue);
}


//Polygon, Polygon -> bool
//Determines if two given polygons overlap each other

/*//stub
bool isOverlapping(Polygon one, Polygon two){
	return false;
}

//template
bool isOverlapping(Polygon one, Polygon two){
	return ... one.a.a.x one.a.a.y one.a.b.x one.a.b.x
}*/
bool isOverlapping(Polygon one, Polygon two){
	Point one1 = {one.a.a.x, one.a.a.y};
	Point one2 = {one.a.b.x, one.a.b.y};
	Point two1 = {two.a.a.x, two.a.a.y};
	Point two2 = {two.a.b.x, two.a.b.y};
	return ((isWithinPolygon(one, two1)) || (isWithinPolygon(one, two2)) || (isWithinPolygon(two, one1)) || (isWithinPolygon(two, one2)));
}


//Point, int, int -> Point
//Translate a point given the x and y movement

Point translate(Point sth, int x, int y){
	sth.x += x;
	sth.y += y;

	return (Point){sth.x, sth.y};
}


int main(){
	printf("STRUCTS NAKO... YEY! THANK YOU LORD :D\n");
	Point a = {2, 3};
	Point b = {3, 9};
	Point c = {9, 3};

	// Point a;
	// a.x = 2;
	// a.y = 3;

	Line a1 = {a, b};
	Line b1 = {c, b};
	Line c1 = {a, c};

	Point d = {-2, 1};
	Point e = {2, 1};
	Point f = {-2, -3};
	Point g = {2, -3};

	Line d1 = {d, e};
	Line e1 = {f, g};
	Polygon aa = {d1, e1};

	Point h = {1, -2};
	Point i = {3, -2};
	Point j = {1, -4};
	Point k = {3, -4};

	Line f1 = {h, i};
	Line g1 = {j, k};
	Polygon bb = {f1, g1};

	printf("%.2f\n", distance(a, b));

	printf("%d\n", isParallel(a1, b1));
	printf("%d\n", isParallel(a1, c1));
	printf("%d\n", isParallel(c1, b1));

	printf("%d\n", isOverlapping(aa, bb));
	printf("The new coordinates are [%d, %d].\n", translate(d, 2, -1));

	printf("\n\nTHANK YOU LORD, YOU ARE SO AMAZING. :)\n");
	printf("I will never stop praising you. I will worship you even in my weakness.\n");

	return 0;
}