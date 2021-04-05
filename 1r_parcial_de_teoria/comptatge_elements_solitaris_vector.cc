#include <vector>
using namespace std;

/* Pre: v.size() > 0 */
/* Post: el resultat es el nombre de solitaris a v */
int solitaris(const vector<int> &v) {
    int c = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0) {
            if (v[i] != v[i+1]) ++c;
        } else if (i == v.size()-1) {
            if (v[i-1] != v[i]) ++c;
        } else {
            if (v[i] != v[i+1] and v[i-1] != v[i]) ++c;
        }
    }
    return c;
}
