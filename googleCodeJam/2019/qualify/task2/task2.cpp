#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

void solve() {
	int n;
	scanf("%d\n", &n);
	char c;
	char ourFirstMove;
	char ourOtherMove;

	int crossing = -1;
	int lidS = 0;
	int lidE = 0;
	char lidPrev;
	std::unordered_map<char, int> moves;
	moves['E'] = 0;
	moves['S'] = 0;

	for (int i = 0; i < 2 * n - 2; i++) {
		scanf("%c", &c);
		if (crossing != -1) {
			continue;
		}

		if (c != 'E' && c != 'S') {
			//error in read?
			printf("Error in read....\n");
			exit(1);
		}
		moves[c]++;
		if (i == 0) {
			// first move
			lidPrev = c;
			if (c == 'E') {
				ourFirstMove = 'S';
				ourOtherMove = 'E';
				continue;
			}
			if (c == 'S') {
				ourFirstMove = 'E';
				ourOtherMove = 'S';
				lidS++;
				continue;
			}
			// error
			printf("Error on first character\n");
			exit(1);
		} else {
			// look for a crossing;
			if (c == ourFirstMove && lidPrev == ourFirstMove) {
				// corssing found;
				// cross at SS e.g. horizontal
				// cross vertial, because she has done EE
				crossing = moves[c] - 1;
			}
			lidPrev = c;
		}
	}

	char lidLast = c;
	// Cases
	if (ourFirstMove == lidLast) {
		// go directly, no crossing
		for (int i = 0; i < n - 1; i++) {
			std::cout << ourFirstMove;
		}
		for (int i = 0; i < n - 1; i++) {
			std::cout << ourOtherMove;
		}
		std::cout << std::endl;
		return;
	} else {
		// we need to cross somewhere, luckily we already know where!
		// Here crossing cannot be -1, in this case solution does not exist
		for (int i = 0; i <= crossing - 1; i++) {
			std::cout << ourFirstMove;
		}
		for (int i = 0; i < n - 1; i++) {
			std::cout << ourOtherMove;
		}
		for (int i = crossing + 1; i <= n - 1; i++) {
			std::cout << ourFirstMove;
		}
		std::cout << std::endl;
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}

	return 0;
}
