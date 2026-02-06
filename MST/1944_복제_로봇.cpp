#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;

typedef struct Edge {
	int u, v, w;
	bool operator> (const Edge &tmp) const {
		return w > tmp.w;
	}
} Edge;

int n, m, keycnt;
int foundkey = 0;
int map[51][51];
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int parent[260];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool visited[55][55];

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) parent[b] = a;
}

void bfs(int x, int y, int node) {
	queue<tuple<int,int,int>> q;
	int dist;
	visited[x][y] = true;
	q.push({x, y, 0});
	while(!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		dist = get<2>(q.front());
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(0<=nx&&nx<n&&0<=ny&&ny<n&&!visited[nx][ny]&&map[nx][ny]!=-1) {
				if(map[nx][ny] != 0) {
					// cout << node << " -> " << nx << ", " << ny << " = " << dist+1 << " : " << int(map[nx][ny]) << endl; //
					pq.push(Edge{node, map[nx][ny], dist + 1});
				}
				visited[nx][ny] = true;
				q.push({nx, ny, dist + 1});
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 1;
	char tmp;
	cin >> n >> keycnt;
	keycnt++; // 시작 지점까지 고려
	for(int i=0; i<=keycnt; i++) parent[i] = i;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> tmp;
			if(tmp == '1') map[i][j] = -1;
			if(tmp == '0') map[i][j] = 0;
			if(tmp == 'K') {
				map[i][j] = ++cnt; // 숫자로 들어가는거! 주의!!
			}
			else if(tmp == 'S') {
				map[i][j] = 1;
			}
		}
	}

	// for test
	// cout << endl;
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << int(map[i][j]) << " ";
	// 	} cout << endl;
	// }
	// cout << endl;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] != -1 && map[i][j] != 0) {
				// cout << "call: " << i << ", " << j << " : " << int(map[i][j]) << endl; //
				fill(&visited[0][0], &visited[n][n], false);
				bfs(i, j, map[i][j]);
			}
		}
	}

	int usedEdge = 0;
	ll totalsum = 0;
	while(usedEdge < keycnt - 1) {
		if(pq.empty()) {
			totalsum = -1;
			break;
		}
		Edge tmp = pq.top();
		pq.pop();
		if(find(tmp.u) != find(tmp.v)) {
			unionfunc(tmp.u, tmp.v);
			usedEdge++;
			totalsum += tmp.w;
		}
	}

	cout << totalsum;
}