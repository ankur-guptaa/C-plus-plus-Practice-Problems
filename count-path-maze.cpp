#include <iostream>
using namespace std;

long long count_path_maze(int n, int m, int i = 1, int j = 1)
{
    if (i > n || j > m)
        return 0;

    if (i == n && j == m)
        return 1;

    return count_path_maze(n, m, i + 1, j) + count_path_maze(n, m, i, j + 1);
}

int main()
{
    int n, m;
    cout << "Enter number of rows and column is maze : ";
    cin >> n >> m;
    cout << "The total number of ways to reach to the end of the maze are " << count_path_maze(n, m) << ".";
}