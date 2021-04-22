#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> cap, totes;
    string nom;
    
    while (cin >> nom and nom != ".") cap.insert(nom);

    int n;
    cin >> n;

    cin >> nom;
    while (nom != ".") {
      cap.erase(nom);
      totes.insert(nom);
      cin >> nom;
    }

    for (int i = 1; i < n; ++i) {
      set<string>::iterator it = totes.begin();

      cin >> nom;
      while (it != totes.end() and nom != ".") {
        cap.erase(nom);

        if (*it < nom) it = totes.erase(it);
        else if (*it > nom) cin >> nom;
        else  {
          ++it;
          cin >> nom;
        }
      }
      
      while (it != totes.end()) it = totes.erase(it);

      while (nom !=".") {
        cap.erase(nom);
        cin >> nom;
      }
    }
    
    cout << "Totes les activitats:";
    for (set<string>::const_iterator it = totes.begin(); it != totes.end(); ++it) cout << " " << *it;
    cout << endl;
    cout << "Cap activitat:";
    for (set<string>::const_iterator it = cap.begin(); it != cap.end(); ++it) cout << " " << *it;
    cout << endl;
}
