#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Task: The task is to evaluate the value of an arithmetic expression in Reverse Polish Notation.
    // Approach: We use a stack to keep track of the numbers. When we encounter an operator, we pop the top two numbers from the stack, perform the operation, and push the result back onto the stack.
    // Time Complexity: O(n), where n is the number of tokens. This is because we are iterating through the tokens once.
    // Space Complexity: O(n), for the stack. In the worst case (when all tokens are numbers), we will push all tokens onto the stack.

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res, a, b;

        for(const auto& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if(token=="+") {
                    res = a + b;
                }else if (token == "-"){
                    res = b - a;
                }
                else if(token == "*"){
                    res = a*b;
                }
                else{
                    res = b/a;
                }
                s.push(res);
            }else{
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};

int main() {
    // Test Case: The tokens are ["2", "1", "+", "3", "*"]
    // The value of the expression should be 9
    Solution solution;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Value of Expression: " << solution.evalRPN(tokens) << endl;

    return 0;
}