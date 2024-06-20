#include<bits/stdc++.h>

using namespace std;

int main(){
    // Task: The task is to select the maximum number of activities that a single person can do, given the start and end times of the activities.
    // Approach: We sort the activities based on their end times and then select as many activities as possible by always selecting the next activity whose start time is greater than or equal to the end time of the previously selected activity.
    // Time Complexity: O(n log n), where n is the number of activities. This is because we are sorting the activities.
    // Space Complexity: O(n), as we are storing the activities in a vector.
    // Test Case: The activities are [ [10, 20], [12, 15], [20, 30] ]. The maximum number of activities that can be selected is 2.

    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    vector<vector<int>> v;
    cout << "Enter the start and end times of the activities:\n";
    for(int i=0;i<n;i++){
        int st, ed;
        cin >> st >> ed;
        v.push_back({st,ed});
    }
    sort(v.begin(), v.end(),[&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });
    int take = 1;  
    int end = v[0][1];  
    for(int i=1; i<n;i++){
        if(v[i][0] >= end){
            take++; 
            end = v[i][1]; 
        }
    }
    cout << "Take " << take << " no of activities" << endl;
}
// [ [12, 15], [10, 20], [20, 30] ].