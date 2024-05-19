#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    // Task: The task is to simplify a Unix-style file path.
    // Approach: We use a stack to keep track of the directories. When we encounter "..", we pop the top directory from the stack.
    // When we encounter ".", we do nothing. For any other directory, we push it onto the stack.
    // Finally, we construct the simplified path by popping directories from the stack and prepending them to the result string.
    // Time Complexity: O(n), where n is the length of the path. This is because we are iterating through the path once.
    // Space Complexity: O(n), for the stack. In the worst case (when the path is made up of n directories), we will push all directories onto the stack.

    string simplifyPath(string path) {
        stack<string> s;
        int n = path.length();

        for(int i=0;i<n;i++){
            if(path[i] == '/') continue;

            string dir;
            while(i < n && path[i] != '/'){
                dir+=path[i++];
            }

            if(dir == ".."){
                if(!s.empty()){
                    s.pop();
                }
            }

            if(dir != "." && !dir.empty()){
                s.push(dir);
            }
        }

        string res;
        while(!s.empty()){
            res = "/"+s.top()+res;
            s.pop(); 
        }

        return res.empty() ? "/" : res;
    }
};

int main() {
    // Test Case: The path is "/home//foo/"
    // The simplified path should be "/home/foo"
    Solution solution;
    string path = "/home//foo/";
    cout << "Simplified Path: " << solution.simplifyPath(path) << endl;

    return 0;
}