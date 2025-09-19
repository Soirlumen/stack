#include "template_stack.h"
#include <iostream>
using namespace std;

int main() {
    // vytvoříme stack s kapacitou 5
    Stack<int> s(5);

    cout << "Stack capacity: " << s.getCapacity() << endl;

    // přidávání prvků
    cout << "Push: 10, 20, 30" << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack obsah: ";
    s.printy();

    // podíváme se na top
    cout << "Top element: " << s.top() << endl; // 30

    // vyjmeme prvek
    cout << "Pop top element" << endl;
    s.pop();

    cout << "Stack obsah po pop: ";
    s.getThings().printy(); // [ 20 -> 10 ]
    cout << "Top element: " << s.top() << endl; // 20

    // přidáme další prvky
    cout << "Push: 40, 50, 60" << endl;
    s.push(40);
    s.push(50);

    s.push(60);
    // zkusíme překročit kapacitu
    s.push(70);
    // zkuzíme změnit kapacitu
    s.setCapacity(6);
    cout<<"Push: 70"<<endl;
    s.push(70);
    cout << "Stack obsah: ";
    s.printy();
    // zkusíme změnit kapacitu na menší, než kolik je prvků
    s.setCapacity(4);

    cout << "konecny obsah stacku: ";
    s.getThings().printy();

    return 0;
}
