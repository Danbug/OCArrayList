#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct arrayList{
	int size;
	int capacity;
	int* array;
};

struct arrayList arrList;


void expand(){
	arrList.capacity *= 2;
	int * tmpPointer = malloc(arrList.capacity * sizeof(int));
	for(int i = 0 ; i <= arrList.size; i++){
		tmpPointer[i] = arrList.array[i];
	}
	free(arrList.array);
	arrList.array = tmpPointer;
//	realloc(arrList.array,arrList.capacity);
}

int get(int index){
	if(index < 0 || index >= arrList.size){
		return INT_MIN;
	}
	return arrList.array[index];
}

void insert(int index,int item){
	
	if(index < 0 || index > arrList.size){
		printf("OUT OF BOUNDS\n\n\n");
		return;
	}
	
	if(arrList.capacity == arrList.size){
		expand();
	}
	
	// shift to right
	for(int i = arrList.size ; i >= index; i--){
		arrList.array[i + 1] = arrList.array[i];
	}
	
	arrList.array[index] = item;
	arrList.size++;
}

int get(int index){
	if(index < 0 || index > arrList.size){
		printf("OUT OF BOUNDS\n\n\n");
		return INT_MIN;
	}
	
	return arrList.array[index];
}

void removeFromArrList(int index){
	if(index < 0 || index > arrList.size){
		printf("OUT OF BOUNDS\n\n\n");
		return;
	}
	
	// shift to left
	for(int i = index ; i < arrList.size; i++){
		arrList.array[i] = arrList.array[i + 1];
	}
	
	arrList.size--;
}

void set(int index , int item){
	if(index < 0 || index > arrList.size){
		printf("OUT OF BOUNDS\n\n\n");
		return;
	}
	
	arrList.array[index] = item;
	
}

void add(int toAdd){
	//printf("capacity = %d , size = %d\n", arrList.capacity, arrList.size);
	if(arrList.capacity == arrList.size){
		expand();
	}
	arrList.array[arrList.size] = toAdd;
	arrList.size++;
}

int size(){
	return arrList.size;
}

void printArrayList(){
	for(int i = 0 ; i < arrList.size ; i++){
		printf("%d ", arrList.array[i]);
	}
	printf("\n");
}


void initArrayList(){
	arrList.size = 0;
	arrList.capacity = 10;
	arrList.array = malloc(arrList.capacity * sizeof(int));
}

int main(int argc, char *argv[]) {
	initArrayList();
	for(int i = 0 ; i < 10 ; i++){
		add(i);
	}
	
	printArrayList();
	
	removeFromArrList(8);
	
	printArrayList();
	
	set(0,16);
	set(5, 15);
	
	printArrayList();
	
	free(arrList.array);
	return 0;
}