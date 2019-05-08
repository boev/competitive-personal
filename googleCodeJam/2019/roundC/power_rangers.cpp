#include <iostream>
#include <unordered_map>
#include <vector>

std::string ask(int pos) {
	std::string c;
	std::cout << pos << std::endl;
	std::cin >> c;
	return c;
}

int solve(int t) {

	std::string ans = "";
	std::unordered_map<std::string, bool> used;
	std::unordered_map<std::string, std::vector<int>> data;
	for (int i = 0; i < 5; i++) {
		data[ans].push_back(i * 3 + 1);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < data[ans].size(); j++) {
			data[ans + ask(data[ans][j] + i)].push_back(data[ans][j]);
		}
		int min = 25;
		std::string nextLetter;
		for (auto c : { "A", "B", "C" }) {
			if (i == 0)
				used[c] = false;
			if (!used[c] && data[ans + c].size() < min) {
				nextLetter = c;
				min = data[ans + c].size();
			}
		}
		std::cout << min << std::endl;
		ans += nextLetter;
		used[nextLetter] = true;
	}

	for (auto c : { "A", "B", "C" }) {
		if (!used[c]) {
			ans += c;
			break;
		}
	}

	std::string verdict;

	std::cout << ans << std::endl;
	std::cin >> verdict;
	if (verdict == "N") {
		return 0; // stop
	}
	return 1;
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int t, f;
	std::cin >> t >> f;
	for (int i = 1; i <= t; i++) {
		if (!solve(i))
			break;
	}

	return 0;
}
