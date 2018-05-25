#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int N, result;
int arr[101][101];
int visit[101][101];
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
vector<int> v;

void dfs(int x, int y, int cnt) {
	visit[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
			if(!visit[nx][ny] && arr[nx][ny] == 1)
				dfs(nx, ny, cnt);
		}
	}
}

void bfs(int check) {
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1 && visit[i][j] == check) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
				if (!visit[nx][ny] && arr[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					arr[nx][ny] = arr[fx][fy] + 1;
					visit[nx][ny] = visit[fx][fy];
				}
				if (visit[nx][ny] != visit[fx][fy]) {
					result = arr[fx][fy];
					v.push_back(result);
					return;
				}
			}
		}
	}
}

int main() {
	int cnt = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && arr[i][j] == 1) {		
				dfs(i,j,cnt);
				cnt++;
			}
		}
	}
	for (int i = 1; i <= cnt - 1; i++) {
		bfs(i);
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][k] != 1) {
					visit[j][k] = 0;
					arr[j][k] = 0;
				}
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", v.front()-1);

	return 0;
}