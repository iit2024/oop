#include <iostream>
using namespace std;

class complex
{
    float r;
    float i;

public:
    complex()
    {
        r = 0;
        i = 0;
    }

    complex operator+(const complex &c);
    complex operator*(const complex &c);
    friend istream &operator>>(istream &input, complex &t);
    friend ostream &operator<<(ostream &output, const complex &t);
};

complex complex::operator+(const complex &c)
{
    complex temp;
    temp.r = r + c.r;
    temp.i = i + c.i;
    return temp;
}

complex complex::operator*(const complex &c)
{
    complex temp2;
    temp2.r = (r * c.r) - (i * c.i);
    temp2.i = (i * c.r) + (r * c.i);
    return temp2;
}

istream &operator>>(istream &input, complex &t)
{
    cout << "Enter the real part: ";
    input >> t.r;
    cout << "Enter the imaginary part: ";
    input >> t.i;
    return input;
}

ostream &operator<<(ostream &output, const complex &t)
{
    output << t.r;
    if (t.i >= 0)
        output << "+";
    output << t.i << "i\n";
    return output;
}

int main()
{
    complex c1, c2, c3, c4;

    cout << "Default constructor value = " << c1 << endl;

    cout << "Enter the 1st number\n";
    cin >> c1;
    cout << "Enter the 2nd number\n";
    cin >> c2;

    cout << "The first number is " << c1 << endl;
    cout << "The second number is " << c2 << endl;

    c3 = c1 + c2;
    c4 = c1 * c2;

    cout << "\nAddition Of Two Complex Numbers Is " << c3 << endl;
    cout << "Multiplication Of Two Complex Numbers Is " << c4 << endl;

    return 0;
}