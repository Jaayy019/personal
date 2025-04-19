#include <iostream>
#include <vector>
using namespace std;

class Matrix {

private:

	vector<vector<int>> data;
	int rows;
	int cols;

public:

	//Constructor for instance variables
	Matrix(int r, int c, vector<vector<int>> nums) {

		rows = r;
		cols = c;
		data = nums;

	}

	//Transposes a matrix
	Matrix Transpose() {

		vector<vector<int>> toTranspose(cols, vector<int>(rows));

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < cols; j++) {

				toTranspose[j][i] = data[i][j];

			}

		}

		return Matrix(cols, rows, toTranspose);

	}

	//Overriding operator for plus sign
	Matrix operator+(const Matrix& other) {

		vector<vector<int>> toAdd(rows, vector<int>(cols));

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < cols; j++) {

				toAdd[i][j] = data[i][j] + other.data[i][j];

			}

		}

		return Matrix(cols, rows, toAdd);

	}

	//Overriding multiplication operator for matrix on matrix
	Matrix operator*(const Matrix& other)const {

		vector<vector<int>> toMult(rows, vector<int>(other.cols, 0));

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < other.cols; j++) {

				for (int k = 0; k < cols; k++) {

					toMult[i][j] += data[i][k] * other.data[k][j];

				}


			}

		}

		return Matrix(rows, other.cols, toMult);

	}

	//Operator overriding for scaling multiplication
	Matrix operator*(int num) {

		vector<vector<int>> toMult(rows, vector<int>(cols));

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < cols; j++) {

				toMult[i][j] = data[i][j] * num;

			}

		}

		return Matrix(rows, cols, toMult);

	}

	//Prints the matrix
	void ToPrint() {

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < cols; j++) {

				cout << data[i][j] << " ";

			}

			cout << endl;

		}

	}

};

int main() {

	//Initializes the matricies
	vector<vector<int>> a_nums = { {6, 4}, {8, 3} };
	vector<vector<int>> b_nums = { {1, 2, 3}, {4, 5, 6} };
	vector<vector<int>> c_nums = { {2, 4, 6}, {1, 3, 5} };

	Matrix A(2, 2, a_nums);
	Matrix B(2, 3, b_nums);
	Matrix C(2, 3, c_nums);

	Matrix D = A + (B * 3) * C.Transpose();

	D.ToPrint();

}