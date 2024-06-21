// A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels.

// To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).

// The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).

// Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.

// Input
// The first line of the input contains an integer t representing the number of test cases. Then t test cases follow. Each test case has the follwing form:

// Line 1: A single integer, N
// Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
// Line N+2: Two space-separated integers, L and P
// Output
// For each test case, output a single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        int l, p;
        cin >> l >> p;

        for (int i = 0; i < n; i++)
        {
            a[i].first = l - a[i].first;
        }

        sort(a.begin(), a.end());

        int ans = 0;
        int curr = p;
        bool flag = 0;

        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < n; i++)
        {
            if (curr >= l)
            {
                break;
            }

            while (curr < a[i].first)
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                curr += pq.top();
            }
            if (flag)
                break;

            pq.push(a[i].second)
        }

        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }

        while (!pq.empty() && curr < l)
        {
            curr += pq.top();
            pq.pop();
            ans++;
        }

        if (curr < l)
        {
            cout << "-1" << endl;
            continue;
        }

        cout << "Minimum No Of Stops " << ans << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

// Function to find the minimum number of fuel stops needed to reach the town.
int minFuelStops(vector<pair<int, int>>& stops, int distanceToTown, int initialFuel) {
    // Sort stops based on their distance from the starting point (after converting distances from town to distances from start).
    sort(stops.begin(), stops.end());

    // Priority queue to store available fuel amounts in descending order.
    priority_queue<int> availableFuels;

    int stopsCount = 0; // Count of stops made for fuel.
    int currentFuel = initialFuel; // Current fuel in the truck.
    bool isPossible = true; // Flag to check if reaching the town is possible.

    for (int i = 0; i < stops.size(); i++) {
        // If current fuel is enough to reach the town, break the loop.
        if (currentFuel >= distanceToTown) {
            break;
        }

        // While current fuel is less than the distance to the next stop, use fuel from the priority queue.
        while (currentFuel < stops[i].first) {
            if (availableFuels.empty()) {
                isPossible = false; // If no fuel is available, set isPossible to false and break.
                break;
            }
            currentFuel += availableFuels.top(); // Add the top fuel amount from the queue to current fuel.
            availableFuels.pop(); // Remove the used fuel from the queue.
            stopsCount++; // Increment the stops count.
        }

        if (!isPossible) {
            break; // If it's not possible to reach the next stop, break the loop.
        }

        // Add the fuel from the current stop to the priority queue.
        availableFuels.push(stops[i].second);
    }

    // If not enough fuel to reach the town, try using fuel from the priority queue.
    while (!availableFuels.empty() && currentFuel < distanceToTown) {
        currentFuel += availableFuels.top();
        availableFuels.pop();
        stopsCount++;
    }

    // If it's still not possible to reach the town, return -1.
    if (currentFuel < distanceToTown) {
        return -1;
    }

    return stopsCount; // Return the minimum number of stops needed.
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter number of fuel stops: ";
        cin >> n;

        vector<pair<int, int>> stops(n);

        cout << "Enter distance from town and fuel at each stop:\n";
        for (int i = 0; i < n; i++) {
            cin >> stops[i].first >> stops[i].second;
            stops[i].first = -stops[i].first; // Store distance as negative for sorting in reverse.
        }

        int l, p;
        cout << "Enter distance to town and initial fuel: ";
        cin >> l >> p;

        // Convert distances to be from the starting point instead of from the town.
        for (int i = 0; i < n; i++) {
            stops[i].first += l;
        }

        int result = minFuelStops(stops, l, p);

        if (result == -1) {
            cout << "It is not possible to reach the town.\n";
        } else {
            cout << "Minimum number of stops: " << result << endl;
        }
    }
}