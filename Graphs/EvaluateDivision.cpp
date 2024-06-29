    #include <iostream>
    #include <string>
    #include <vector>
    #include <unordered_map>
    #include <unordered_set>
    using namespace std;

    double dfs(const unordered_map<string, unordered_map<string, double>>& graph, const string& start, const string& end, double acc, unordered_set<string>& visited) {
        if (visited.count(start)) return -1.0;
        if (graph.count(start) == 0 || graph.count(end) == 0) return -1.0;
        if (start == end) return acc;
        visited.insert(start);

        for (const auto& neighbor : graph.at(start)) {
            double result = dfs(graph, neighbor.first, end, acc * neighbor.second, visited);
            if (result != -1.0) return result;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double value = values[i];
            graph[u][v] = value;
            graph[v][u] = 1.0 / value;
        }

        vector<double> results;
        for (const auto& query : queries) {
            string start = query[0];
            string end = query[1];
            unordered_set<string> visited;
            double result = dfs(graph, start, end, 1.0, visited);
            results.push_back(result);
        }

        return results;
    }

    int main() {
        vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
        vector<double> values = {2.0, 3.0};
        vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
        vector<double> results = calcEquation(equations, values, queries);

        for (double result : results) {
            cout << result << " ";
        }
        cout << endl;

        return 0;
    }

    /*
    Idea:
    Solve the "Evaluate Division" problem by constructing a graph where each equation represents an edge with a weight. Use DFS to find the product of weights along the path from the start variable to the end variable.

    Approach:
    1. Build a graph where each node represents a variable, and each edge represents the division equation between variables.
    2. For each query, use DFS to search for a path from the start variable to the end variable, multiplying the weights of the edges along the path.
    3. If a path exists, return the product as the answer to the query; otherwise, return -1.0.

    Time Complexity: O(Q*(V+E)), where Q is the number of queries, V is the number of variables, and E is the number of equations.
    Space Complexity: O(V+E), for storing the graph.

    Example Test Case:
    Input: equations = [["a", "b"], ["b", "c"]], values = [2.0, 3.0], queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]
    Output: [6.0, 0.5, -1.0, 1.0, -1.0]
    */