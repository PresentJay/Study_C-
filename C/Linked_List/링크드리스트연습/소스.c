#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(first) (!(first))

typedef struct listNode *listPointer;
typedef struct {
	int data;
	listPointer link;
} listNode;

listPointer create2() {
	listPointer first, second;
	first = (listPointer)malloc( sizeof(*listPointer));
	second = (listPointer) malloc(sizeof(*listPointer));
	
	
}
