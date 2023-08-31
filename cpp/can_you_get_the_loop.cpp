#include<iostream>

struct Node{
  // member variable
  Node* next;
  std::string name;

  // constructor
  Node(std::string name_in) : name(name_in), next(nullptr){}

  // member functions
  void  setNext(Node* newNode){next = newNode;}
  Node* getNext() const {return next;}
};

// find a node in the loop
auto findLoop(Node* entry){
  auto slow = entry;
  auto fast = slow->getNext();

  while(slow != fast){
    slow = slow->getNext();
    fast = fast->getNext()->getNext();
  }

  return fast;
}

int getLoopSize(Node* startNode){
  auto loop_start = findLoop(startNode);

  auto slow = loop_start;
  auto fast = slow->getNext();

  int size = 1;

  while(slow != fast){
    size += 1;
    slow = slow->getNext();
    fast = fast->getNext()->getNext();
  }
  return size;
}

int main(){
  Node nA("A"), nB("B"), nC("C"), n1("1"), n2("2"), n3("3"), n4("4"), n5("5"), n6("6"),
       n7("7"), n8("8"), n9("9"), n10("10"), n11("11"), n12("12");

  nA.setNext(&nB);
  nB.setNext(&nC);
  nC.setNext(&n1);
  n1.setNext(&n2);
  n2.setNext(&n3);
  n3.setNext(&n4);
  n4.setNext(&n5);
  n5.setNext(&n6);
  n6.setNext(&n7);
  n7.setNext(&n8);
  n8.setNext(&n9);
  n9.setNext(&n10);
  n10.setNext(&n11);
  n11.setNext(&n12);
  n12.setNext(&n1);

  auto loop_size = getLoopSize(&n1);
  std::cout << loop_size << std::endl;
}