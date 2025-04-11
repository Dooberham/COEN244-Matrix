//
// Created by Niall Cunningham on 2025-04-02.
//

#include "Matrix.h"
#include <stdexcept>
Matrix::Matrix(int rows1, int cols1, int value) { // Constructor to initialize a matrix with given rows, columns and value
    rows = rows1;
    cols = cols1;
    ptr = vector<vector<int>>(rows, vector<int>(cols, value)); // Initialize 2D vector with given value
}

Matrix::Matrix(int rows1, int cols1) {  // Constructor to initialize a matrix with given rows and columns
    rows = rows1;
    cols = cols1;
    ptr = vector<vector<int>>(rows, vector<int>(cols, 0)); // Initialize 2D vector with zeros
}





Matrix& Matrix::operator=(const Matrix &m) { // Copy assignment operator
    if (this != &m) {
        rows = m.rows;
        cols = m.cols;
        ptr = m.ptr; // Deep copy of the 2D vector
    }
    return * this;
}


vector<int>& Matrix::operator[] (int row) {
    static vector<int> error; // Static vector to return in case of error
    try {
        return ptr.at(row); // Access the row using at() to check for out of range
    } catch (const out_of_range &e) {
        cout << "Index out of range, returning empty vector. " << e.what() << endl;
        return error; // Re-throw the exception
    }
}

const vector<int>& Matrix::operator[] (int row) const {
    static vector<int> error;
    try {
        return ptr.at(row);
    } catch (const out_of_range &e) {
        cout << "Index out of range, returning empty vector. " << e.what() << endl;
        return error; // Re-throw the exception
    }
}


Matrix Matrix::operator+ (const Matrix& m) {
    try {
        if (rows != m.rows || cols != m.cols) {
            throw invalid_argument("These matrices are not the same size");
        }
        Matrix p(rows,cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                p[i][j] = ptr[i][j] + m[i][j];
            }

        }
        return p;
    } catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
        return Matrix(0,0,0);
    }
}

Matrix Matrix::operator-(const Matrix& m) const {
    try {
        if (rows!= m.rows || cols != m.cols) {
            throw invalid_argument("These matrices are not the same size");
        }
        Matrix p(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                p[i][j] = ptr[i][j] - m[i][j];
            }
        }
        return p;
    } catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
        return Matrix(0, 0,0);
    }
}

bool Matrix::operator== (const Matrix& m) const {
    return ptr == m.ptr;
}

bool Matrix::operator!= (const Matrix& m) const {
    return ptr != m.ptr;
}