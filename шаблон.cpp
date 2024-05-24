#include <iostream>

template <typename T>
int findSecondMax(T* arr, int size) {
    int maxIndex = 0, secondMaxIndex = -1;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            secondMaxIndex = maxIndex;
            maxIndex = i;
        }
        else if (secondMaxIndex == -1 || arr[i] > arr[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }
    return secondMaxIndex;
}

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols]();
        }
    }

    T* operator[](int index) const {
        return data[index];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

template <typename T>
class Vector : public Matrix<T> {
public:
    Vector(int size) : Matrix<T>(1, size) {}

    T dotProduct(Vector<T>& v) {
        T result = 0;
        for (int i = 0; i < this->getCols(); i++) {
            result += (*this)[0][i] * v[0][i];
        }
        return result;
    }

    T scalarProduct(Vector<T>& v) {
        T result = 0;
        for (int i = 0; i < this->getCols(); i++) {
            result += (*this)[0][i] * v[0][i];
        }
        return result;
    }
};

int main() {
    float arr[] = { 3.14, 2.71, 1.41, 1.73 };
    int arrSize = 4;
    int secondMaxIndex = findSecondMax(arr, arrSize);
    std::cout << "Index of the second maximum element in the array: " << secondMaxIndex << std::endl;

    Matrix<double> mat(2, 2);
    mat[0][0] = 1.2;
    mat[0][1] = 3.4;
    mat[1][0] = 5.6;
    mat[1][1] = 7.8;

    Vector<double> vec(2);
    vec[0][0] = 1.0;
    vec[0][1] = 2.0;

    std::cout << "Dot product: " << vec.dotProduct(vec) << std::endl;
    std::cout << "Scalar product: " << vec.scalarProduct(vec) << std::endl;

    return 0;
}
