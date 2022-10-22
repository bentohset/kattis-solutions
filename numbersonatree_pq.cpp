#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
template <typename T>
class binary_heap {
private:
  vector<T> A;
  int heap_size;

  int parent(int i) { return i>>1; }
  int left(int i) { return i<<1; }
  int right(int i) { return (i<<1)+1; }

  void shift_up(int i) { 
    if (i == 1) return;
    if (A[i] > A[parent(i)]) { 
      swap(A[i], A[parent(i)]); 
      shift_up(parent(i));
    }
  }

  void shift_down(int i) {
    if (i > heap_size) return; 
    int swap_id = i;
    if ((left(i) <= heap_size) && (A[i] < A[left(i)])) 
      swap_id = left(i);
    if ((right(i) <= heap_size) && (A[swap_id] < A[right(i)])) // compare with right child, if exists
      swap_id = right(i);
    if (swap_id != i) { // need to swap with the larger of the two children
      swap(A[i], A[swap_id]); // swap downwards with the larger of the two children
      shift_down(swap_id); // recurse, at most O(log n) steps to one of the bottom-most leaf
    }
  }

public:
  binary_heap() { // O(1)
    A.push_back(T()); // remember to set index 0 to be 'dummy'
    heap_size = 0; // an empty Binary Heap
  }

  ~binary_heap() { // O(n)
    A.clear();
  }

  void push(T x) { // O(log n)
    if (heap_size+1 >= (int)A.size()) // O(1)
      A.push_back(T()); // enlarge the vector by one (internally, vector doubles its size) if needed, to avoid potential RTE below, O(1)
    A[++heap_size] = x; // the only possible insertion point, O(1)
    shift_up(heap_size); // shift upwards, O(log n) at worst
  }

  void pop() { // O(log n)
    if (empty()) return; // safeguard
    swap(A[1], A[heap_size--]); // swap with the last existing leaf, O(1)
    shift_down(1); // fix heap property downwards, O(log n) at worst
  }

  T top() { // O(1)
    return A[1]; // this is the root
  }

  bool empty() { // O(1)
    return heap_size == 0; // the condition for an empty A
  }

  int size() { // O(1)
    //assert(heap_size <= (int)A.size()); // should be true at all times
    return heap_size;
  }
  void findVerticesbiggerthan(T v, int x){
    if (v.value > x){
      cout << v.value << endl;
      findVerticesbiggerthan(v.left, x);
      findVerticesbiggerthan(v.right, x);
    } 
  }
  T findElem(T i){
    return A[i];
  }
  void printHeap(){
    while(!empty()){
        cout << top() << endl;
        pop();
    }
  }
};

int main(){
    fast_cin();
    int H; cin >> H;
    binary_heap<int> pq;
    int elem = pow(2, H+1)-1;
    //cout << elem;
    for (int i = elem; i > 0; i--){
        pq.push(i);
    }
    /* while (!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    } */
    //pq.printHeap();
    int indx = 1;
    string letters; cin >> letters;
    for (char c: letters){
        if (c == 'L') indx = indx * 2;
        if (c == 'R') indx = indx * 2 + 1;
    }
    cout << pq.findElem(indx);
    return 0;
}