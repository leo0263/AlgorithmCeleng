#include <iostream>
using namespace std;

const int maxN = 101;



struct t_point {
    int x;
    int y;
};

struct t_qData {
    t_point p;
    int distance;
};

struct bfsQueue {
    int head, tail;
    t_qData queue[maxN * maxN];
    
    void add(int x, int y, int distance) {
        tail++;
        queue[tail].p.x = x;
        queue[tail].p.y = y;
        queue[tail].distance = distance;
    }
    
    t_qData pop() {
        int lastHeadPos = head;
        head++;
        
        return queue[lastHeadPos];
    }
    
    void clear() {
        head = 0;
        tail = 0;
    }
    
    bool isEmpty() {
        if (head > tail) return true;
        else return false;
    }
};

int map[maxN][maxN];
t_point destinationMap[maxN];
bfsQueue queue;
int head, tail;
int T, N, maxDestination;




bool isValidPos(int x, int y) {
    if ((x < 1) || (x > N) || (y < 1) || (y > N)) return false;
    if (map[y][x] == 9) return false; // 9 is the monster! don't go there! 
    return true;
}

bool isSamePosition(t_point a, t_point b) {
    if ((a.x == b.x) && (a.y == b.y)) return true;
    else return false;
}





int main()
{
	cin >> T;
    for (int t = 1; t <= T; t++) {
        // read input
        cin >> N >> maxDestination;
        for (int y = 1; y <= N; y++)
            for (int x = 1; x <= N; x++)
                cin >> map[y][x];
                
        // map the destinations (1 to maxDestination)
        for (int y = 1; y <= N; y++)
            for (int x = 1; x <= N; x++)
                if ((map[y][x] != 0) && (map[y][x] <= maxDestination)) {
                    destinationMap[map[y][x]].x = x;
                    destinationMap[map[y][x]].y = y;
                }
        
        // do a sequential loop (from point 1 to 2, 2 to 3, etc..)
        // to find how many shortest path to destination there are
        bool anyPathFound = false;
        int totalDistances = 1;
        int shortestWaysToDestination;
        for (int start = 1; start <= maxDestination-1; start++) {
            shortestWaysToDestination = 0;
            int destination = start+1;
            
            // prepare the queue (reset for every new pair of start-stop)
            head = 0; tail = 0;
            queue.clear();
            queue.add(destinationMap[start].x, destinationMap[start].y, 0);
            
            // do BFS loop
            bool finishFound = false;
            int minimumDistance = 0;
            while (!queue.isEmpty()) {
                t_qData currentData = queue.pop();
                t_point currentPos = currentData.p;
                
                // if we already found a minimum path, check the remaining queue data for
                // the minimum path to finish point (the alternative ways to reach next destination)
                if ((finishFound) && (isSamePosition(currentPos, destinationMap[destination])) && (currentData.distance == minimumDistance)) {
                    shortestWaysToDestination++;
                }
                
                // if we found the finish point for the first time, mark this path and
                // make it the shortest path
                if ((!finishFound) && (isSamePosition(currentPos, destinationMap[destination]))) {
                    finishFound = true;
                    minimumDistance = currentData.distance;
                    shortestWaysToDestination++;
                }
                              
                // if we haven't found the finish, always insert current point's kid to the queue (up, down, left, right)
                if (!finishFound) {
                    if (isValidPos(currentData.p.x, currentData.p.y - 1)) queue.add(currentData.p.x, currentData.p.y - 1, currentData.distance + 1);
                    if (isValidPos(currentData.p.x, currentData.p.y + 1)) queue.add(currentData.p.x, currentData.p.y + 1, currentData.distance + 1);
                    if (isValidPos(currentData.p.x - 1, currentData.p.y)) queue.add(currentData.p.x - 1, currentData.p.y, currentData.distance + 1);
                    if (isValidPos(currentData.p.x + 1, currentData.p.y)) queue.add(currentData.p.x + 1, currentData.p.y, currentData.distance + 1);
                } else { // else we only want to add possible alternative way, where it's distance is not greater than minimumDistance already found
                    if (currentData.distance < minimumDistance) {
                        if (isValidPos(currentData.p.x, currentData.p.y - 1)) queue.add(currentData.p.x, currentData.p.y - 1, currentData.distance + 1);
                        if (isValidPos(currentData.p.x, currentData.p.y + 1)) queue.add(currentData.p.x, currentData.p.y + 1, currentData.distance + 1);
                        if (isValidPos(currentData.p.x - 1, currentData.p.y)) queue.add(currentData.p.x - 1, currentData.p.y, currentData.distance + 1);
                        if (isValidPos(currentData.p.x + 1, currentData.p.y)) queue.add(currentData.p.x + 1, currentData.p.y, currentData.distance + 1);                       
                    }
                }
            } // repeat doing this until the queue is empty
            
            //// debug 
            //cout << start << " to " << destination << " shortest way(s) found = " << shortestWaysToDestination << endl;  
            
            // for every pair of start-stop destinations (1-2, 2-3, 3-4, etc) count the total cost
            if (shortestWaysToDestination != 0) {
                anyPathFound = true;
                totalDistances = totalDistances * shortestWaysToDestination;
            }
        }

        if (anyPathFound) cout << "case #" << t << ": " << totalDistances << endl;
        else cout << "case #" << t << ": " << 0 << endl;
    }
    
    return 0;
}
