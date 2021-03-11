#include <queue>
#include <iostream>
using namespace std;

double calcular_mitja(int nota, int size) {
    double nota_mitja = double(nota)/size;
    return nota_mitja;
}

void escriu (int min, int max, double mitja) {
    cout << "min " << min << "; max " << max << "; media " << mitja << endl;
}

void recalcular_max_min(queue<int> q, int& min, int& max){
    min = 1001, max = -1002;
    while (not q.empty()) {
	if (q.front() > max) max = q.front();
	if (q.front() < min) min = q.front();
	q.pop();
    }
}

int main() {
    int valor_total=0, min=1001, max=-1002, n;
    queue<int> q;
    cin >> n;
    while (n >= -1001 and n <= 1000) {
	if (n != -1001) {
	    if (n > max) max = n;
	    if (n < min) min = n;
	    valor_total += n;
	    q.push(n);
	}
	else if (not q.empty()) {
	    valor_total -= q.front();
	    bool recalcular = (q.front() == max or q.front() == min);
	    q.pop();
	    if (recalcular) recalcular_max_min(q, min, max);
	}
	if (q.empty()) cout << 0 << endl;
	else escriu(min, max, calcular_mitja(valor_total, q.size()));
	cin >> n;
    }
}
