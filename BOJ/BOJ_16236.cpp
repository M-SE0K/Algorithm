// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int board[22][22]; //물고기를 입력 받을 이차원 배열
// int check[22][22]; //물고기로부터 얼마나 떨어져 잇는지를 기록하기 위한 이차원 배열

// int dx[4] = { 1, 0, -1, 0 };
// int dy[4] = { 0, 1, 0, -1 };
// int second = 0, babysize = 2, N, x, y;
// int eatfish = 0;
// //최종 결과값 second, 아기 상어의 사이즈인 babysize, 입력값 N, 아기 상어의 위치인 x, y
// //eatfish는 아기 상어가 얼마만큼의 물고기를 먹었는지

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);


// 	cin >> N;
// 	for (int i = 0; i < N; i++) //입력을 받기 위한 이중 반복문
// 		for (int j = 0; j < N; j++)
// 		{
// 			cin >> board[i][j];
// 			if (board[i][j] == 9) //아기 상어의 위치를 알고 시작해야 편하기 때문에 입력 받는 동시에 조건문으로 좌표를 미리 저장해둔다.
// 			{
// 				x = i;
// 				y = j;
// 			}
// 		}

// 	while (1)
// 	{
// 		for (int i = 0; i < N; i++) //물고기의 위치가 바뀔 때마다 계속 새롭게 탐색을 해줘야 되니 매번 -1로 바꿔줘야 한다.
// 			for (int j = 0; j < N; j++)
// 				check[i][j] = -1;

// 		check[x][y] = 0; //(x, y)좌표가 시작지점으로 거리는 0이라는 의미
// 		board[x][y] = 0; //처음 시작할 때 아기 상어가 9로 되어 있으므로 0으로 바꿔줘야 한다. why -> 바꾸지 않으면 물고기의 크기를 9로 인식하는 오류가 발생할 수 있기 때문이다.

// 		queue <pair<int, int>> Q; //아기 상어의 시작 위치를 넣어줄 큐이고
// 		vector <pair<int, int>> fish; // 아기 상어가 먹을 수 있는 물고기의 좌표를 넣어줄 vector이다.
		
// 		if (eatfish >= babysize) //아기 상어의 크기보다 먹은 물고기의 양이 크다면 아기 상어의 크기를 키워주고 아기 상어의 크기만큼 먹은 물고기의 양을 빼준다.
// 		{
// 			eatfish -= babysize;
// 			babysize++;
// 		}

// 		Q.push({ x, y }); //BFS를 돌리기 위해서 넣어줌
// 		while (!Q.empty())
// 		{
// 			auto cur = Q.front();
// 			Q.pop();

// 			for (int dir = 0; dir < 4; dir++) //현재의 위치(큐에 담겨 있는 좌표)를 기준으로 상하좌우를 탐색하기 위한 반복문
// 			{
// 				int nx = cur.first + dx[dir]; //상하좌우를 탐색하기 위한 x축 변수
// 				int ny = cur.second + dy[dir]; //상하좌우를 탐색하기 위한 y축 변수

// 				if (nx < 0 || ny < 0 || N <= nx || N <= ny)	continue; //상하좌우를 탐색하기 위해 조합된 변수들이 범위에서 벗어날 경우 탐색하지 못하기 때문에 continue함
// 				if (check[nx][ny] != -1)	continue; //이미 방문한 곳 or 거리가 입력된 경우 continue
// 				if (board[nx][ny] > babysize)	continue; //물고기의 크기가 상어의 크기보다 큰 경우 continue
// 				else if (board[nx][ny] == babysize || board[nx][ny] == 0) //물고기의 크기 == 상어의 크기 or 아기 상어의 좌표인 경우 지나갈 수 있는 경로
// 				{
// 					check[nx][ny] = check[cur.first][cur.second] + 1; //지나갈 수 있으므로 지나가면서 거리를 측정하기 위해 check배열에 + 1을 하여 거리를 셈한다.
// 					Q.push({ nx, ny }); //지나갈 수 있는 길이므로 큐에 넣고 BFS를 돌린다.
// 				}
// 				else if (board[nx][ny] < babysize && board[nx][ny] >= 1) //물고기의 크기가 1보다 크거나 같다 == (빈칸이 아닌 물고기가 존재하는 칸)이면서 상어가 물고기를 잡아먹을 수 있는 크기인 경우
// 				{
// 					check[nx][ny] = check[cur.first][cur.second] + 1;
// 					fish.push_back({ nx, ny });
// 					Q.push({ nx, ny });
// 				}
// 			}
// 		}
// 		if (fish.size() == 0) // 더이상 잡아 먹을 물고기가 없는 경우 프로그램을 종료한다.
// 		{
// 			cout << second << '\n';
// 			return 0;
// 		}
// 		else if (fish.size() == 1)
// 		{
// 			x = fish[0].first;
// 			y = fish[0].second;
// 			board[x][y] = 0;
// 			eatfish++;
// 			second += check[x][y];
// 		}

// 		else
// 		{
// 			int mindist = 1e5; // 1e5 = 100000, 과학 기술 계산용으로 e를 소문자로 출력
// 			for (auto& x : fish) //auto& x의 변수가 하는 역할은 fish의 해당 객체를 참조한다는 뜻
// 				mindist = min(mindist, check[x.first][x.second]);

// 			int mincnt = 0;
// 			vector<pair<int, int>> minfish;
// 			for (auto& x : fish)
// 				if (mindist == check[x.first][x.second])
// 					minfish.push_back({ x.first, x.second });

			
// 			if (minfish.size() == 1)
// 			{
// 				x = minfish[0].first;
// 				y = minfish[0].second;
// 				board[x][y] = 0;
// 				second += check[x][y];
// 				eatfish++;
// 			}

// 			else
// 			{
// 				sort(minfish.begin(), minfish.end());
// 				x = minfish[0].first;
// 				y = minfish[0].second;
// 				second += check[x][y];
// 				board[x][y] = 0;
// 				eatfish++;
// 			}
// 		}
// 	}

// }