#include <vector>
#include <queue>
#include<iostream>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);

    for (const auto &p : prerequisites)
    {
        adjList[p[1]].push_back(p[0]);
    }

    vector<int> indeg(numCourses, 0);

    for (int i = 0; i < numCourses; i++)
    {
        for (int neighbour : adjList[i])
        {
            indeg[neighbour]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < numCourses; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    int completedCourse = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        completedCourse++;

        for (int n : adjList[node])
        {
            indeg[n]--;
            if (indeg[n] == 0)
            {
                q.push(n);
            }
        }
    }

    return completedCourse == numCourses;
}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};
    bool result = canFinish(numCourses, prerequisites);
    cout<<"Can finish course = "<<result<<endl;
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