#include <iostream>
using namespace std;
void move(int n, char x, char y)
{
	cout << "把" << n << "号从" << x << "挪动到" << y << endl;
}
void Hannoi(int n, char A, char B, char C)
{
	if (n == 1)
		move(1, A, C);
	else
	{
		Hannoi(n - 1, A, C, B);
		move(n, A, C);
		Hannoi(n - 1, B, A, C);
	}
}
int main()
{
	int n;
	cout << "输入盘子的个数：" << endl;
	cin >> n;
	Hannoi(n, 'A', 'B', 'C');
	return 0;
}


