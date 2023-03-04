#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int arr[1000][1000][2];
int diri[4] = { -1,1,0,0 };
int dirj[4] = { 0,0,-1,1 };
int initialday = 1000005;

typedef struct Coordinate {
	int x, y;
}Coordinate;

queue<Coordinate> q;

void BFS() {
	while (!q.empty()) {
		Coordinate currentTomato = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Coordinate nextTomato = { currentTomato.x + dirj[i], currentTomato.y + diri[i] };

			if (nextTomato.x >= 0 && nextTomato.y >= 0 && nextTomato.x < M && nextTomato.y < N && arr[nextTomato.y][nextTomato.x][0] != -1 &&
				arr[nextTomato.y][nextTomato.x][1] > arr[currentTomato.y][currentTomato.x][1] + 1) {
				q.push(nextTomato);
				arr[nextTomato.y][nextTomato.x][1] = arr[currentTomato.y][currentTomato.x][1] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j][0];
			if (arr[i][j][0] == 1) {
				arr[i][j][1] = 0;
				q.push({ j,i });
			}
			else
				arr[i][j][1] = initialday;
		}
	}

	BFS();

	int maxday = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j][0] != -1) {
				if (arr[i][j][1] == initialday) {
					cout << -1;
					return 0;
				}
				else
					maxday = max(maxday, arr[i][j][1]);
			}
		}
	}

	cout << maxday;
}
