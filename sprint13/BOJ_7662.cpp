#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		priority_queue<int, vector<int>, greater<int>> ascPQ;
		priority_queue<int> dscPQ;
		map<int, int> countMap;
		int k;
		cin >> k;

		for (int j = 0; j < k; j++) {
			char mode;
			int n;

			cin >> mode >> n;

			if (mode == 'I') {
				ascPQ.push(n);
				dscPQ.push(n);

				countMap[n]++;
			}
			else {
				if (n == 1) {
					while (!dscPQ.empty() && countMap[dscPQ.top()] <= 0) dscPQ.pop();
					if (!dscPQ.empty()) {
						countMap[dscPQ.top()]--;
						dscPQ.pop();
					}
				}
				else {
					while (!ascPQ.empty() && countMap[ascPQ.top()] <= 0) ascPQ.pop();
					if (!ascPQ.empty()) {
						countMap[ascPQ.top()]--;
						ascPQ.pop();
					}
				}
			}
		}

		while (!dscPQ.empty() && countMap[dscPQ.top()] <= 0) dscPQ.pop();
		while (!ascPQ.empty() && countMap[ascPQ.top()] <= 0) ascPQ.pop();

		if (dscPQ.empty() || ascPQ.empty()) cout << "EMPTY" << '\n';
		else cout << dscPQ.top() << ' ' << ascPQ.top() << '\n';
	}
}
