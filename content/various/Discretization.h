/**
 * Author: MingqiHuang
 * License: CC0
 * Description: Discretization for large data range.
 * Usage: call discretization() first, then call query() when you need. Return
 *   Value is a number that reference to the value in the array.
 * Time: O(n\log n + Q\log n)
 */
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int arr[maxn], n;
inline int* discretization() {
	sort(a, a + n);
	return unique(a, a + n);
}
inline int query(int *begin, int *end, int val) {
	return lower_bound(begin, end, val) - begin;
}
