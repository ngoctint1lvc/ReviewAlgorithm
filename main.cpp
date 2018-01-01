#include <iostream>
#include "list.hpp"

using namespace std;
using namespace MyList;

int main(){
  Node* head = NULL;
  int arr[10] = {5, 7, 2, 9, 8, 19, 30, 10, 42, 56};
  head = buildListFromArr(arr, 10);
  printList(head);
  MyList::swap(head, 7, 42);
  printList(head);

  cout << "After sort by merge sort" << endl;
  int arr1[3] = {1, 5, 10};
  int arr2[4] = {2, 4, 6, 11};
  Node* head1 = buildListFromArr(arr1, 3);
  Node* head2 = buildListFromArr(arr2, 4);
  printList(head1);
  printList(head2);
  Node* headMerge = MyList::mergeTwoList(head1, head2);
  printList(head1);
  printList(head2);
  printList(headMerge);

  return 0;
}