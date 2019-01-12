#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
template <class T> class CMatrix
{
private:
    unsigned int rows, colm; //hold the size of matrix

public:
    std::vector<std::vector<T> > myMatrix; //created a vector of vector type bidimensional object
    CMatrix() { rows=colm=0;} //constructor 1 : default contrsuctor
    CMatrix(unsigned int); //constructor 2 : receives only 1 parameter to build identity matrix
    CMatrix(unsigned int, unsigned int);//constructor 3 : receives the size of matrix (rows & columns) as parameter to build a matrix
    unsigned int getRows() const; //these are my accessors, this one will give me no of rows and it can not be changed (manipulated)
    unsigned int getColm() const; //these are my accessors, this one will give me no of columns and it can not be changed (manipulated)
    void buildMatrix();
    void displayMatrix();
    void addMatrix(CMatrix, CMatrix);
    void subtractMatrix(CMatrix, CMatrix);
    void multiplyMatrix(CMatrix, CMatrix);
    void transposeMatrix(CMatrix);
    T traceMatrix();
    ~CMatrix() {}
};

template <class T>
unsigned int CMatrix<T>::getRows() const
{
    return rows;
}

template <class T>
unsigned int CMatrix<T>::getColm() const
{
    return colm;
}



//reference engineer4free on youtube
//this will build a matrix of size m x n of some random values
template <class T>
CMatrix<T>::CMatrix(unsigned int m, unsigned int n)
{
    rows = m;
    colm = n;
    //build nested for loops to enter values in the matrix using std::vectors
    for (unsigned int i=0; i<rows ; i++)
    {
        std::vector <T> temp; //a vector which will be used to build and hold each row temporarily

        for (unsigned int j=0; j<colm; j++)
        {
            temp.push_back( rand()%99+0.25 );
        }
        myMatrix.push_back(temp); //stacking each row in the matrix to make a bi-dimensional array
    }
}


template <class T>
T CMatrix<T>::traceMatrix()
{
    T final=0;
    if (rows==colm)
    {
        for (unsigned int i=0; i<rows ; i++)
        {
            std::vector <T> temp;
            for (unsigned int j=0; j<colm; j++)
            {
                if(i==j) final+=myMatrix[i][j];
            }
        }
    }
    else std::cout << "Sorry the trace can only be find for a square matrix"<< std::endl;
    return final;
}


template <class T>
void CMatrix<T>::buildMatrix()
{
    std::cout << "Enter the no of rows and columns of the matrix : " << std::endl;
    std::cin >> rows; std::cin>>colm;
    for (unsigned int i=0; i<rows ; i++)
    {
        std::vector <T> temp; //a vector which will be used to build and hold each row temporarily

        for (unsigned int j=0; j<colm; j++)
        {
            std::cout << "Enter the element "<< i<<j<< ": " << std::endl;
            T data; std::cin >> data;
            temp.push_back(data);
        }
        myMatrix.push_back(temp); //stacking each row in the matrix to make a bi-dimensional array
    }
}

template <class T>
void CMatrix<T>::displayMatrix()
{
    for (unsigned int i=0; i<rows ; i++)
    {
        for (unsigned int j=0; j<colm; j++)
            std::cout <<myMatrix[i][j] <<" " ;
        std::cout << std::endl;
    }
}

template <class T>
void CMatrix<T>::transposeMatrix(CMatrix M1)
{
    rows = M1.colm;
    colm = M1.rows;

    for (unsigned int i=0; i<rows ; i++)
    {

        std::vector <T> temp;
        for (unsigned int j=0; j<colm; j++)
        {
            temp.push_back(M1.myMatrix[j][i]);
        }
        myMatrix.push_back(temp);
    }
}

//this will build a square identity matrix of size m x m
template <class T>
CMatrix<T>::CMatrix(unsigned int a)
{
    rows=a;
    colm=a;
    for (unsigned int i=0; i<rows; i++)
    {
        std::vector <T> temp;
        for (unsigned int j=0; j<colm; j++)
        {
            if (i==j) temp.push_back(1);
            else temp.push_back(0);
        }
        myMatrix.push_back(temp);
    }
}

template <class T>
void operator << (std::ostream & os, CMatrix <T> M)
{
    unsigned int r = M.getRows();
    unsigned int c = M.getColm();

    for (unsigned int i=0; i<r ; i++)
    {
        for (unsigned int j=0; j<c; j++)
        {
            os << M.myMatrix[i][j] << " ";
        }
        os << std::endl;
    }
}


template <class T>
void CMatrix<T>::addMatrix(CMatrix M1, CMatrix M2)
{
    rows=M1.rows;
    colm=M1.colm;

    if (M1.rows==M2.rows && M1.colm==M2.colm)
    {
        for (unsigned int i=0; i<M1.rows ; i++)
        {
            std::vector<T> temp;
            for (unsigned int j=0; j<M1.colm; j++)
                temp.push_back(M1.myMatrix[i][j]+M2.myMatrix[i][j]);
            myMatrix.push_back(temp);
        }
    }
    else std::cout <<"Please check the dimenions of the matrix to be added"<<std::endl;

}

template <class T>
void CMatrix<T>::subtractMatrix(CMatrix M1, CMatrix M2)
{
    rows=M1.rows;
    colm=M1.colm;

    if (M1.rows==M2.rows && M1.colm==M2.colm)
    {
        for (unsigned int i=0; i<rows ; i++)
        {
            std::vector<T> temp;
            for (unsigned int j=0; j<colm; j++)
                temp.push_back(M1.myMatrix[i][j]-M2.myMatrix[i][j]);
            myMatrix.push_back(temp);
        }
    }
    else std::cout <<"Please check the dimenions of the matrix to be substracted"<<std::endl;
}

template <class T>
void CMatrix<T>::multiplyMatrix(CMatrix M1, CMatrix M2)
{
    rows = M1.rows;
    colm = M2.colm;

    if (M1.colm==M2.rows)
    {
        for (unsigned int i=0; i<rows ; i++)
        { std::vector <T> temp;
            for (unsigned int j=0; j<colm ; j++)
                temp.push_back(0);
            myMatrix.push_back(temp);
        }

        for (unsigned int i=0; i<rows ; i++)
            for (unsigned int j=0; j<colm ; j++)
                for (unsigned int k=0; k<M1.colm ; k++)
                    myMatrix[i][j] += M1.myMatrix[i][k]*M2.myMatrix[k][j];
    }
    else
        std::cout <<"Sorry the dimensions are not correct for performing matrix multiplication"<< std::endl;
}

template <class T>
CMatrix<T> operator + (CMatrix <T> M1, CMatrix <T> M2)
{
    CMatrix <T> output;
    output.addMatrix(M1,M2);
    return output;
}

template <class T>
CMatrix<T> operator - (CMatrix <T> M1, CMatrix <T> M2)
{
    CMatrix <T> output;
    output.subtractMatrix(M1,M2);
    return output;
}

template <class T>
CMatrix<T> operator * (CMatrix <T> M1, CMatrix <T> M2)
{
    CMatrix <T> output;
    output.multiplyMatrix(M1,M2);
    return output;
}

template <class T>
void operator >> (std::istream & is, CMatrix <T> & M)
{
    unsigned int r = M.getRows();
    unsigned int c = M.getColm();

    for (unsigned int i=0; i<r ; i++)
    {
        std::vector <T> temp;
        for (unsigned int j=0; j<c; j++)
        {
            std::cout << "Enter the element : " << std::endl;
            T data; is >> data;
            temp.push_back(data);
        }
        M.writeRow(temp);
    }

}


#endif // MATRIX_H
