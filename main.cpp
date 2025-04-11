#include <iostream>
#include "Matrix.h"

int main() {

   Matrix m1(3,3,2); // initialize a 3x3 matrix with all elements set to 2

   Matrix m2(3,3,1); // initialize a 3x3 matrix with all elements set to 1


    Matrix c = m1 + m2; // add the two matrices

    cout << c[0][0] << endl;  // print the first element of the result matrix, should be 3


    Matrix d = m1 - m2; // subtract the two matrices

    cout << d[0][0] << endl; // print the first element of the result matrix, should be 1

    cout << ( c == d) << endl; // check if the two matrices are equal, should be false
    cout << ( c != d) << endl; // check if the two matrices are not equal, should be true


    return 0;
}
