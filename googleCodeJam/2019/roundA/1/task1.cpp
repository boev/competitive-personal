#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

void solve() {
	std::vector<std::string> words;
	std::unordered_map<std::string, int> suff;
	std::unordered_map<std::string, std::vector<int>> cnt;

	std::vector<int> used;

	int n;
	std::cin >> n;
	words.resize(n);
	used.resize(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> words[i];
		for (int k = words[i].length() - 1; k >= 0; k--) {
			suff[words[i].substr(k, words[i].length() - 1)]++;
			cnt[words[i].substr(k, words[i].length() - 1)].push_back(i);
		}

	}

	int ans = 0;
	for (auto& m : suff) {
		if (m.second == 2 && used[cnt[m.first][0]] == 0 && used[cnt[m.first][0]] == 0) {
			ans++;
			used[cnt[m.first][0]] = 1;
			used[cnt[m.first][0]] = 1;
		}
	}

}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}
