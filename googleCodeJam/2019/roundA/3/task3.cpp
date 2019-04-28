#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

void solve(int caseNum) {
	int r, c;

	std::vector<std::pair<int, int>> moves;
	std::vector<std::vector<int>> p;
	std::vector<std::vector<int>> used;
	std::cin >> r >> c;
	p.resize(r + 1);
	used.resize(r + 1);
	for (int i = 1; i <= r; i++) {
		p[i].resize(c + 1, 0);
		used[i].resize(c + 1, 0);
		for (int j = 1; j <= c; j++) {
			p[i][j] = r * c + 1;
			p[i][j] -= r;
			p[i][j] -= c;
			p[i][j] -= std::min(j - 1, i - 1);
			p[i][j] -= std::min(i - 1, c - j);
			p[i][j] -= std::min(j - 1, r - i);
			p[i][j] -= std::min(c - j, r - i);
//			printf("%d ", p[i][j]);
		}
//		printf("\n");
	}

	int visited = 0;
	int ci = 1;
	int cj = 1;

	while (1) {
		// update board
		used[ci][cj] = 1;
		visited++;
		moves.push_back(std::make_pair(ci, cj));
//		printf("move is: %d %d\n", ci, cj);
		if (visited == r * c)
			break;
		// next move
		int nexti = -1;
		int nextj = -1;
		int min = r * c;

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (i == ci || j == cj || ci - cj == i - j
						|| ci + cj == i + j) {
					continue;
				}
				p[i][j]--;
				if (used[i][j] == 0) {
					if (min > p[i][j]) {
						nexti = i;
						nextj = j;
						min = p[i][j];
					}
				}
			}
		}

		if (nexti > 0) {
			ci = nexti;
			cj = nextj;
		} else {
			break;
		}
	}

	if (visited == r * c) {
		printf("Case #%d: POSSIBLE\n", caseNum);
		for (auto& a : moves) {
			std::cout << a.first << " " << a.second << "\n";
		}
	} else {
		printf("Case #%d: IMPOSSIBLE\n", caseNum);
	}

}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		solve(i+1);
	}

	return 0;
}
