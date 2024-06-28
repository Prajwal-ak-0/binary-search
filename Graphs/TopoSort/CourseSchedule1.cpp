#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it) {
        adj[(*it)[1]].push_back((*it)[0]);
    }

    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo.size() == numCourses;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2},{1,3}};
    bool result = canFinish(numCourses, prerequisites);
    // Output: false (There is a cycle in the prerequisites)
    return 0;
}

/*
Idea:
Determine if it's possible to finish all courses given the prerequisites, using topological sorting (Kahn's algorithm).

Approach:
1. Create an adjacency list to represent the graph.
2. Calculate in-degree for each course.
3. Use a queue to keep track of courses with no prerequisites (in-degree of 0).
4. Perform topological sort:
   - Remove a course from the queue, add it to the topological order.
   - Decrease the in-degree of its neighbors.
   - If a neighbor's in-degree drops to 0, add it to the queue.
5. If the size of the topological order equals the number of courses, return true; otherwise, false.

Time Complexity: O(V+E), where V is the number of courses, and E is the number of prerequisites.
Space Complexity: O(V+E), for storing the graph and in-degree.

Example Test Case:
Input: numCourses = 4, prerequisites = [[1,0],[2,1],[3,2],[1,3]]
Output: false (The courses form a cycle, so it's not possible to complete all courses.)
*/