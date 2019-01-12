#include <iostream>
#include <vector>
#include "matrix.h"


int main()
{

    CMatrix <int> inderMatrix1(3,5);
    std::cout << inderMatrix1;

    CMatrix <int> inderMatrix2;
    inderMatrix2.transposeMatrix(inderMatrix1);
    std::cout << inderMatrix2;


    return 0;
}
