#include <iostream>
using namespace std;

// Binary Heap = Priority Queue
// Min Heap = Children Larger than parent
// Max Heap = Children Smaller than parent
// Left child = 2 * i
// Right child = 2 * i + 1
// Parent = 2 // i

class Heap {
  int *heap;
  int bum;
  void bubble_up(int i) {
    int parent = i / 2;
    while (heap[parent] > heap[i]) {
      swap(parent, i);
      i = parent;
      parent = i / 2;
      if (!parent) {
        break;
      }
    }
  }
  void bubble_down() {
    int i = 1;
    // while () {
      
    // }
  }
  void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
  }

public:
  Heap() {
    heap = new int[100];
    bum = 1;
  }
  int pop() { 
     int temp = heap[1];
     bum--;
     swap(bum,1);
     bubble_down();
     return 0; 
  }
  void push(int x) {
    heap[bum] = x;
    bubble_up(bum);
    bum++;
  }
  void print() {
    for (int i = 1; i < bum; i++) {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  std::cout << "Hello World!\n";
  Heap heap;

  for (int i = 0; i < 10; i++) {
    heap.push(rand() % 100 + 1);
  }
  heap.push(13);
  heap.push(11);
  heap.push(7);
  heap.push(3);
  heap.print();
}