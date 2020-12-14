#include <iostream>

using namespace std;
class UnionFind{
  int size;               //size of elements in UnionFind
  int *sz;                //track size of each of components
  int *id;                //id[i] points to the parent of i , if id[i] = i, then i ia a root node

  int numComponents;      //track # of components in UnionFind
  public:
  UnionFind(int size){
    this->size = numComponents = size;
    sz = new int[size];
    id = new int[size];

    for(int i=0; i < size; i++){
      id[i] = i;          // link to self (self root)
      sz[i] = i;          // Each element is originally of same size
    }
  }

  // Find which component/set 'p' belongs to , takes amortized constant time
  int find(int p){
    //find the root of the component/set

    int root = p;
    while( root != id[root]){
      root = id[root];
    }

    //Compress the path leading back to the root
    //Doing this operation is called path compression
    //and is what gives us amortized constant time complexity

    while(p != root){
      int next = id[p];
      id[p] = root;
      p = next;
    }
  
    return root;
  }

  //Return whether or not the elements 'p' and 
  // 'g' are in the same components/set.

  bool connected(int p, int q){
    return find(p) == find(q);
  }

  //Return the size of the components/set 'p' belongs to
  int componentSize(int p){
    return sz[find(p)];
  }

  // Return the # of elements in this UnionFind/Disjoint set

  int Size(){
    return size;
  }

  //Return the # of remaining components/set
  int components(){
    return numComponents;
  }

  // Unify the components/sets containing elements 'p' and 'q'
  void unify(int p, int q){
    int root1 = find(p);
    int root2 = find(q);

    // These elements are already in the same group
    if(root1 == root2)  return;

    //Merge two components/sets together
    //Merge smaller components/sets into the larger one

    if(sz[root1] < sz[root2]){
      sz[root2] += sz[root1];
      id[root1] = root2;
    }

    else{
      sz[root1] += sz[root2];
      id[root2] = root1;
    }

    //Since the roots found are d/f we know that the
    // # components/sets has decreased by one
    numComponents--;
  }
  void print(){
    cout<<numComponents<<" "<<endl;
    for(int i=0; i<size; i++){
      cout<<id[i]<<" ";
    }
  }
};

int main() {

  UnionFind U(10);

  U.unify(2,5);
 U.unify(1,5);
 U.unify(1,3);
 U.unify(2,6);
 U.unify(3,4);
 U.unify(1,2);
 U.unify(8,7);
 U.print();
}
