#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

void solve() {
	bool bBegun = false;
	std::string n = "";
	std::string a, b;
	a = "";
	b = "";

	std::cin >> n;

	for (char& c : n) {
		if (!isdigit(c)) {
			// this should not happen
			continue;
		}
		if (c == '4') {
			bBegun = true;
			a += '1';
			b += '3';
		} else {
			a += c;
			if (bBegun) {
				b += '0';
			}
		}
	}

	std::cout << a << " " << b << std::endl;

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
