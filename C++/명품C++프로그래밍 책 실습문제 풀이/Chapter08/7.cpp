#include <iostream>
using namespace std;

class BaseMemory {
	char *mem;
protected:
	BaseMemory(int size=1) { mem = new char[size]; }
	void setmem(int index, int src) { mem[index] = src; }
	char getmem(int index) { return mem[index]; }
};

class ROM : public BaseMemory {
	int dataSize;
public:
	ROM(int dataSize, char* str, int capacity) : BaseMemory(capacity)  { this->dataSize = dataSize; for (int i = 0; i < capacity; i++) setmem(i, str[i]); }
	char read(int index) { return getmem(index); }
};

class RAM : public BaseMemory {
	int dataSize;
public:
	RAM(int dataSize) : BaseMemory(dataSize / (1024 * 512)) { this->dataSize = dataSize; }
	void write(int index, char data) { setmem(index, data); }
	char read(int index) { return getmem(index); }
};

int main() {
	char x[5] = { 'h', 'e', 'l', 'l', 'o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
	cout << endl;
}
