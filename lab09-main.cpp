#include "ArrayStack.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    ArrayStack<int> stack(5);
    // push values
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Full int Stack: " << stack << endl;

    stack.pop();
    cout << stack << endl;

    stack.rotate(Stack<int>::LEFT);
    cout << stack << endl;

    stack.rotate(Stack<int>::RIGHT);
    stack.rotate(Stack<int>::RIGHT);
    cout << stack << endl;

    ArrayStack<int> copy(stack);
    cout << "Copy: " << copy << endl;
    try {
        for (int i = 0; i < 10; i++) {
            copy.pop();
        }
        cout << "Top element: " << copy.peek() << endl;
    }
    catch (const string& e) {
        cout << "Exception caught: " << e << endl;
    }

    stack.clear();

    ArrayStack<string> strings(15);
    // push values
    strings.push("10hello");
    strings.push("tested");
    strings.push("working");
    cout << "before pop: " << strings << endl;
    strings.pop();
    cout << "after pop: " << strings << endl;

    try {
        for (int o = 0; o < 10000; o++) {
            strings.push(to_string(o));
        }
        cout << "Top element: " << strings.peek() << endl;
    }
    catch (const string& e) {
        cout << "Exception caught: " << e << endl;
    }

    ArrayStack<string> copy2(strings);
    cout << "Copy: " << copy2 << endl;

    strings.clear();

    return 0;
}

