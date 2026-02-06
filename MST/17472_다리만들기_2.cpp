#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

typedef struct Edge {
	int u1, v1, u2, v2, w;
	bool operator> (const Edge &tmp) const {
		return w > tmp.w;
	}
} Edge;

int n, m;
int map[15][15];
vector<Edge> edges;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int parent[15];

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) parent[b] = a;
}

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
void dfs(int x, int y, int tar) {
	map[x][y] = tar;
	for(int k=0; k<4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(1<=nx&&nx<=n&&1<=ny&&ny<=m && map[nx][ny] == 1) {
			dfs(nx, ny, tar);
		}
	}
}

void makebridge(int x, int y, int tar) {
	for(int k=0; k<4; k++) {
		bool visited[10] = {};
		visited[tar] = true;
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(1<=nx&&nx<=n&&1<=ny&&ny<=m) {
			int dist = 0, beftar = map[nx][ny];
			if(map[nx][ny] == tar) { // 본인 섬
				continue;
			}
			else if(map[nx][ny] == 0) { // 바다
				int tmpx = nx, tmpy = ny;
				while(1<=tmpx&&tmpx<=n&&1<=tmpy&&tmpy<=m) {
					if(visited[map[tmpx][tmpy]]) break;
					if(map[tmpx][tmpy]!=0 && map[tmpx][tmpy] != tar && 
						(beftar == 0 || beftar != map[tmpx][tmpy])) { // 본인 섬X
						if(dist < 2) break;
						// cout << x << y << tmpx << tmpy << dist << endl;
						visited[map[tmpx][tmpy]] = true;
						edges.push_back(Edge {x, y, tmpx, tmpy, dist});
						pq.push(Edge {x, y, tmpx, tmpy, dist});
						break;
					}
					beftar = map[tmpx][tmpy];
					tmpx += dx[k]; tmpy += dy[k];
					dist++;
				}
			}	
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> map[i][j];
		}
	}

	// 섬별로 구분
	int island_cnt = 2;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(map[i][j] == 1) {
				dfs(i, j, island_cnt++);
			}
		}
	}
	// union find 초기화
	for(int i=0; i<island_cnt; i++) {
		parent[i] = i;
	}

	// // for test
	// cout << endl;
	// for(int i=1; i<=n; i++) {
	// 	for(int j=1; j<=m; j++) {
	// 		cout << map[i][j] << " ";
	// 	} cout << endl;
	// }

	// 다리를 간선 정보로 변환
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(map[i][j]) {
				makebridge(i, j, map[i][j]);
			}
		} 
	}
	
	// for test
	// cout << endl;
	// for(int i=0; i<edges.size(); i++) {
	// 	cout << edges[i].u1 << ", " << edges[i].v1 << " | ";
	// 	cout << edges[i].u2 << ", " << edges[i].v2 << " = " << edges[i].w << endl;
	// }

	int usedEdge = 0;
	int ans = 0;
	// cout << endl << endl; // for test
	while(usedEdge < island_cnt-3) {
		if(pq.empty()) {
			ans = -1;
			break;
		}
		Edge e = pq.top();
		pq.pop();
		if(find(map[e.u1][e.v1]) != find(map[e.u2][e.v2])) { // 서로 다른 섬이라면
			// for test
			unionfunc(map[e.u1][e.v1], map[e.u2][e.v2]);
			// cout << e.u1 << ", " << e.v1 << " | ";
			// cout << e.u2 << ", " << e.v2 << " = " << e.w << endl;
			usedEdge++;
			ans += e.w;
		}
	}

	cout << ans;
}