#include <iostream>
#include <stack>

using namespace std;

struct Position
{
	int x;
	int y;
};

int main()
{
	char Maze[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,1,1,1,1,0,0,0,1},
		{1,0,0,0,1,1,0,1,1,1},
		{1,1,1,0,0,0,0,1,1,1},
		{1,1,1,1,1,1,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,0,1,1,1},
		{1,0,1,1,1,1,0,0,1,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};

	
	//		초기 설정
	// 플레이어 위치
	Position PlayerPosition = { 1, 1 };
	// 스택 선언
	stack<Position> history;

	//				도착점이 아닐때, 반복
	while (!(PlayerPosition.x == 8 && PlayerPosition.y == 8))
	{
		//		현재 좌표
		history.push(PlayerPosition);
		//		현재 좌표 -> 3
		Maze[PlayerPosition.x][PlayerPosition.y] = 3;

		if (Maze[PlayerPosition.x + 1][PlayerPosition.y] == 0)
		{
			PlayerPosition.x++;
		}
		else if (Maze[PlayerPosition.x - 1][PlayerPosition.y] == 0)
		{
			PlayerPosition.x--;
		}
		else if (Maze[PlayerPosition.x][PlayerPosition.y + 1] == 0)
		{
			PlayerPosition.y++;
		}
		else if (Maze[PlayerPosition.x][PlayerPosition.y - 1] == 0)
		{
			PlayerPosition.y--;
		}
		else
		{
			if (history.empty())
			{
				cout << "No Exit" << endl;
				break;
			}

			PlayerPosition = history.top();
			history.pop();
		}
		// 지도 방문 위치 표시 

	}

	while (!history.empty())
	{
		Position Temp = history.top();
		cout << Temp.x << "," << Temp.y << endl;;
		history.pop();

	}

	return 0;
}