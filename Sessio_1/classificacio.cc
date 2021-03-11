#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
  int team_num;
  int points;
  int gols;
  int reb_gols;
};

bool compare(const Team& a, const Team& b) {
  if (a.points != b.points) return a.points > b.points;
  else if ((a.gols-a.reb_gols) != (b.gols-b.reb_gols)) return (a.gols-a.reb_gols) > (b.gols-b.reb_gols);
  else return a.team_num < b.team_num;
}

int main() {

  int n;
  cin >> n;
  vector<Team> v(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pair<int,int> p;
      cin >> p.first >> p.second;
      if (i == 0) v[j].team_num = j+1;
      if (i != j and j == v[j].team_num-1) {
	v[j].gols += p.second;
	v[j].reb_gols += p.first;
	if (p.second > p.first) v[j].points += 3;
	else if (p.first == p.second) v[j].points += 1;
      }
      if (i != j and i == v[i].team_num-1) {
	v[i].gols += p.first;
	v[i].reb_gols += p.second;
	if (p.first > p.second) v[i].points += 3;
	else if (p.first == p.second) v[i].points += 1;
      }
    }
  }
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < n; ++i) cout << v[i].team_num << ' ' << v[i].points << ' ' << v[i].gols << ' ' << v[i].reb_gols << endl;
}
