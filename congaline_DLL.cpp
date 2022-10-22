#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
struct Vertex {
    string item;
    Vertex* prev;
    Vertex* next;
    Vertex* partner;
};

class DLL {
    private:
    Vertex* head;
    Vertex* tail;
    Vertex* mic;
    public:
    DLL() {
        head = NULL;
        tail = NULL;
        mic = head;
    }
    void InsertAtHead(string v) {
        Vertex* vtx = new Vertex();
        vtx->item = v;
        vtx->next = head;
        vtx->prev = NULL;
        if (head == NULL) tail = vtx;
        else head->prev = vtx;
        head = vtx;
        mic = vtx;
    }
    void InsertAfterTail1(string v) {
        if (head == NULL)
            InsertAtHead(v);
        else {
            Vertex* vtx = new Vertex();
            vtx->item = v;
            vtx->next = NULL;
            vtx->prev = tail;
            tail->next = vtx; 
            tail = vtx;
        }
    }
    void InsertAfterTail2(string v){        //initialise partner to partner*
        if (head == NULL){
            InsertAtHead(v);
        }
        else{
            Vertex* vtx = new Vertex();
            vtx->item = v;
            vtx->next = NULL;
            vtx->prev = tail;
            vtx->partner = vtx->prev;
            vtx->prev->partner = vtx;
            tail->next = vtx;
            tail = vtx;
        }
    }
    void printList() {
        Vertex* temp = head;
        while (temp != NULL) {
            cout << temp->item << endl;
            temp = temp->next;
        }
    }
    void fInst(){       //point mic to prev
        mic = mic->prev;
    }
    void bInst(){       //point mic to next
        mic = mic->next;
    }
    void pInst(){       //cout mic partner position
        if (mic == NULL) return;
        cout << mic->partner->item << endl;
    }
    void rInst(){       //bInst + del + insert at back; if mic is tail, mic pass to head
        Vertex* temp = mic;
        if (mic->next == NULL){  //if mic is last, mic pass to head, person stay behind
            mic = head;
        }
        else if (mic->prev == NULL){      //if mic is head, mic pass back, person requeue
            Vertex* aftMic = mic->next;
            aftMic->prev = NULL;
            mic = mic->next;
            head = head->next;
            temp->next = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }   
        else{       //if mic is middle, mic pass back, person requeue
            Vertex* aftMic = mic->next;    //value after mic
            Vertex* befMic= mic->prev;    //value before mic
            aftMic->prev = befMic;
            befMic->next = aftMic;
            mic = mic->next;
            tail->next = temp;
            temp->prev = tail;
            temp->next = NULL;
            tail = temp;
        }
    }
    void cInst(){       //bInst + del + insert behind partner; if mic is tail, mic pass to head
        Vertex* temp = mic;
        if (mic->next == NULL){     //if mic at tail, mic pass to head, person behind partner
            Vertex* aftPartner = mic->partner->next;        //value after partner
            Vertex* part = mic->partner;
            Vertex* befMic = mic->prev;    //value before mic to cut off link
            mic = head;
            if (aftPartner == temp) return;   //if already behind partner (means at tail already)
            befMic->next = NULL;
            tail = befMic;
            //reestablish link between partner+mic and mic+afterpartner
            temp->prev = part;
            temp->next = part->next;
            part->next = temp;
            if (temp->next == NULL){
                tail = temp;
            }
            else temp->next->prev = temp;
        }
        else if (mic->prev == NULL){    //if mic at head, mic pass back, person behind partner
            Vertex* aftPartner = mic->partner->next;
            Vertex* part = mic->partner;
            mic = mic->next;
            if (aftPartner == temp) return;
            head = head->next;   
            temp->next->prev = NULL;
            if (part->next== NULL){        //if partner is at tail
                part->next = temp;
                temp->prev = part;
                temp->next = NULL;
                tail = temp;
            }
            else{
                temp->next = part->next;
                part->next = temp;
                temp->prev = part;
                temp->next->prev = temp;
            }
        }
        else {      //if mic is middle, mic pass back, person behind partner
            Vertex* aftPartner = mic->partner->next;    //value after partner
            Vertex* befMic = mic->prev;    //value before mic
            Vertex* aftMic = mic->next;
            Vertex* part = temp->partner;
            mic = mic->next;
            if (aftPartner == temp) return;
            befMic->next = aftMic;
            aftMic->prev = befMic;
            if (part->next == NULL){    //if partner is tail
                temp->prev = part;
                part->next = temp;
                temp->next = NULL;
                tail = temp;
            }
            else{   //if partner is not at tail
                temp->next = part->next;
                part->next = temp;
                temp->prev = part;
                temp->next->prev = temp;
            }
            
        }
    }
};

int main(){
    fast_cin();
    DLL line;
    int N, Q; cin >> N >> Q; //N number of couples, Q number of instructions
    for (int i=0; i<N; i++){
        string c1, c2; cin >> c1 >> c2;
        line.InsertAfterTail1(c1);
        line.InsertAfterTail2(c2);
    }
    string instr; cin >> instr;
    
    for (char c: instr){
        if (c == 'F') line.fInst();
        else if (c == 'B') line.bInst();
        else if (c == 'P') line.pInst();
        else if (c == 'R') line.rInst();
        else if (c == 'C') line.cInst();
    }
    cout << endl;
    line.printList();
    return 0;
}