#include "BinTree.hh"

bool poda_subarbre(BinTree<int> &a, int x) {
    if (not a.empty()) {
	if (a.value() != x) {
	    BinTree<int> l = a.left();
	    BinTree<int> r = a.right();
	    if (poda_subarbre(l, x) or poda_subarbre(r, x)) {
		a = BinTree<int> (a.value(), l, r);
		return true;
	    }
	}
	else {
	    a = BinTree<int>();
	    return true;
	}
    }
    return false;
}
