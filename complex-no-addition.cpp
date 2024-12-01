#include <iostream>
using namespace std;

class complex_no
{
    int real, img;

public:
    complex_no() {}
    complex_no(int r, int i)
    {
        real = r;
        img = i;
    }
    void setter(int r, int i)
    {
        real = r;
        img = i;
    }
    void getter()
    {
        cout << " " << real << " + " << img << "i ";
    }
    complex_no operator+(complex_no x)
    {
        complex_no z;
        z.real = real + x.real;
        z.img = img + x.img;
        return z;
    }
};

int main()
{
    int a, b, c, d;
    cout << "Enter first Complex Number's Real part and then Imaginary part : ";
    cin >> a >> b;
    cout << "Enter second Complex Number's Real part and then Imaginary part : ";
    cin >> c >> d;
    complex_no x(a, b), y(c, d);
    complex_no z = x + y;
    cout << "The Sum of the given two Complex Number is :";
    z.getter();
}