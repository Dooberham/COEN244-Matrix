//
// Created by Niall Cunningham on 2025-04-02.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    Matrix(int, int, int); // constructor to initialize a matrix with given rows, columns and value
    Matrix(int,int); // constructor to initialize a matrix with given rows and columns



    int getcols() const; // returns the number of columns
    int getrows() const; // returns the number of rows

    vector<int>& operator[] (int); //used to access individual elements of the 2d array
    const vector<int>& operator[] (int) const;
    Matrix& operator=(const Matrix &); //used to copy arrays
    Matrix operator+ (const Matrix &); //used to add two arrays
    Matrix operator- (const Matrix &) const; //used to subtract two arrays
    bool operator== (const Matrix &) const; //used to compare two arrays
    bool operator!= (const Matrix &) const; //used to compare two arrays


private:
    int cols; // number of columns
    int rows; // number of rows
    vector<vector<int>> ptr; // 2D vector to store the matrix elements
};



#endif //MATRIX_H
