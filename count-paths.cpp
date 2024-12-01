#include <iostream>
using namespace std;

long long count_paths(int sp, int ep)
{
    if (sp > ep)
        return 0;

    if (sp == ep)
        return 1;

    return count_paths(sp + 1, ep) + count_paths(sp + 2, ep) + count_paths(sp + 3, ep) + count_paths(sp + 4, ep) + count_paths(sp + 5, ep) + count_paths(sp + 6, ep);
}

int main()
{
    int sp, ep;
    cout << "Enter Starting Point & Ending Point : ";
    cin >> sp >> ep;
    cout << "The total numbers of ways to reach to the End Point are " << count_paths(sp, ep) << ".";
}