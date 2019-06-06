//#include "Book_in.h"
#include "book_out.h"

int main() {
	Book a("รปรแ", 20000, 300), b("นฬทก", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}