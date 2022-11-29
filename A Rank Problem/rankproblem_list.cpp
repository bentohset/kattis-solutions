#include <iostream>
using namespace std;
template<class T>
class ListArray {
private:
  int N;
  T A[100];
public:
  ListArray() : N(0) {}
  T get(int i) {
    return A[i];
  }
  int search(T v) {
    for (int i = 0; i < N; ++i)
      if (A[i] == v)
        return i;
    return -1;
  }
  void insert(int i, T v) {
    if ((N == 100) || (i < 0) || (i > N)) return; 
    for (int j = N-1; j >= i; j--)
      A[j+1] = A[j];
    A[i] = v;
    ++N;
  }
  void remove(int i) {
    for (int j = i; j < N-1; ++j) 
      A[j] = A[j+1];
    --N;
  }
  void printList() {
    for (int i = 0; i < N; ++i)
      cout << (i ? " T" : "T") << A[i];
    cout << '\n';
  }
};
int main() {
  int n, m; cin >> n >> m;
  ListArray<int> ranking;
  for (int i = 0; i < n; ++i){
    ranking.insert(i, i+1); // 1, 2, 3, ..., N
  }
  while (m--) { // repeat m times, one for each of the m matches
    char dummy1, dummy2; int i, j; cin >> dummy1 >> i >> dummy2 >> j; // team i beats team j
    int idx_i = ranking.search(i); // we will get the index of value i at the moment
    int idx_j = ranking.search(j);
    if (idx_i > idx_j) { // the order is wrong, we need to re-rank
      ranking.remove(idx_j); // erase Tj first
      ranking.insert(idx_i, j); // insert j at previous idx_i
    }
  }
  ranking.printList();
  return 0;
}

//erase Tj and put behind Ti