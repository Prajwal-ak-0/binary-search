// Idea: To find the minimum computation time required to merge files.
// Approach: Use a min heap to always merge the two smallest files first, then add the merged file back to the heap until one file remains.
// Time Complexity: O(n log n), where n is the number of files. The heap operations (insert and delete) take O(log n) time.
// Space Complexity: O(n) for storing the files in the heap.
// Example Test Case: Input - n=4, files={4, 3, 2, 6}. Output - Optimal Computation Time is: 29.

#include<bits/stdc++.h>

using namespace std;

signed main(){
    int n;
    cout << "Enter the number of files: ";
    cin>>n;

    vector<int> a(n);

    cout << "Enter the sizes of the files:\n";
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    priority_queue<int, vector<int>, greater<int>> minheap;

    for(int i=0;i<n;i++){
        minheap.push(a[i]);
    }

    int ans = 0;

    while (minheap.size() > 1)
    {
        int first_smallest = minheap.top();
        minheap.pop();
        int second_smallest = minheap.top();
        minheap.pop();
        int computation = first_smallest + second_smallest;
        minheap.push(computation);
        ans += computation;
    }

    cout<<"Optimal Computation Time is : "<<ans<<endl;
}