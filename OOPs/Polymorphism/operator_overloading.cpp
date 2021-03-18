#include <iostream>

using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    Complex operator+(Complex &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;

        return res;
    }
    void print()
    {
        cout << real << " + i" << imag;
    }
};

int main()
{
    Complex c1(3, 4), c2(4, 3);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}
