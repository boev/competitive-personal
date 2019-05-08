#include <iostream>
#include <unordered_map>
#include <string>

int r, c;
std::unordered_map<std::string, bool> states;

std::pair<std::string, int> placeVertical(const std::string &s, int i, int j) {
	int index = i * c + j;
	std::string nextState = s;
	bool terminate = false;

	// place cell
	nextState[index] = 'p';

	// go up
	int move = index;

	move -= c;
	if (move >= 0 && s[move] == '#') {
		terminate = true;
	}

	//go down
	move = index;
	int skip = 0;
	while (1) {
		move += c;
		if (move >= s.length()) {
			break;
		}
		if (s[move] == '#') {
			terminate = true;
			break;
		}
		if (s[move] == '.') {
			skip++;
			nextState[move] = 'p';
			continue;
		}
		break;
	}
	return std::make_pair(terminate ? "" : nextState, skip);
}

std::pair<std::string, int> placeHorizontal(const std::string &s, int i,
		int j) {
	int index = i * c + j;
	std::string nextState = s;
	bool terminate = false;

	// place cell
	nextState[index] = 'p';

	// look radioactive left
	int move = index;
	move--;
	if (move >= i * c && s[move] == '#') {
		terminate = true;
	}

	// go right
	move = index;
	int skip = 0;
	while (1) {
		move++;
		if (move >= (i + 1) * c) {
			break;
		}
		if (s[move] == '#') {
			terminate = true;
			break;
		}
		if (s[move] == '.') {
			nextState[move] = 'p';
			skip++;
			continue;
		}
		break;
	}
	return std::make_pair(terminate ? "" : nextState, skip);
}

int play(std::string &state) {
	int win = 0;
	int loss = 0;
	for (int j = 0; j < c; j++) {
		for (int i = 0; i < r; i++) {
			if (state[i * c + j] != '.')
				continue;
			std::pair<std::string, int> vpair = placeVertical(state, i, j);
			if (vpair.first != "") {
				if (states.find(vpair.first) == states.end()) {
					play(vpair.first);
				}
				if (states[vpair.first] == true) {
					win = win + 1 + vpair.second;
				} else {
					loss = loss + 1 + vpair.second;
				}
			}

			i += vpair.second;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (state[i * c + j] != '.')
				continue;
			std::pair<std::string, int> hpair = placeHorizontal(state, i, j);
			if (hpair.first != "") {
				if (states.find(hpair.first) == states.end()) {
					play(hpair.first);
				}
				if (states[hpair.first] == true) {
					win = win + 1 + hpair.second;
				} else {
					loss = loss + 1 + hpair.second;
				}

			}
			j += hpair.second;
		}
	}
	if (loss == 0) {
		states[state] = false;
	} else {
		states[state] = true;
	}

//	std::cout << "State : " << state << " is " << states[state] << std::endl;
	return loss; // return number of winning moves
}

void solve(int testCase) {
	std::cin >> r >> c;

	std::string initial = "";
	states.clear();
	std::string s;
	for (int i = 0; i < r; i++) {
		std::cin >> s;
		initial += s;
	}

	//becca = 0
	int winning_moves = play(initial);

	printf("Case #%d: %d\n", testCase, winning_moves);
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
	return 0;
}
