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
    if ((right(i) <= heap_size) && (A[swap_id] < A[right(i)])) 
      swap_id = right(i);
    if (swap_id != i) { 
      swap(A[i], A[swap_id]);
      shift_down(swap_id); 
    }
  }

public:
  binary_heap() {
    A.push_back(T());
    heap_size = 0; 
  }

  ~binary_heap() {
    A.clear();
  }

  void push(T x) { 
    if (heap_size+1 >= (int)A.size()) 
      A.push_back(T());
    A[++heap_size] = x; 
    shift_up(heap_size); 
  }

  void pop() {
    if (empty()) return; 
    swap(A[1], A[heap_size--]);
    shift_down(1); 
  }

  T top() {
    return A[1]; 
  }

  bool empty() {
    return heap_size == 0;
  }

  int size() { 
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
    int indx = 1;
    string letters; cin >> letters;
    for (char c: letters){
        if (c == 'L') indx = indx * 2;
        if (c == 'R') indx = indx * 2 + 1;
    }
    cout << pq.findElem(indx);
    return 0;
}