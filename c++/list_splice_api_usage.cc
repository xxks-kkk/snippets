#include<iostream>
#include<list>

/* Demonstrate some typical usage of splice function of list (doubly-linked list)

   1) http://www.cplusplus.com/reference/list/list/splice/
   2) https://www.geeksforgeeks.org/list-splice-function-in-c-stl/

   For forward_list (single-linked list), to transfer elements from list to another used
   `splice_after(L1.end(), L2)`.
   
   Compile: clang++ -std=c++14 -stdlib=libc++ list_splice_api_usage.cc
 */
   
using namespace std; 

void usage1() {
    list<int> l1 = { 1, 2, 3 }; 
    list<int> l2 = { 4, 5 }; 
    list<int> l3 = { 6, 7, 8 }; 
  
    // transfer all the elements of l2 
    l1.splice(l1.begin(), l2); 
  
    // at the beginning of l1 
    cout << "list l1 after splice operation" << endl; 
    for (auto x : l1) 
        cout << x << " "; 
  
    // transfer all the elements of l1 
    l3.splice(l3.end(), l1); 
  
    // at the end of l3 
    cout << "\nlist l3 after splice operation" << endl; 
    for (auto x : l3) 
        cout << x << " ";  
}

void usage2() {
    list<int> l1 = { 1, 2, 3, 4, 5 }; 
    list<int> l2 = { 6, 7, 8 }; 
    list<int>::iterator it; 
  
    // iterator pointing to 1 
    it = l1.begin(); 
  
    // advance the iterator by 2 positions 
    advance(it, 2); 
  
    // transfer 3, 4 and 5 at the 
    // beginning of l2 
    l2.splice(l2.begin(), l1, it, l1.end()); 
  
    cout << "list l2 after splice operation" << endl; 
    for (auto x : l2) 
        cout << x << " ";   
}

int main() 
{
  usage1();
  usage2();
  return 0; 
} 
