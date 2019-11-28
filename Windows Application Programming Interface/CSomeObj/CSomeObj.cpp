#include <windows.h>
#include <stdio.h>

class CSomeObj {
public:
	CSomeObj(){ printf("Constructor\n");  }
	~CSomeObj(){ printf("Destructor\n");  }
};

CSomeObj g_GlobalObj;

void main() {
	CSomeObj LocalObj;
//	ExitProcess(0);
}
