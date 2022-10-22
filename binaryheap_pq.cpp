#include <iostream>

void checkSize(int expected) {
    int got = getSize();
    if (got != expected) {
        std::cout << "Got size " << got << ", expected " << expected << std::endl;
    }
}

void checkMax(int expected) {
    int got = getMax();
    if (got != expected) {
        std::cout << "Got max " << got << ", expected " << expected << std::endl;
    }
}

int getMax(){
    return -1;
}

int getSize(){
    return -1;
}

void insert(int element){
}

void removeMax(){
}

int main() {
    checkSize(0);
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    checkMax(5);
    removeMax();
    removeMax();
    checkSize(3);
    checkMax(3);
}