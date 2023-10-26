#pragma once
#include <vector>
#include <utility>

class Game {
	std::vector<std::vector<int>> curr_board;
	std::vector<std::vector<int>> prev_board;
	const int n;
	const int m;

public:
	Game(int n, int m) : 
		curr_board(std::vector<std::vector<int>>(n, std::vector<int>(m,0))),
		prev_board(std::vector<std::vector<int>>(n, std::vector<int>(m, 0))),
		n(n),
		m(m)
	{}

	inline void setAlive(int x, int y) {
		if (0 <= x && x < n && 0 <= y && y < m) {
			curr_board[x][y] = -1;
		}
	}
	inline void setDead(int x, int y) {
		if (0 <= x && x < n && 0 <= y && y < m) {
			curr_board[x][y] = 0;
		}
	}

	inline bool getCurrAlive(int x, int y) {
		return curr_board[x][y] == -1;
	}

	inline void update() {
		std::swap(prev_board, curr_board);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int count = 0;
				if (i - 1 >= 0 && prev_board[i - 1][j] == -1) {
					count++;
				}
				if (j - 1 >= 0 && prev_board[i][j-1] == -1) {
					count++;
				}
				if (i + 1 < n && prev_board[i + 1][j] == -1) {
					count++;
				}
				if (j + 1 < m && prev_board[i][j+1] == -1) {
					count++;
				}
				if (i - 1 >= 0 && j - 1 >= 0 && prev_board[i - 1][j-1] == -1) {
					count++;
				}
				if (i - 1 >= 0 && j + 1 <m && prev_board[i-1][j + 1] == -1) {
					count++;
				}
				if (i + 1 <n && j + 1 < m && prev_board[i + 1][j + 1] == -1) {
					count++;
				}
				if (i + 1 < n && j - 1 >= 0 && prev_board[i + 1][j - 1] == -1) {
					count++;
				}

				if(count == 3){
					curr_board[i][j] = -1;
				}
				else if (prev_board[i][j] == -1 && count == 2) {
					curr_board[i][j] = -1;
				}
				else {
					curr_board[i][j] = 0;
				}
			}
		}
	}
};