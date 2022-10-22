#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Vertex { // we can use either C struct or C++/Python/Java class
    bool item; // the data is stored here, an integer in this example
    Vertex* next; // this pointer tells us where is the next vertex
};
class SLL {
private:
    Vertex* head;
    Vertex* tail; // show how to maintain tail pointer so that InsertAfterTail is 

public:
    SLL() {
        head = NULL;
        tail = NULL;
    }
    void InsertAtHead(bool v) {
        Vertex* vtx = new Vertex(); // create new vertex vtx from item v
        vtx->item = v;
        vtx->next = head; // link this new vertex to the (old) head vertex
        if (head == NULL) tail = vtx; // :O
        head = vtx; // the new vertex becomes the new head
    }
    void InsertAfterTail(bool v) {
        if (head == NULL)
            InsertAtHead(v);
        else {
            // The O(N) version (if we do not use tail pointer)
            // Vertex* ptr = head; // we have to start from head
            // while (ptr->next != NULL) // while not tail, O(N) - the slow part
            //   ptr = ptr->next; // the pointers are pointing to the higher index
            // // now ptr is tail
            // The O(1) version (just by simply maintaining tail pointer at all times)
            Vertex* vtx = new Vertex(); // create new vertex vtx from item v, O(1)
            vtx->item = v; // O(1)
            tail->next = vtx; // link tail to this new vertex, O(1)
            tail = vtx; // now update tail, O(1)
        }
    }
    bool GetHead() {
        if (head == NULL) return false; // avoid crashing when SLL is empty
        return head->item;
    }
    bool GetTail() {
        if (tail == NULL) return false; // avoid crashing when SLL is empty (if tail == NULL, then head must also be NULL)
        return tail->item;
    }
    void DeleteHead() {
        // https://visualgo.net/en/list?slide=3-15   
        if (head == NULL) return; // avoid crashing when SLL is empty
        Vertex* temp = head; // so we can delete it later
        head = head->next; // book keeping, update the head pointer
        delete temp; // which is the old head
        if (head == NULL) tail = NULL; // another corner case
    }
    void printDummy() {
        cout << "MyStack (or MyQueue) should not be able to use this or any other SLL operations that are not related to Stack / Queue operations\n";
    }
};

class MyStack : SLL { //inheritance
public:
    MyStack() { } // nothing
    void push(int v) { InsertAtHead(v); } // at head (causing the ordering to be LIFO - Last In First Out)
    void pop() { DeleteHead(); }
    bool top() { return GetHead(); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n; cin >> n;
    vector<bool> val(n, false);
    for (int i = 0; i < n; i++) {
        char TF; cin >> TF;
        val[i] = (TF == 'T');
    }

    MyStack s;
    char token;
    while (cin >> token) {          //need to press ctrl+z == signify end of input
        bool operand1, operand2;
        if (token == '-') {     //negation
            operand1 = s.top(); s.pop();
            s.push(!operand1);          //push back negation of s1
        }
        else if ((token == '*') || (token == '+')) {        //* == OR, + == AND
            operand2 = s.top(); s.pop();
            operand1 = s.top(); s.pop();
            if (token == '*') s.push(operand1 & operand2);
            else s.push(operand1 | operand2);
        }
        else {      //input is an alphabet
            s.push(val[token - 'A']);   //'A' is index 0, if token is A - 'A'==0; B-'A' == 1

        }
    }
    cout << (s.top() ? 'T' : 'F') << endl;          //if top is T print T; if top is F print F
    return 0;
}