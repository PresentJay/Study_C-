#include <iostream>
#define INF 999
#define MAX 6
using namespace std;

class Jay_Matrix {
private:
	int D[MAX+1][MAX][MAX];
	int P[MAX+1][MAX][MAX];
	int step;
public:
	Jay_Matrix(int[MAX][MAX]);
	Jay_Matrix() {}
	void print();
	void Nextstep();
};

void Jay_Matrix::print() {
	cout << endl << endl << "\t 현재 Step = " << step << endl;
	cout << "\t [최단거리 행렬D" << step << "] \t\t\t\t\t [최단경로 행렬P" << step << "] " << endl;
	cout << "\t - - - - - - - - - - - - - - - - - - - - \t\t - - - - - - - - - - - - - - - - - - - - " << endl;
	for (int i = 0; i < MAX; i++) {
		cout << '\t';
		for (int j = 0; j < MAX; j++) {
			if (D[step][i][j] != INF)
				cout << D[step][i][j] << '\t';
			else
				cout << "∞\t";
		}
		cout << " \t";
		for (int j = 0; j < MAX; j++) {
			cout << P[step][i][j] << '\t';
		}

		cout << endl;
	}
	cout << "\t - - - - - - - - - - - - - - - - - - - - \t\t - - - - - - - - - - - - - - - - - - - - " << endl;
}

void Jay_Matrix::Nextstep() {
	Jay_Matrix temp;
	for (int i = 0 ; i < MAX ; i++)
		for (int j = 0; j < MAX; j++) {
			if (D[step][i][step] + D[step][step][j] < D[step][i][j]) {
				P[step + 1][i][j] = step+1;
				D[step + 1][i][j] = D[step][i][step] + D[step][step][j];
			}
			else {
				P[step + 1][i][j] = P[step][i][j];
				D[step + 1][i][j] = D[step][i][j];
			}
		}
	step++;
}

Jay_Matrix::Jay_Matrix(int data[MAX][MAX]) {
	step = 0;
	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++) {
				if (k == step)
					D[step][i][j] = data[i][j];
				else
					D[k][i][j] = 0;
				P[k][i][j] = 0;
			}
	}
}

int main() {

	int src_input[MAX][MAX] = {
		{ 0, 7, INF, 11, INF, INF },
		{ 3, 0, INF, INF, 17, INF },
		{ INF, 6, 0, INF, INF, INF },
		{ INF, INF, INF, 0, 9, INF },
		{ INF, 5, 15, 16, 0, 2 },
		{ INF, INF, 11, INF, 8, 0 }
	};

	Jay_Matrix Src(src_input);
	cout << endl << endl << "\t2019 Algorithm, 20143174 정현재, 과제#2" << endl << "\t*\t*\t*" << endl << endl;

	Src.print();
	for (int i = 0; i < 6; i++) {
		Src.Nextstep();
		Src.print();
	}
}