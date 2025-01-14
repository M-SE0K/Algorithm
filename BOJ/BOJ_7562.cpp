// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>

// #define X first
// #define Y second

// using namespace std;

// int board[305][305] = {};
// int dx[8] = { 1, 2, -1, -2, 1, 2, -1, -2 };
// int dy[8] = { 2, 1, -2, -1, -2, -1, 2, 1 };

// int Size;
// pair<int, int> p1, p2;
// int vis[305][305] = {};

// void BFS();
// int main()
// {
// 	int T;
// 	cin >> T;

// 	while (T--)
// 	{
// 		int num1, num2;

// 		cin >> Size;
		
// 		cin >> num1 >> num2;
// 		p1 = {num1, num2};

// 		cin >> num1 >> num2;
// 		p2 = { num1, num2 };

// 		BFS();

// 		for (int i = 0; i < Size; i++)
// 			for (int j = 0; j < Size; j++)
// 			{
// 				board[i][j] = 0;
// 				vis[i][j] = 0;
// 			}
// 	}
// }

// void BFS()
// {
// 	queue <pair<int, int>> Q;
// 	Q.push({ p1.X, p1.Y });

// 	while (!Q.empty())
// 	{
// 		pair<int, int> coordinate = (Q.front());
// 		Q.pop();

// 		if (coordinate.X == p2.X && coordinate.Y == p2.Y)
// 		{
// 			cout << vis[coordinate.X][coordinate.Y] << '\n';
// 			return;
// 		}

// 		for (int dir = 0; dir < 8; dir++)
// 		{
// 			int nx = coordinate.X + dx[dir];
// 			int ny = coordinate.Y + dy[dir];

// 			if (nx < 0 || ny < 0 || Size <= nx || Size <= ny)	continue;
// 			if (vis[nx][ny])	continue;
			
// 			vis[nx][ny] = vis[coordinate.X][coordinate.Y] + 1;
// 			Q.push({ nx, ny });
// 		}
// 	}
// }