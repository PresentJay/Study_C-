#include <iostream>
using namespace std;

class Matrix {
	int item_maximum;
	double** items;
public:
	Matrix(int);
	~Matrix();
	Matrix(const Matrix &);
	Matrix& operator= (const Matrix&);
	void set_ROW_items(int, int*);
	double get_Determinant();
	Matrix get_TransposedMatrix();
	Matrix get_AdjointMatrix();
	Matrix get_MinorMatrix(int, int);
	Matrix get_CofactorMatrix();
	Matrix get_InverseMatrix();
	void solution();
	void show_matrix();
};

Matrix::Matrix(int itemM) {
	item_maximum = itemM;
	items = new double*[itemM];
	for (int i = 0; i < itemM; i++) {
		items[i] = new double[itemM];
		memset(items[i], 0, sizeof(double)*itemM);
	}
}

Matrix::~Matrix() {
	if (items) {
		for (int i = 0; i < item_maximum; i++)
			delete[] items[i];
		delete[] items;
	}
}

Matrix::Matrix(const Matrix &matrix) {
	this->item_maximum = matrix.item_maximum;
	items = new double*[item_maximum];
	for (int i = 0; i < item_maximum; i++) {
		items[i] = new double[item_maximum];
		for (int j = 0; j < item_maximum; j++)
			items[i][j] = matrix.items[i][j];
	}
}

Matrix& Matrix::operator= (const Matrix& src) {
	if (this == &src)
		return *this;
	item_maximum = src.item_maximum;
	if (items) {
		for (int i = 0; i < item_maximum; i++)
			delete[] items[i];
		delete[] items;
	}
	items = new double*[item_maximum];
	for (int i = 0; i < item_maximum; i++) {
		items[i] = new double[item_maximum];
		for (int j = 0; j < item_maximum; j++)
			items[i][j] = src.items[i][j];
	}
	return *this;
}

void Matrix::set_ROW_items(int row, int* item) {
	for (int i = 0; i < item_maximum; i++)
		items[row][i] = item[i];
}

Matrix Matrix::get_TransposedMatrix() {
	Matrix tmp(item_maximum);
	for (int i = 0; i < item_maximum; i++)
		for (int j = 0; j < item_maximum; j++)
			tmp.items[i][j] = items[j][i];
	return tmp;
}

Matrix Matrix::get_AdjointMatrix() {
	Matrix tmp(item_maximum);
	Matrix tmp2(item_maximum);
	tmp2 = get_CofactorMatrix().get_TransposedMatrix();
	for (int i = 0; i < item_maximum; i++)
		for (int j = 0; j < item_maximum; j++)
			tmp.items[i][j] = (i + j) % 2 != 0 ? -(tmp2.items[i][j]) : tmp2.items[i][j];
	return tmp;
}

Matrix Matrix::get_MinorMatrix(int col, int row) {
	Matrix tmp(item_maximum - 1);
	int index_row = 0;
	int index_col = 0;
	int j;
	for (int i = 0; i < item_maximum; i++) {
		for (j = 0; j < item_maximum; j++) {
			if (i != row && j != col) {
				tmp.items[index_row][index_col] = items[i][j];
				index_col++;
			}
		}
		if (i != row && j != col) {
			index_col = 0;
			index_row++;
		}
	}
	return tmp;
}

Matrix Matrix::get_CofactorMatrix() {
	Matrix tmp(item_maximum);
	for (int i = 0; i < item_maximum; i++)
		for (int j = 0; j < item_maximum; j++)
			tmp.items[j][i] = get_MinorMatrix(i, j).get_Determinant();
	return tmp;
}

