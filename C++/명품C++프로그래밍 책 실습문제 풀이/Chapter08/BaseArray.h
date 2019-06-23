#ifndef BASEARRAY_h
#define BASEARRAY_h
#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity = 100) { this->capacity = capacity; mem = new int[capacity]; }
	~BaseArray() { delete[]mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int index;
public:
	MyQueue(int number) : BaseArray(number) { index = 0; }
	void enqueue(int number) { index++; put(index - 1, number); }
	int capacity() { return getCapacity(); }
	int length() { return index; }
	int dequeue() { int cashData = get(0); for (int i = 0; i < index - 1; i++) put(i, get(i + 1)); put(index - 1, NULL); index--; return cashData; }
};

class MyStack : public BaseArray {
	int index;
public:
	MyStack(int number) : BaseArray(number) { index = 0; }
	void push(int number) { index++; put(index-1, number);}
	int capacity() { return getCapacity(); }
	int length() { return index; }
	int pop() { int cashData = get(index-1); put(index-1, NULL); index--; return cashData; }
};

#endif // !BASEARRAY_H
