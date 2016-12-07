#include <iostream>
using namespace std;

int N = 3;
int digits[100];

void printComb(int digit) {
    if (digit == N) {
        for (int i = 0; i < N; i++) cout << digits[i] << " ";
        cout << endl;
        return;
    }
    
    for (int x = 1; x <= N; x++) {
        digits[digit] = x;
        printComb(digit+1);
    }
}

int main() {
    printComb(0);
    
    return 0;
}

//int n, startX, startY, stopX, stopY;
//int map[100][100];
//bool isVisited[100][100];
//int globalSteps;
//bool finishFound;
//
//bool isValid(int x, int y) {
//    if (x < 0) return false;
//    if (y < 0) return false;
//    if (x >= n) return false;
//    if (y >= n) return false;
//    if (map[y][x] == 1) return false;
//    return true;
//}
//
//
//void cariPath(int x, int y, int steps) {
//    // exit condition
//    if (!isValid(x, y)) return;
//    if (isVisited[y][x]) return;    
//    if ((x == stopX) && (y == stopY)) {
//        finishFound = true;
//        if (globalSteps > steps) globalSteps = steps;
//        return;
//    }    
//    
//    // pruning
//    if (finishFound && (steps > globalSteps)) return;
//    
//    isVisited[y][x] = true;
//    cariPath(x, y-1, steps+1);
//    cariPath(x, y+1, steps+1);
//    cariPath(x-1, y, steps+1);
//    cariPath(x+1, y, steps+1);
//    isVisited[y][x] = false;
//}
//
//int main() {
//    // read input
//    cin >> n;
//    for (int y = 0; y < n; y++) 
//        for (int x = 0; x < n; x++) {
//            cin >> map[y][x];
//            isVisited[y][x] = false;
//            if (map[y][x] == 2) { startX = x; startY = y; }
//            if (map[y][x] == 3) { stopX = x; stopY = y; }
//        }
//    
//    globalSteps = n*n*n;
//    finishFound = false;
//    cariPath(startX, startY, 0);
//    cout << globalSteps;
//}

//5
//2 0 0 0 0
//0 1 0 1 1
//0 1 0 0 0
//0 1 1 1 0
//0 3 0 0 0


//int fib(int n) {
//    if (n <= 2) return 1;
//    return fib(n-1) + fib(n-2);
//}
//
//int main() {
//    int N = 5;
//    cout << fib(N);
//    
//    return 0;
//}