#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;

int main() {
	fastio;

	int m;
	cin >> m;

	int bits = 0, x;
	for (int i = 0; i < m; ++i) {
		string command;
		cin >> command;

		if (command == "add") {
			cin >> x;
			bits |= 1 << x;
		} else if (command == "remove") {
			cin >> x;
			bits &= ~(1 << x);
		} else if (command == "check") {
			cin >> x;
			cout << ((bits & (1 << x)) != 0) << '\n';
		} else if (command == "toggle") {
			cin >> x;
			bits ^= 1 << x;
		} else if (command == "all") {
			bits = (1 << 21) - 1;
		} else if (command == "empty") {
			bits = 0;
		}
	}
}
