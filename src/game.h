#pragma once
#include <vector>

class Game {
	std::vector<std::vector<int>> curr_board;
	std::vector<std::vector<int>> next_board;
	const int n;
	const int m;

public:
	Game(int n, int m) : 
		curr_board(std::vector<std::vector<int>>(n, std::vector<int>(m,0))),
		next_board(std::vector<std::vector<int>>(n, std::vector<int>(m, 0))),
		n(n),
		m(m)
	{}

	inline void alive(int x, int y) {
		if (0 <= x && x < n && 0 <= y && y < m) {
			curr_board[x][y] = 1;
		}
	}
	inline void dead(int x, int y) {
		if (0 <= x && x < n && 0 <= y && y < m) {
			curr_board[x][y] = 0;
		}
	}
};