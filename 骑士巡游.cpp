// 左上角是（0,0）
#define _CRT_SECURE_NO_WARNINGS 1
#define N 8
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int board[N][N] = { 0 };
int step = 1;

typedef struct coordinate
{
	int x;
	int y;
}cdn;

vector<cdn> ans;

int options(cdn x)
{
	int ret = 0;
	if (x.x + 1 < N && x.y + 2 < N && board[x.x + 1][x.y + 2] == 0)
		ret++;
	if (x.x + 2 < N && x.y + 1 < N && board[x.x + 2][x.y + 1] == 0)
		ret++;
	if (x.x + 2 < N && x.y - 1 >= 0 && board[x.x + 2][x.y - 1] == 0)
		ret++;
	if (x.x + 1 < N && x.y - 2 >= 0 && board[x.x + 1][x.y - 2] == 0)
		ret++;
	if (x.x - 1 >= 0 && x.y - 2 >= 0 && board[x.x - 1][x.y - 2] == 0)
		ret++;
	if (x.x - 2 >= 0 && x.y - 1 >= 0 && board[x.x - 2][x.y - 1] == 0)
		ret++;
	if (x.x - 2 >= 0 && x.y + 1 < N && board[x.x - 2][x.y + 1] == 0)
		ret++;
	if (x.x - 1 >= 0 && x.y + 2 < N && board[x.x - 1][x.y + 2] == 0)
		ret++;
	return ret;
}

bool quick(cdn x, cdn y)
{
	int num_x = options(x);
	int num_y = options(y);
	return num_x < num_y;
}

bool is_over()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] == 0)
				return false;
	return true;
}

bool deep_search(int x, int y)
{
	if (is_over())
		return true;

	vector<cdn> options;
	cdn next = { -1,-1 };
	if (x - 1 >= 0 && y + 2 < N && board[x - 1][y + 2] == 0)
	{
		next.x = x - 1;
		next.y = y + 2;
		options.push_back(next);
	}
	if (x - 2 >= 0 && y + 1 < N && board[x - 2][y + 1] == 0)
	{
		next.x = x - 2;
		next.y = y + 1;
		options.push_back(next);
	}
	if (x - 2 >= 0 && y - 1 >= 0 && board[x - 2][y - 1] == 0)
	{
		next.x = x - 2;
		next.y = y - 1;
		options.push_back(next);
	}
	if (x - 1 >= 0 && y - 2 >= 0 && board[x - 1][y - 2] == 0)
	{
		next.x = x - 1;
		next.y = y - 2;
		options.push_back(next);
	}
	if (x + 1 < N && y - 2 >= 0 && board[x + 1][y - 2] == 0)
	{
		next.x = x + 1;
		next.y = y - 2;
		options.push_back(next);
	}
	if (x + 2 < N && y - 1 >= 0 && board[x + 2][y - 1] == 0)
	{
		next.x = x + 2;
		next.y = y - 1;
		options.push_back(next);
	}
	if (x + 2 < N && y + 1 < N && board[x + 2][y + 1] == 0)
	{
		next.x = x + 2;
		next.y = y + 1;
		options.push_back(next);
	}
	if (x + 1 < N && y + 2 < N && board[x + 1][y + 2] == 0)
	{
		next.x = x + 1;
		next.y = y + 2;
		options.push_back(next);
	}

	if (options.size() == 0)
		return false;
	sort(options.begin(), options.end(), quick);

	int next_x = -1, next_y = -1;
	for (int i = 0; i < options.size(); i++)
	{
		next_x = options[i].x;
		next_y = options[i].y;
		board[next_x][next_y] = step;
		++step;

		if (deep_search(next_x, next_y))
			return true;
		else
		{
			board[next_x][next_y] = 0;
			--step;
		}
	}

	return false;
}

int main()
{
	int x, y;
	cin >> x >> y;

	board[x][y] = step;
	++step;
	bool is_ans = deep_search(x, y);

	if (is_ans)
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf("%-5d", board[i][j]);
			cout << endl;
		}
	else
		cout<< "No Answer";
		
	return 0;
}