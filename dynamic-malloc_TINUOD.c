#include <stdlib.h>
#include <stdio.h>

#define ENLARGE_FACTOR 2.0
#define SHRINK_FACTOR 0.5

//global variables
int count;//number of elements
int* ar;//array
int size;//size of the array

int* createArray(int size);
void addElement(int element);
void removeElement(int element);
int* resizeArray(double factor);
void printElements();
void destroy();

void printElements()
{
	for (int i = 0; i < count; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

void addElement(int element)
{
	if (count > (size / 2))
	{
		ar = resizeArray(ENLARGE_FACTOR);
	}
	ar[count] = element;
	count++;
}

void printArr(int* arr, int count){
    for (int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void removeElement(int element)
{
    int* temp = ar;
	int indexToBeRemoved = 0;
	for (int i = 0; i < count; i++){
		if (ar[i] == element){
			indexToBeRemoved = i;
			count--;
		}
	}

	for (int k = 0; k < indexToBeRemoved; k++){
		ar[k] = temp[k];
	}

	for (int j = indexToBeRemoved; j < (count + 1); j++){
		ar[j] = temp[j + 1];
	}

	if (count < (size / 2)){
		ar = resizeArray(SHRINK_FACTOR);
	}
}

void destroy()
{
	free(ar);
	ar = NULL;
}

int* createArray(int size)
{
	count = 0;
	int* p = (int*)calloc(size, sizeof(int));
	return p;
}
int* resizeArray(double factor)
{
	size = size * factor;
	int* p = (int*)realloc(ar, size * sizeof(int));
	return p;
}

int main()
{
	size = 4;
	ar = createArray(size);
	addElement(3);
	addElement(4);
	addElement(5);
	addElement(6);
	addElement(7);
	printElements();
	removeElement(6);
	printElements();
	removeElement(5);
	printElements();
	removeElement(4);
	printElements();
	removeElement(3);
	printElements();
	removeElement(7);
	printElements();
	
	//end statement
	destroy();
}
