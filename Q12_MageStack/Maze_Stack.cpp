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

	
	//		�ʱ� ����
	// �÷��̾� ��ġ
	Position PlayerPosition = { 1, 1 };
	// ���� ����
	stack<Position> history;

	//				�������� �ƴҶ�, �ݺ�
	while (!(PlayerPosition.x == 8 && PlayerPosition.y == 8))
	{
		//		���� ��ǥ
		history.push(PlayerPosition);
		//		���� ��ǥ -> 3
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
		// ���� �湮 ��ġ ǥ�� 

	}

	while (!history.empty())
	{
		Position Temp = history.top();
		cout << Temp.x << "," << Temp.y << endl;;
		history.pop();

	}

	return 0;
}