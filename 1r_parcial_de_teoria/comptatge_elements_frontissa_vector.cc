#include <vector>
using namespace std;

int comptatge_frontisses(const vector<int> &v) {
    int counter = 0, left_counter = 0, right_counter = 0;
    for (int i = 0; i < v.size()-1; ++i) left_counter += v[i];
    for (int i = v.size()-1; i >= 0; --i) {
	if (right_counter - left_counter == v[i]) ++counter;
	right_counter += v[i];
	if (i != 0) left_counter -= v[i-1];
    }
    return counter;
}
