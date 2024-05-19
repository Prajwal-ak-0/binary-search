#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>

using namespace std;

bool isValid(string s) {
    // Idea: The idea is to check if the given string of parentheses is valid.
    // Approach: We use a stack to keep track of the opening parentheses. When we encounter a closing parenthesis, we check the top of the stack.
    // If the top of the stack is the corresponding opening parenthesis, we pop it from the stack. If not, the string is not valid.
    // In the end, if the stack is empty, the string is valid. Otherwise, it is not.
    // Time Complexity: O(n), where n is the length of the string.
    // Space Complexity: O(n), for the stack.

    stack<char> st;

    for(char c:s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }else{
            if(st.empty()) {
                return false;
            }

            char top = st.top();
            st.pop();

            if((c == ')' && top != '(') || (c == '}' && top != '{' ) || (c == ']' && top != '[')){
                return false;
            }
        }
    }

    return st.empty();
}

bool isValid2(string s) {
    // Method 2
    stack<char> st;

    unordered_map<char,char> bracketMapping = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for(char c:s){
        if(bracketMapping.count(c)){
            if(st.empty() || bracketMapping[c] != st.top()){
                return false;
            }
            st.pop();
        }
        else{
            st.push(c);
        }
    }

    return st.empty();
}

int main() {
    // Test Case: The string is "{[]}"
    // The string is valid, so the output should be 1 (true).
    string s = "{[]}";
    cout << isValid(s) << endl;
    cout << isValid2(s) << endl;

    return 0;
}