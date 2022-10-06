#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// int get(int index){
// 	if(index < 0 || index >= arrList.size){
// 		return INT_MIN;
// 	}
// 	return arrList.array[index];
// }

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
	int menu = 1;
	while(menu != 0){
		printf("1 - Print ArrayList\n");
		printf("2 - Add\n");
		printf("3 - Insert\n");
		printf("4 - Size\n");
		printf("5 - Remove\n");
		printf("6 - Set\n");
		printf("7 - Get\n");
		printf("0 - Exit\n");
		printf("Enter: ");
		scanf("%d",&menu);
		switch (menu)
		{
		case 1:{
			printArrayList();
			break;
		}
		case 2:{
			printf("Enter int that you want to add : ");
			int toAdd = 0;
			scanf("%d",&toAdd);
			add(toAdd);
			break;
		}
		case 3:{
			printf("Enter index where you want to place your item : ");
			int index = 0;
			scanf("%d",&index);
			printf("Enter int that you want to add : ");
			int item = 0;	
			scanf("%d",&item);					
			insert(index,item);
			break;
		}
		case 4:{
			printf("Size = %d\n", size());
			break;
		}
		case 5:{
			printf("Enter index to remove: ");
			int index = 0;
			scanf("%d", &index);
			removeFromArrList(index);
			break;
		}
		case 6:{
			printf("Enter index where you want to replace your item : ");
			int index = 0;
			scanf("%d",&index);
			printf("Enter int that you want to add : ");
			int item = 0;	
			scanf("%d",&item);					
			set(index,item);
			break;
		}
		case 7:{
			printf("Enter index that you want to recieve : ");
			int index = 0;
			scanf("%d",&index);
			printf("Recieved = %d ",get(index));
			break;
		}		
		case 0:{
			printf("GoodBye!\n\n");
			break;
		}			
		
		default:{
			printf("Unkwnown input!\n");
			break;
		}
			
		}
	}
	
	free(arrList.array);
	return 0;
}