#include <iostream>
#define INF 999
#define MAX 6
using namespace std;

class Jay_Matrix{
    private:
        int D[MAX][MAX];

    public:
        Jay_Matrix(int[][]);
        print();
};

Jay_Matrix::print(){
    cout << "--------------------" << endl;
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            if (D[i][j] != INF)
                cout << D[i][j] << '\t';
            else
                cout << '∞\t';
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

Jay_Matrix::Jay_Matrix(int data[][]){
    for (int i=0; i<MAX; i++)
        for (int j=0; j<MAX; j++)
            D[i][j] = data[i][j];
}

int main(){

    Jay_Matrix Src({
        {   0,   7, INF,  11, INF, INF },
        {   3,   0, INF, INF,  17, INF },
        { INF,   6,   0, INF, INF, INF },
        { INF, INF, INF,   0,   9, INF },
        { INF,   5,  15,  16,   0,   2 },
        { INF, INF,  11, INF,   8,   0 }
    });

    cout << "2019 Algorithm, 20143174 정현재, 과제#2" << endl << "* * *" << endl << "입력값 확인" << endl << endl;

    Src.print();
}