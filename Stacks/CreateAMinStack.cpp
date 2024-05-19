#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> ms;
    MinStack() {}

    // Task: The task is to design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    // Approach: We use two stacks, one to store the actual stack elements (s) and the other to store the minimum element at each level (ms).
    // When we push an element onto the stack, we also push it onto the ms stack if it's less than or equal to the current top element of ms.
    // When we pop an element from the stack, we also pop the top element from the ms stack.
    // The top function returns the top element of the s stack, and the getMin function returns the top element of the ms stack, which is the current minimum.
    // Time Complexity: O(1) for all operations, because we're just performing constant time operations on the top of the stacks.
    // Space Complexity: O(n), where n is the number of elements in the stack, because we're storing all elements in the s stack and potentially all elements in the ms stack.

    void push(int val) {
        s.push(val);
        if (ms.empty() || val <= ms.top()) {
            ms.push(val);
        }else {
            ms.push(ms.top());
        }
    }

    void pop() {
        ms.pop();
        s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return ms.top(); }
};

int main() {
    // Test Case: Push the values 5, 3, 4 into the MinStack
    // The minimum value should be 3
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->push(3);
    obj->push(4);
    cout << "Minimum Value: " << obj->getMin() << endl;

    return 0;
}