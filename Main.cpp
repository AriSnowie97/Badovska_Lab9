#include <iostream>
using namespace std;

struct Matrix2x2 {
    double elements[2][2];
    Matrix2x2() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                elements[i][j] = 0.0;
            }
        }
    }
    Matrix2x2(double a, double b, double c, double d) {
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }
    Matrix2x2 operator+(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }
    Matrix2x2 operator-(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.elements[i][j] = elements[i][j] - other.elements[i][j];
            }
        }
        return result;
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.elements[i][j] =
                    elements[i][0] * other.elements[0][j] +
                    elements[i][1] * other.elements[1][j];
            }
        }
        return result;
    }
    
    void print() const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix2x2 matrix1(1, 2, 3, 4);
    Matrix2x2 matrix2(2, 1, 4, 3);

    Matrix2x2 sum = matrix1 + matrix2;
    Matrix2x2 difference = matrix1 - matrix2;
    Matrix2x2 product = matrix1 * matrix2;

    cout << "THe first matrix:\n";
    matrix1.print();

    cout << "The second matrix:\n";
    matrix2.print();

    cout << "Sum of matrix:\n";
    sum.print();

    cout << "Difference of matrix:\n";
    difference.print();

    cout << "Plural of matrix:\n";
    product.print();

    return 0;
}
