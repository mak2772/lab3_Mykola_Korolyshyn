#include<iostream>
using namespace std;

class ErrorTooSmall : public exception
{
    virtual const char *what() const throw()
    {
        return "[Error]: Podana liczba jest niedodatnia";
    }
};

class ErrorTooBig : public exception
{
    virtual const char *what() const throw()
    {
        return "[Error]: Rozmiar kolumn lub wierszy przekracza 50";
    }
};

class ErrorWrongIndexMath : public exception
{
    virtual const char *what() const throw()
    {
        return "[Error]: Wymiary matrixy nie sa takie same";
    }
};

class ErrorWrongMultiplication : public exception
{
    virtual const char *what() const throw()
    {
        return "[Error]: Bledne wymiary matrixy do wymnozenia";
    }
};

class ErrorWrongIndexReach : public exception
{
    virtual const char *what() const throw()
    {
        return "[Error]: Podany indeks jest poza zakresem matrixy";
    }
};

class ErrorFileNotOpen : public exception
{
    virtual const char *what() const throw()
    {
        return "[Error]: Nie udalo sie otworzyc pliku";
    }
};
