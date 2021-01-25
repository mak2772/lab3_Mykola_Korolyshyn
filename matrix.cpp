#define RED "\033[31m"
#define RESET "\033[0m"
#include "matrix.hpp"
#include "exceptions.cpp"
using namespace std;

matrix::matrix(int &wwiersze,int &col)
{
    wiersze=wwiersze;
    kolumny=col;
    bool x=checkif(wiersze,kolumny);

    if(x==true)
    {
        return;
    }
    tab=new double*[wiersze+1];
    for(int i=0;i<wiersze;i++)
        {
            tab[i]=new double[kolumny+1];

            for(int j=0;j<kolumny;j++)
            {
                tab[i][j]=0;
            }
        }

}

matrix::matrix(int &cube)
{

        wiersze=cube;
        kolumny=wiersze;
        bool x=checkif(wiersze,kolumny);

        if(x==true)
            {
                return;
            }
        tab=new double*[wiersze+1];

        for(int i=0;i<wiersze;i++)
        {
            tab[i]=new double[wiersze+1];
            for(int j=0;j<wiersze;j++)
            {
                tab[i][j]=0;
            }
        }

}

void matrix::set(int &n,int &m,double &val)
{
    try{
    if(n-1<0 || n-1>wiersze || m-1<0 || m-1>kolumny)
    {
        ErrorWrongIndexReach error;
        throw error;
    }
    tab[n-1][m-1]=val;
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
}

double matrix::get(int &n,int &m)
{
    try{
     if(n-1<0 || n-1>wiersze || m-1<0 || m-1>kolumny)
    {
        ErrorWrongIndexReach error;
        throw error;
    }
    else{
    return tab[n-1][m-1];
    }
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    return 0;

}

void matrix::print()
{
    for(int i=0;i<wiersze;i++)
        {
            for(int j=0;j<kolumny;j++)
            {
                cout<<tab[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
}

matrix matrix::add(matrix &m2)
    {
        int tempkol=m2.cols();
        int tempwie=m2.rows();
        matrix addm(tempwie,tempkol);
        try{
        if(m2.cols()!=kolumny || m2.rows()!=wiersze)
        {
            ErrorWrongIndexMath error;
            throw error;
        }
        for(int i=0;i<wiersze;i++)
        {
            for(int j=0;j<kolumny;j++)
            {
                addm.tab[i][j]=tab[i][j]+m2.tab[i][j];
            }
        }
        }
         catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
        return addm;
    }

matrix matrix::substract(matrix &m2)
    {
        int tempkol=m2.cols();
        int tempwie=m2.rows();
        matrix subb(tempwie,tempkol);
        try{
        if(m2.cols()!=kolumny || m2.rows()!=wiersze)
        {
            ErrorWrongIndexMath error;
            throw error;
        }
        for(int i=0;i<wiersze;i++)
        {

            for(int j=0;j<kolumny;j++)
            {
                subb.tab[i][j]=tab[i][j]-m2.tab[i][j];
            }
        }
        }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
        return subb;
    }

matrix matrix::multiply(matrix &m2)
    {
        int tempkol=m2.cols();
        int tempwie=m2.rows();
        matrix mnoz(wiersze,tempkol);
        try{
        if(tempwie!=kolumny)
        {
            ErrorWrongMultiplication error;
            throw error;
        }
        for(int i=0;i<wiersze;i++)
        {
            for(int j=0;j<kolumny;j++)
            {
                for(int k=0;k<kolumny;k++)
                {
                mnoz.tab[i][j]=mnoz.tab[i][j]+tab[i][k]*m2.tab[k][j];
                }
                }
        }
        }
        catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
        return mnoz;
    }

int matrix::rows()
    {
    return wiersze;
    }

int matrix::cols()
    {
    return kolumny;
    }

void matrix::store(string &filename, string &path)
{
    ofstream plik;
    plik.open(path, ios_base::out);
    try{
    if(plik.good()!=true)
    {
        ErrorFileNotOpen error;
        throw error;
    }
    else
    plik<<rows()<<" "<<cols()<<endl;
    for(int i=0;i<wiersze;i++)
    {
        for(int j=0;j<kolumny;j++)
        {
            plik<<tab[i][j]<<" ";
        }
        plik<<endl;
    }
    plik.close();
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }

}

matrix::matrix(string &a)
{
    ifstream czytaj;
    czytaj.open(a,ios_base::out);

    if(czytaj.good()!=true)
    {
    FailToOpen();
    }
    else
    {
     int x,y;
     czytaj>>x;
     czytaj>>y;
     wiersze=x;
     kolumny=y;
     bool check=checkif(wiersze,kolumny);

     if(check==true)
     {
        return;
     }
     tab=new double*[wiersze+1];
     for(int i=0;i<wiersze;i++)
        {
         tab[i]=new double[wiersze+1];
         for(int j=0;j<wiersze;j++)
            {
                czytaj>>tab[i][j];
            }
        }
    }
}



bool matrix::checkif(int &n,int &m)
{
    try{
    if(wiersze<0 || kolumny<0)
    {
        ErrorTooSmall error;
        throw error;
    }
    if(wiersze>50 || kolumny>50)
    {
        ErrorTooBig error;
        throw error;
    }
    }
    catch (exception &e)
    {
        cout <<RED<< e.what() <<RESET << endl;
        return true;
    }
    return false;
}

void matrix::FailToOpen()
{
    try{
        ErrorFileNotOpen error;
        throw error;
    }
    catch (exception &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
}