Matrix Matrix::get_InverseMatrix() {
	Matrix tmp(item_maximum);
	Matrix tmp2(item_maximum);
	double Det = get_Determinant();
	if (item_maximum == 2) {
		tmp2.items[0][0] = items[1][1];
		tmp2.items[1][1] = items[0][0];
		tmp2.items[0][1] = -(items[0][1]);
		tmp2.items[0][0] = -(items[1][1]);
		for (int i = 0; i < item_maximum; i++)
			for (int j = 0; j < item_maximum; j++)
				tmp.items[i][j] = (double)((double)1 / Det) * tmp2.items[i][j];
	}
	else {
		tmp2 = get_AdjointMatrix();
		for (int i = 0; i < item_maximum; i++)
			for (int j = 0; j < item_maximum; j++)
				tmp.items[i][j] = (double)((double)1 / Det) * tmp2.items[i][j];
	}
	return tmp;
}

double Matrix::get_Determinant() {
	double Det = 0;
	int flag = 1;
	if (item_maximum == 2)
		Det = items[0][0] * items[1][1] - items[1][0] * items[0][1];
	else
		for (int i = 0; i < item_maximum; i++) {
			Matrix minor(item_maximum - 1);
			minor = get_MinorMatrix(0, i);
			Det += flag * items[i][0] * minor.get_Determinant();
			flag *= -1;
		}
	return Det;
}

void Matrix::show_matrix() {
	cout << endl;
	for (int i = 0; i < item_maximum; i++) {
		cout << "|\t";
		for (int j = 0; j < item_maximum; j++)
			cout << items[i][j] << "\t";
		cout << "|" << endl;
	}
	cout << endl;
}

void Matrix::solution() {
	double Det = get_Determinant();
	show_matrix();
	cout << "해당 행렬의 역행렬여부를 판단하고," << endl << "존재한다면 역행렬을 구합니다." << endl << endl;

	cout << "1. 행렬식을 계산해, 가역적인지 판단합니다. (Det!=0)" << endl;
	if (Det) {
		cout << ">> 해당 행렬은 가역적입니다. (Det = " << Det << ")" << endl << "역행렬이 존재하므로 수반행렬을 통해 역행렬을 구합니다" << endl << endl;
		cout << "2. 해당 행렬의 소행렬식을 구합니다." << endl;
		get_CofactorMatrix().show_matrix();
		cout << "3. 해당 소행렬식의 수반행렬을 구합니다. (여인수행렬의 수반행렬)" << endl;
		get_AdjointMatrix().show_matrix();
		cout << "4. 수반행렬을 이용한 역행렬을 구합니다. (1/Det * Adj)" << endl;
		get_InverseMatrix().show_matrix();
	}
	else {
		cout << ">> 해당 행렬은 역행렬이 존재하지 않습니다. (Det=0)" << endl;
	}
}

int main() {
	cout.precision(2);
	Matrix p193_Q16_A(3);
	Matrix p193_Q16_B(3);
	Matrix p193_Q16_C(3);
	Matrix p193_Q17(4);
	int Q16_A[3][3] = { { 1,-2,-1 },{ 2,-3,1 },{ 3,-4,4 } };
	int Q16_B[3][3] = { { 1,2,3 },{ 2,6,1 },{ 3,10,-1 } };
	int Q16_C[3][3] = { { 1,3,-2 },{ 2,8,-3 },{ 1,7,1 } };
	int Q17[4][4] = { { 1,2,3,1 },{ -1,0,2,1 },{ 2,1,-3,0 },{ 1,1,2,1 } };
	for (int i = 0; i < 3; i++) {
		p193_Q16_A.set_ROW_items(i, Q16_A[i]);
		p193_Q16_B.set_ROW_items(i, Q16_B[i]);
		p193_Q16_C.set_ROW_items(i, Q16_C[i]);
		p193_Q17.set_ROW_items(i, Q17[i]);
	}
	p193_Q17.set_ROW_items(3, Q17[3]);

	p193_Q16_A.solution();
	system("pause");
	system("cls");
	p193_Q16_B.solution();
	system("pause");
	system("cls");
	p193_Q16_C.solution();
	system("pause");
	system("cls");
	p193_Q17.solution();
}
