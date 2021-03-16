#include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos) {
    list<int>::iterator l1 = uno.begin();
    list<int>::const_iterator l2 = dos.begin();
    while (l1 != uno.end() and l2 != dos.end()) {
	if (*l1 < *l2) l1 = uno.erase(l1);
	else if (*l1 > *l2) ++l2;
	else if (*l1 == *l2) ++l1, ++l2;
    }
    while (l1 != uno.end()) l1 = uno.erase(l1);
}
