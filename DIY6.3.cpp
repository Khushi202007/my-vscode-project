// Safe array using operator[]

#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray
{
    int *arr;
    int size;

public:
    // Constructor
    SafeArray(int n) : size(n)
    {
        arr = new int[size];
    }

    // Overloading [] operator
    int& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range!");
        }

        return arr[index];
    }

    // Destructor
    ~SafeArray()
    {
        delete[] arr;
    }
};

int main()
{
    SafeArray a(5);

    // Assigning values
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;

    cout << "a[2] = " << a[2] << endl;

    try
    {
        cout << "a[10] = " << a[10] << endl;
    }
    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}