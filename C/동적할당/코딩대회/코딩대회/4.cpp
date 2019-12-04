#define MAX 5
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> map[MAX];
queue<int> q;
bool visit[MAX];

void bfs(int start) {
	
	memset(visit, false, sizeof(visit));
	visit[start] = true;

	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; r++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

}