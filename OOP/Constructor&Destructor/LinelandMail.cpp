#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cities(n);
    
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < n; i++) {
        int mini, maxi;

        // Compute min distance
        if (i == 0) {
            mini = abs(cities[i] - cities[i + 1]); // First city: only right neighbor
        } else if (i == n - 1) {
            mini = abs(cities[i] - cities[i - 1]); // Last city: only left neighbor
        } else {
            mini = min(abs(cities[i] - cities[i - 1]), abs(cities[i] - cities[i + 1])); // Middle cities: min of two neighbors
        }

        // Compute max distance
        maxi = max(abs(cities[i] - cities[0]), abs(cities[i] - cities[n - 1])); // Max is always to first or last city

        cout << mini << " " << maxi << "\n";
    }

    return 0;
}
