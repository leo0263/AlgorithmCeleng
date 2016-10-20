// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/once-upon-a-time-in-time-land/
// by : leo.0263@gmail.com

#include <iostream>
using namespace std;

int T, N, K;
int data[10001];
int dp[10001];

int findMax(int index) {
    // if index is out of data bound, return 0
    if (index > N) return 0;
    
    // if we've found the max value for this step before, use it
    if (dp[index] != -1) return dp[index];

    // else, recursively find wheter it is better to skip this data, or use it (by it's index) 
    int maxLocal = max(findMax(index + 1), data[index] + findMax(index + K + 1));
    if (dp[index] < maxLocal) dp[index] = maxLocal;
    return maxLocal;
}

int main()
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        // read input parameters
        cin >> N >> K;
        
        // read data & prepare dp table
        for (int i = 0; i < N; i++) {
            cin >> data[i];
            dp[i] = -1;
        }
        
        // process the data using dp table
        int maxGlobal = 0;
        for (int i = 0; i < N; i++) {
            int maxI = findMax(i);
            if (maxI > maxGlobal) maxGlobal = maxI;
        }
    
        // print the output
        cout << maxGlobal << endl;
    }
    
    return 0;
}
