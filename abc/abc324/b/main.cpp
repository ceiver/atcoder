#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    while (!(N % 2)) N /= 2;
    while (!(N % 3)) N /= 3;
    if(N == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
