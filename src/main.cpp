#include "../header/magic.hpp"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  auto res = true;
  auto test_bound=100; // better less than 1000
  for (auto i = 3; i < test_bound; i += 2) {
    res = res && magic_matrix(i).varify();
  }
  cout<<"All results of the odd-level magic matrices within level "<<test_bound<<" are ";
  cout << boolalpha << res << endl;
  magic_matrix().display();
  magic_matrix(5).display();
  magic_matrix(7,2).display();
  magic_matrix(9,9).display();
  return 0;
}
