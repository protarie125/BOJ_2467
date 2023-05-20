#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <ranges>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vl dat;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	dat = vl(n);
	for (const auto& i : ranges::iota_view{ 0, n }) {
		cin >> dat[i];
	}

	auto le = dat.begin();
	auto ri = dat.end();
	--ri;

	auto al = *le;
	auto ar = *ri;
	auto ans = al + ar;
	while (le < ri) {
		const auto& now = *le + *ri;
		if (abs(now) < abs(ans)) {
			al = *le;
			ar = *ri;
			ans = now;
		}

		if (0 < now) {
			--ri;
		}
		else {
			++le;
		}
	}

	cout << al << ' ' << ar;

	return 0;
}