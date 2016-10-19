// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-two-arrays/
// by : leo.0263

#include <iostream>
using namespace std;

long int N, Q;
long int data[2][100002];
long int dpTable[2][100002];


int main()
{
    cin >> N >> Q;
    for (long int i = 1; i <= N; i++) cin >> data[0][i];
    for (long int i = 1; i <= N; i++) cin >> data[1][i];
    
    // prepare the data -> dpTable
    for (long int i = 1; i <= N; i++) {
        if (i == 1) {
            dpTable[0][1] = data[0][1];
            dpTable[1][1] = data[1][1];
        } else {
            if (i % 2 == 0) {
                dpTable[0][i] = dpTable[0][i-1] + data[1][i];
                dpTable[1][i] = dpTable[1][i-1] + data[0][i];
            } else {
                dpTable[0][i] = dpTable[0][i-1] + data[0][i];
                dpTable[1][i] = dpTable[1][i-1] + data[1][i];                
            }
        }        
    }
    
    // debug 
    for (int j = 0; j < 2; j++) {
        cout << "dpTable[" << j << "] : "; 
        for (int i = 1; i <= N; i++) cout << dpTable[j][i] << " ";
        cout << endl;
    }
    
    // process the queries
    long int channel, start, stop, cStart;
    for (long int q = 0; q < Q; q++) {
        cin >> channel >> start >> stop;
        switch (channel) {
            case 1 : if (start % 2 == 1) cStart = 0;
                     else cStart = 1;
                     break;
            case 2 : if (start % 2 == 0) cStart = 0;
                     else cStart = 1;
                     break;
        }
        //if (start > 1) cout << (dpTable[cStart][stop] - dpTable[cStart][start]) + (dpTable[cStart][start]- dpTable[cStart][start-1]) << endl;
        if (start > 1) cout << dpTable[cStart][stop] - dpTable[cStart][start-1] << endl;
        else cout << dpTable[cStart][stop] << endl;
    }
    
    return 0;
}
