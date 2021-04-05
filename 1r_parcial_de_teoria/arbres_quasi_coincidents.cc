#include "BinTree.hh"
using namespace std;

bool compara(const BinTree<int> &a, const BinTree<int> &b, int &f) {
    if (a.empty() and b.empty()) return true;
    if ((a.empty() and not b.empty()) or (b.empty() and not a.empty())) {
	if (f >= 1) return false;
	else {
	    ++f;
	    if (not a.empty() and a.right().empty() and a.left().empty()) return true;
	    if (not b.empty() and b.right().empty() and b.left().empty()) return true;
	    return false;
	}
    }
    else return (compara(a.left(), b.left(), f)) and (compara(a.right(), b.right(), f));
}

bool quasi_coincidents(const BinTree<int> &a, const BinTree<int> &b) {
    int counter = 0;
    return compara(a, b, counter);
}
