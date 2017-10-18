#include <stdio.h>

void swap(int* a, int* b, int* c) {
    int oldA = *a;
    int oldB = *b;
    int oldC = *c;
    *b = oldA;
    *c = oldB;
    *a = oldC;

}


int* maxOf2(int* a, int* b){
    if (*a > *b){
        return a;
    }
    
    return b;
}

int* maxOf3(int* a, int* b, int* c) {
    return maxOf2(maxOf2(a, b), c);

}

int main(){
    int a = 3;
    int b = 4;
    int c = 6;
    swap(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
	return 0;
}
