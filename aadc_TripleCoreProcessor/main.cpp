#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct t_data {
	int arrival;
	int length;
};

int T, N;
t_data inputan[1000];
int cpuTime[5 + 1], proc;

int main() {
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		// read input
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> inputan[i].arrival;
			cin >> inputan[i].length;
		}

		// sort input?

		// do simulation;
		bool isImpossible = false;
		proc = 1;
		cpuTime[proc] = inputan[0].arrival + inputan[0].length - 1;
		for (int i = 1; i < N; i++) {
			if (isImpossible) continue;

			// try assign to available processors
			bool cpuAvailable = false;
			for (int q = 1; q <= proc; q++) {
				if ((!cpuAvailable) && (cpuTime[q] + inputan[i].length - inputan[i].arrival + 1 <= 10)) {
					cpuAvailable = true;
					if (cpuTime[q] < inputan[i].arrival) cpuTime[q] = inputan[i].arrival + inputan[i].length - 1;
					else cpuTime[q] += inputan[i].length;
				}
			}

			// if no processor available, try adding new core!
			if ((!cpuAvailable) && (proc < 5)) {
				proc++;
				cpuTime[proc] = inputan[i].arrival + inputan[i].length - 1;
				cpuAvailable = true;
			}

			// else this job is impossible!
			if (!cpuAvailable) {
				isImpossible = true;
			}
		}

		// write output
		cout << "#" << t << " ";
		if (isImpossible) cout << -1 << endl;
		else cout << proc << endl;
	};

	return 0;
}
