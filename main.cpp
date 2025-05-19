#include <iostream>
#include "QueueFIFO.h"

using namespace std;

int main() {
    QueueFIFO<int> queue = QueueFIFO<int>(5);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    cout << "Current head element: " << queue.peekElement() << endl;

    cout << "Iterator start first" << endl;
    QueueFIFO<int>::Iterator it = queue.getIterator();
    while (!it.finish()) {
        std::cout << it.value() << " ";
        it.next();
    }
    std::cout << endl;
    cout << "Popped element: " << queue.pop() << endl;
    cout << "Popped element: " << queue.pop() << endl;
    cout << "Iterator start second" << endl;
    it.start();
    while (!it.finish()) {
        std::cout << it.value() << " ";
        it.next();
    }
    cout << "\nPopped element: " << queue.pop();
    cout << "\nPopped element: " << queue.pop();
    cout << "\nPopped element: " << queue.pop();
    cout << "\nIterator start third" << endl;
    it.start();
    while (!it.finish()) {
        std::cout << it.value() << " ";
        it.next();
    }
    cout << "\nIterator start fourth (NO DIFFERENCE)" << endl;
    it.start();
    while (!it.finish()) {
        std::cout << it.value() << " ";
        it.next();
    }

    return 0;

}
