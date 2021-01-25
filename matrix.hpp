#include<iostream>
#include<fstream>

using namespace std;
#ifndef MATRIX
#define MATRIX
#endif

class matrix
{
    private:
    int wiersze;
    int kolumny;
    double **tab;

    public:
    matrix(int &,int &);
    matrix(int &);
    matrix(string &);
    void set(int &,int &,double &);
    double get(int &,int &);
    void print();
    bool checkif(int &,int &);
    void FailToOpen();
    matrix add(matrix &);
    matrix substract(matrix &);
    matrix multiply(matrix &);
    int rows();
    int cols();
    void store(string &, string &);
};
