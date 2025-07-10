#include <iostream>
#include <cassert>
using namespace std;

class Array {
private:
    int size;
    int* ptr;

public:
    Array() : size(0), ptr(nullptr) {}

    Array(int size_) : size(size_) {
        assert(size_ > 0);
        ptr = new int[size];
    }

    ~Array() {
        delete[] ptr;
        ptr = nullptr;
    }

    Array(const Array& other) : size(other.size) {
        ptr = new int[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = other.ptr[i];
    }

    Array& operator=(const Array& other) {
        if (this == &other)
            return *this;

        delete[] ptr;
        size = other.size;
        ptr = new int[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = other.ptr[i];

        return *this;
    }

    int getSize() const {
        return size;
    }

    int& operator[](int pos) {
        if (pos < 0 || pos >= size)
            throw out_of_range("Index out of range");
        return ptr[pos];
    }

    const int& operator[](int pos) const {
        if (pos < 0 || pos >= size)
            throw out_of_range("Index out of range");
        return ptr[pos];
    }

    Array& operator++() {
        for (int i = 0; i < size; ++i)
            ++ptr[i];
        return *this;
    }

    Array operator++(int) {
        Array temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const Array& other) const {
        if (size != other.size)
            return false;
        for (int i = 0; i < size; ++i)
            if (ptr[i] != other.ptr[i])
                return false;
        return true;
    }

    bool operator!=(const Array& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Array& arr) {
        for (int i = 0; i < arr.size; ++i)
            out << arr.ptr[i] << " ";
        return out;
    }
};

class Array2D {
private:
    int rows, cols;
    Array* vec;

public:
    Array2D() : rows(0), cols(0), vec(nullptr) {}

    Array2D(int r, int c) : rows(r), cols(c) {
        assert(r > 0 && c > 0);
        vec = new Array[rows];
        for (int i = 0; i < rows; ++i)
            vec[i] = Array(cols);
    }

    ~Array2D() {
        delete[] vec;
        vec = nullptr;
    }

    Array2D(const Array2D& other) : rows(other.rows), cols(other.cols) {
        vec = new Array[rows];
        for (int i = 0; i < rows; ++i)
            vec[i] = other.vec[i]; // Deep copy
    }

    Array2D& operator=(const Array2D& other) {
        if (this == &other)
            return *this;

        delete[] vec;
        rows = other.rows;
        cols = other.cols;
        vec = new Array[rows];
        for (int i = 0; i < rows; ++i)
            vec[i] = other.vec[i];

        return *this;
    }

    Array& operator[](int row) {
        if (row < 0 || row >= rows)
            throw out_of_range("Row index out of range");
        return vec[row];
    }

    const Array& operator[](int row) const {
        if (row < 0 || row >= rows)
            throw out_of_range("Row index out of range");
        return vec[row];
    }

    Array2D& operator++() {
        for (int i = 0; i < rows; ++i)
            ++vec[i];
        return *this;
    }

    Array2D operator++(int) {
        Array2D temp = *this;
        ++(*this);
        return temp;
    }

    int& operator()(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw out_of_range("Index out of range");
        return vec[row][col];
    }

    const int& operator()(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw out_of_range("Index out of range");
        return vec[row][col];
    }

    bool operator==(const Array2D& other) const {
        if (rows != other.rows || cols != other.cols)
            return false;
        for (int i = 0; i < rows; ++i)
            if (vec[i] != other.vec[i])
                return false;
        return true;
    }

    bool operator!=(const Array2D& other) const {
        return !(*this == other);
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    friend ostream& operator<<(ostream& out, const Array2D& arr2) {
        for (int i = 0; i < arr2.rows; ++i)
            out << arr2.vec[i] << "\n";
        return out;
    }
};

void test_Array() {
    Array arr1(6);
    int counter = 0;
    for (int i = 0; i < arr1.getSize(); ++i)
        arr1[i] = counter++;

    cout << arr1 << "\n";

    Array arr2 = ++arr1;
    cout << arr2 << "\n";

    if (arr2 == arr1)
        cout << "arr2 == arr1\n";
    else
        cout << "arr2 != arr1\n";

    Array arr3;
    arr3 = arr2++;
    cout << arr3 << "\n";

    if (arr3 != arr1)
        cout << "arr3 != arr1\n";
    else
        cout << "arr3 == arr1\n";
}

void test_Array2D() {
    Array2D arr1(2, 3);
    int counter = 0;

    for (int i = 0; i < arr1.getRows(); ++i)
        for (int j = 0; j < arr1.getCols(); ++j)
            arr1(i, j) = counter++;

    cout << arr1 << "\n";

    Array2D arr2 = ++arr1;
    cout << arr2 << "\n";

    if (arr2 == arr1)
        cout << "arr2 == arr1\n";
    else
        cout << "arr2 != arr1\n";

    Array2D arr3;
    arr3 = arr2++;
    cout << arr3 << "\n";

    if (arr3 != arr1)
        cout << "arr3 != arr1\n";
    else
        cout << "arr3 == arr1\n";
}

int main() {
    test_Array();
    test_Array2D();
    cout << "Bye\n";
    return 0;
}
