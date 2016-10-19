// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-chocolates-bars-2/
// by : leo.0263@gmail.com

#include <iostream>
#include <string> 
using namespace std;

int T, N;
string stringnya;
int dp[1000001];

int main()
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        // read input
        cin >> stringnya;
        N = stringnya.length();
        //cout << "stringnya : [" << stringnya << "] = " << N << endl;
        
        // prepare dp table
        for (int i = 0; i < N; i++) dp[i] = 0;
        int maxChocolate = 0;
        
        // do dp iteration, start from the 3rd char
        for (int i = 3-1; i < N; i++) {
            if ((stringnya[i] != stringnya[i-1]) || (stringnya[i] != stringnya[i-2])) {
                if (i-3 >= 0) dp[i] = 3 + dp[i-3];
                else dp[i] = 3;
            }
            if (maxChocolate < dp[i]) maxChocolate = dp[i];
        }
        
//        // debug        
//        for (int i = 0; i < N; i++) cout << dp[i];
//        cout << " <= dp table" << endl;
        
        // print the output
        cout << N - maxChocolate << endl;
    }
}
