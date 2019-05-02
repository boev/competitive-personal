#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

int p, q;

int findBest(std::vector<int> &add, std::vector<int> &sub) {
	int ans = 0;
	int ansVal = sub.size();
	int current = sub.size();
	int y = 0;
	size_t iN = 0, iS = 0;
	while (iN < add.size() && iS < sub.size()) {
		int currentMin = std::min(add[iN], sub[iS]);
		if (sub[iS] == currentMin) {
			// favor substraction
			current--;
			iS++;
			continue;
		}
		if (add[iN] == currentMin) {
			current++;
			if (ansVal < current) {
				ans = add[iN];
				ansVal = current;
			}
			iN++;
			continue;
		}

	}
	while (iN < add.size()) {
		current++;
		if (ansVal < current) {
			ansVal = current;
			ans = add[iN];
		}
		iN++;
	}
	return ans;
}

void solve(int caseNum) {
	scanf("%d %d", &p, &q);

	std::map<char, std::vector<int>> data;

	data['N'].resize(0);
	data['S'].resize(0);
	data['E'].resize(0);
	data['W'].resize(0);
	char c;
	int x, y;

	for (int i = 0; i < p; i++) {
		scanf("%d %d %c", &x, &y, &c);
		if (c == 'N') {
			data[c].push_back(y + 1);
		}
		if (c == 'S') {
			data[c].push_back(y);
		}
		if (c == 'E') {
			data[c].push_back(x + 1);
		}
		if (c == 'W') {
			data[c].push_back(x);
		}
	}
	sort(data['N'].begin(), data['N'].end());
	sort(data['S'].begin(), data['S'].end());
	sort(data['E'].begin(), data['E'].end());
	sort(data['W'].begin(), data['W'].end());

// find best y
	int ansY = findBest(data['N'], data['S']);

// find best x
	int ansX = findBest(data['E'], data['W']);

	printf("Case #%d: %d %d\n", caseNum, ansX, ansY);

}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
