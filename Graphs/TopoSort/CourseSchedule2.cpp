#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    for (const auto& p : prerequisites) {
        adjList[p[1]].push_back(p[0]);
    }

    vector<int> indeg(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        for (auto n : adjList[i]) {
            indeg[n]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto n : adjList[node]) {
            indeg[n]--;
            if (indeg[n] == 0) {
                q.push(n);
            }
        }
    }

    if (ans.size() == numCourses) {
        return ans;
    } else {
        return {};
    }
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> order = findOrder(numCourses, prerequisites);

    if (!order.empty()) {
        cout << "Course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    } else {
        cout << "No possible order to complete all courses." << endl;
    }

    return 0;
}

/*
Idea:
Find an order in which all courses can be finished given the prerequisites, using topological sorting.

Approach:
1. Convert the prerequisites list into an adjacency list to represent the graph.
2. Calculate in-degree for each course.
3. Use a queue to keep track of courses with no prerequisites (in-degree of 0).
4. Perform topological sort:
   - Remove a course from the queue, add it to the result list.
   - Decrease the in-degree of its neighbors.
   - If a neighbor's in-degree drops to 0, add it to the queue.
5. If the size of the result list equals the number of courses, return the list; otherwise, return an empty list.

Time Complexity: O(V+E), where V is the number of courses, and E is the number of prerequisites.
Space Complexity: O(V+E), for storing the graph and in-degree.

Example Test Case:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0, 1, 2, 3] or [0, 2, 1, 3]
*/