// https://www.hackerrank.com/challenges/red-john-is-back
// by : leo.0263@gmail.com

#include <iostream>
using namespace std;

int T, N;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        
        int totalWays = 1;
        int possibleSquare = N / 4;
        totalWays += possibleSquare;
        for (int square = 0; square < possibleSquare; square++) {
            int remainingCell = N % 4;
            totalWays += remainingCell;          
        }

        
        cout << totalWays << endl;
        
    }
        
    return 0;
}