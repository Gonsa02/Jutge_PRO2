#include "BinTree.hh"
#include <stack>
using namespace std;

int mida(const BinTree<int>& a) {
    if (a.empty()) return 0;
    return 1 + mida(a.left()) + mida(a.right());
}

void cami_preferent(const BinTree<int>& a, stack<int>& c) {
    if (not a.empty()) {
	int fills_dreta = mida(a.right());
	if (fills_dreta > 0 and fills_dreta > mida(a.left())) cami_preferent(a.right(), c);
	else cami_preferent(a.left(), c);
	c.push(a.value());
    }
}
