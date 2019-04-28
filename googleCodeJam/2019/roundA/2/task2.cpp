#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

int t;
int n;
int g;
std::vector<int> primes { 16, 9, 5, 7, 11, 13, 17 };

void solve() {
	int r;
	std::vector<int> nums;
	nums.resize(g + 1, 0);

	int ans = 0;

	for (int p : primes) {
		for (int i = 0; i < 18; i++) {
			std::cout << p;
			if (i < 17)
				std::cout << " ";
			else {
				std::cout << "\n" << std::flush;
			}
		}
		int sum = 0;
		for (int i = 0; i < 18; i++) {
			std::cin >> r;
			sum += r;
		}

		sum %= p;
		for (int i = sum; i <= g; i += p) {
			nums[i]++;
			if (nums[i] == 7) {
				ans = i;
				break;
			}
		}
	}

	std::cout << ans << std::endl << std::flush;

	int rslt;
	std::cin >> rslt;
	if (rslt < 0) {
		exit(1);
	}

}
int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//scanf("%d %d %d", &t, &n, &g);
	std::cin >> t >> n >> g;

	for (int i = 0; i < t; i++) {
//		printf("Case #%d: ", i + 1);
		solve();
	}

	return 0;
}
