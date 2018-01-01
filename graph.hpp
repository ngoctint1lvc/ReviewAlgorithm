#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

class Graph{
  int v;
  list<int>* adj;

public:
  Graph(int v);

  ~Graph();

  bool existEdge(int src, int des);

  void bfs(int begin);

  void dfs(int begin);

  void print();

  bool validNode(int node);

  void addEdge(int src, int des);

  void removeEdge(int src, int des);

  bool isCyclic();

  bool isCyclicUtil(int begin);
};

bool Graph::validNode(int node){
  return (node >= 0 && node < v);
}

bool Graph::existEdge(int src, int des){
  if(validNode(src) && validNode(des)){
    for(list<int>::iterator it = adj[src].begin(); it != adj[src].end(); it++){
      if(*it == des) return true;
    }
    return false;
  }
  return true;
}

Graph::Graph(int v){
  if(v <= 0){
    cout << "Error: v <= 0 => replace v = 1" << endl;
    v = 1;
  }

  this->v = v;
  adj = new list<int>[v];
}

Graph::~Graph(){
  delete[] adj;
  adj = NULL;
}

void Graph::addEdge(int src, int des){
  if(validNode(src) && validNode(des)){
    if(!existEdge(src, des)){
      adj[src].push_back(des);
    }
    else{
      cout << "This edge already exists" << endl;
    }
  }
  else{
    cout << "Error: src or des node is invalid" << endl;
  }
}

void Graph::removeEdge(int src, int des){
  if(validNode(src) && validNode(des)){
    if(existEdge(src, des)){
      adj[src].remove(des);
    }
  }
  else{
    cout << "Error: src or des node is invalid" << endl;
  }
}

void Graph::print(){
  for(int i = 0; i < v; i++){
    cout << i << ": ";
    for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++){
      cout << *it << " ";
    }
    cout << endl;
  }
}

void Graph::bfs(int begin){
  // Check begin node
  if(!validNode(begin)){
    cout << begin << " is invalid node" << endl;
    return;
  }

  // Create visit array
  bool* visit = new bool[v];
  for(int i = 0; i < v; i++){
    visit[i] = false;
  }

  // Breadth first traverse
  list<int> visitQueue;
  visitQueue.push_back(begin);
  visit[begin] = true;
  while(!visitQueue.empty()){
    int front = visitQueue.front();
    cout << front << " ";
    visitQueue.pop_front();

    for(list<int>::iterator it = adj[front].begin(); it != adj[front].end(); it++){
      if(visit[*it] == false){
        visit[*it] = true;
        visitQueue.push_back(*it);
      }
    }
  }
  cout << endl;

  // Delete visit array
  delete[] visit;
}

void Graph::dfs(int begin){
  // Check begin node
  if(!validNode(begin)){
    cout << begin << " is invalid node" << endl;
    return;
  }

  // Create visit array
  bool* visit = new bool[v];
  for(int i = 0; i < v; i++){
    visit[i] = false;
  }

  // Depth first traverse
  list<int> stack;
  stack.push_front(begin);

  while(!stack.empty()){
    int top = stack.front();
    stack.pop_front();

    if(visit[top] == false){
      cout << top << " ";
      visit[top] = true;
    }

    for(list<int>::iterator it = adj[top].begin(); it != adj[top].end(); it++){
      if(visit[*it] == false){
        stack.push_front(*it);
      }
    }
  }
  cout << endl;

  // Delete visit array
  delete[] visit;
}

bool Graph::isCyclic(){
  for(int i = 0; i < v; i++){
    if(isCyclicUtil(i)) return true;
  }
  return false;
}

bool Graph::isCyclicUtil(int begin){
  bool* visit = new bool[v];
  bool* recursiveStack = new bool[v];
  for(int i = 0; i < v; i++){
    visit[i] = false;
    recursiveStack[i] = false;
  }

  list<int> stack;
  stack.push_front(begin);
  recursiveStack[begin] = true;
  visit[begin] = true;
  while(!stack.empty()){
    int top = stack.front();
    bool addNewNode = false;
    for(list<int>::iterator i = adj[top].begin(); i != adj[top].end(); i++){
      if(visit[*i] == false){
        stack.push_front(*i);
        visit[*i] = true;
        recursiveStack[*i] = true;
        addNewNode = true;
        break;
      }
      else if(recursiveStack[*i] == true){
        delete[] visit;
        delete[] recursiveStack;

        //print stack
        cout << "This is the cycle" << endl;
        stack.reverse();
        for(list<int>::iterator it = stack.begin(); it != stack.end(); it++){
          cout << *it << " ";
        }
        cout << *i << endl;
        return true;
      }
    }

    if(addNewNode == false){
      recursiveStack[top] = false;
      stack.pop_front();
    }
  }

  delete[] visit;
  delete[] recursiveStack;
  return false;
}

void testGraph(){
  cout << "Enter v = ";
  int v;
  cin >> v;
  Graph myGraph(v);

  string command;
  while(true){
    try{
      cout << "command> ";
      cin >> command;

      if(command == "exit"){
        break;
      }
      else if(command == "add"){
        int src, des;
        cin >> src >> des;
        myGraph.addEdge(src, des);
      }
      else if(command == "remove"){
        int src, des;
        cin >> src >> des;
        myGraph.removeEdge(src, des);
      }
      else if(command == "print"){
        myGraph.print();
      }
      else if(command == "bfs"){
        int begin;
        cin >> begin;
        myGraph.bfs(begin);
      }
      else if(command == "dfs"){
        int begin;
        cin >> begin;
        myGraph.dfs(begin);
      }
      else if(command == "cyclic"){
        int begin;
        cin >> begin;
        cout << boolalpha << myGraph.isCyclicUtil(begin) << endl;
      }
      else{
        cout << "Error: Command '" << command << "' not found" << endl;
      }
    }
    catch(runtime_error &error){
      cout << error.what() << endl;
    }
    catch(...){
      cout << "some error ocurred" << endl;
    }
  }
}

#endif
