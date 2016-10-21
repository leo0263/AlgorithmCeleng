// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-ropes/
// by : leo.0263@gmail.com

#include <iostream>
using namespace std;

int T;
long N, maxTime, data;

int main()
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        
        // read data while processing them
        maxTime = N;
        for (long i = 0; i < N-1; i++) {
            cin >> data;
            data += (i + 1);
            if (maxTime < data) maxTime = data;
        }
        for (long i = 0; i < N-1; i++) {
            cin >> data;
            data += (i + 1);
            if (maxTime < data) maxTime = data;
        }
        
        // print output
        cout << maxTime << endl;
    }
    return 0;
}
