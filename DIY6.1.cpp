#include <iostream>
using namespace std;

class Money {
    int rupees, paise;

public:
    Money(int r = 0, int p = 0) {
        rupees = r + p / 100;
        paise = p % 100;
    }

    // Overload + operator
    Money operator+(Money m) {
        Money temp;
        temp.rupees = rupees + m.rupees;
        temp.paise = paise + m.paise;

        if (temp.paise >= 100) {
            temp.rupees++;
            temp.paise -= 100;
        }

        return temp;
    }

    // Overload - operator
    Money operator-(Money m) {
        Money temp;
        temp.rupees = rupees - m.rupees;
        temp.paise = paise - m.paise;

        if (temp.paise < 0) {
            temp.rupees--;
            temp.paise += 100;
        }

        return temp;
    }

    void display() {
        cout << rupees << " rupees and "
             << paise << " paise" << endl;
    }
};

int main() {
    Money m1(10, 80);
    Money m2(5, 50);

    Money sum = m1 + m2;
    Money difference = m1 - m2;

    cout << "First Money: ";
    m1.display();

    cout << "Second Money: ";
    m2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    return 0;
}