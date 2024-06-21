#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) __builtin_popcount(x)

// Comparator function to sort items based on value per weight ratio
bool compare(pii p1, pii p2){
    double v1 = (double) p1.ff/p1.ss;
    double v2 = (double) p2.ff/p2.ss;
    return v1 > v2;
}

int main(){
    // Idea: To maximize the value for a given weight in the knapsack problem by taking items fully or fractionally.
    // Approach: Sort items based on their value/weight ratio. Then, take items fully or fractionally until the knapsack is full.
    // Time Complexity: O(n log n) due to sorting.
    // Space Complexity: O(1) not counting the input storage.
    // Example Test Case: Input - n=3, items={(60,10), (100,20), (120,30)}, w=50. Output - Optimal value is 240.

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vii a(n);
    cout << "Enter value and weight of items:\n";
    rep(i, 0, n){
        cin >> a[i].ff >> a[i].ss;
    }

    int w;
    cout << "Enter the capacity of knapsack: ";
    cin >> w;

    sort(a.begin(), a.end(), compare); // Sort items based on value/weight ratio

    double ans = 0; // Use double for fractional values
    rep(i, 0, n){
        if(w >= a[i].ss){ // If we can take the whole item
            ans += a[i].ff;
            w -= a[i].ss;
        } else { // Take fraction of the item
            double vw = (double)a[i].ff / a[i].ss;
            ans += vw * w;
            w = 0;
            break;
        }
    }

    cout << "Optimal Value for given Weight is " << ans << " value" << endl;
}