#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

struct rsp {
	std::unordered_map<char, int> cnt;
};

void setBit(int &mask, char c) {
	if (c == 'R')
		mask = mask | (1 << 2);
	if (c == 'P')
		mask = mask | (1 << 1);
	if (c == 'S')
		mask = mask | (1 << 0);
}

void solve(int caseNum) {
	int n;
	scanf("%d", &n);

	std::vector<bool> defeated;
	defeated.resize(n, false);

	std::vector<std::string> prog;
	prog.resize(n);

	for (int i = 0; i < n; i++) {
		std::cin >> prog[i];
	}

	std::string winning = "";
	bool impossible = true;
	for (int i = 0; i < 500; i++) {
		int mask = 0;
		for (int r = 0; r < n; r++) {
			if (defeated[r] == false) {
				setBit(mask, prog[r].at(i % prog[r].size()));
			}
		}

		char del;

		if (mask == 7) {
			break;
		}
		if (mask == 1) {
			// put R
			winning += 'R';
			impossible = false;
			break;
		}
		if (mask == 2) {
			winning += 'S';
			impossible = false;
			break;
		}
		if (mask == 3) {
			winning += 'S';
			del = 'P';
		}
		if (mask == 4) {
			winning += 'P';
			impossible = false;
			break;
		}
		if (mask == 5) {
			winning += 'R';
			del = 'S';
		}
		if (mask == 6) {
			winning += 'P';
			del = 'R';
		}

		for (int r = 0; r < n; r++) {
			if (defeated[r] == false && prog[r].at(i % prog[r].size()) == del) {
				defeated[r] = true;
			}
		}
	}
	if (impossible) {
		printf("Case #%d: IMPOSSIBLE\n", caseNum);
	} else {
		printf("Case #%d: %s\n", caseNum, winning.c_str());
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
