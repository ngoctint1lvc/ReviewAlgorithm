#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Node{
    int data;

    Node* left = NULL;
    Node* right = NULL;

    Node(int data){
        this->data = data;
    }
};

void insertBST(Node*& root, int value){
    if(root == NULL){
        root = new Node(value);
        return;
    }

    if(value > root->data){
        insertBST(root->right, value);
    }
    else{
        insertBST(root->left, value);
    }
}

void removeBST(Node*& root, int value){
    if(root == NULL){
        
    }
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void printBinary(Node* root, int depth = 0){
    if(root == NULL){
        for(int i = 0; i < depth; i++){
            cout << " ";
        }
        cout << "null" << endl;
        return;
    }

    for(int i = 0; i < depth; i++){
        cout << " ";
    }
    cout << root->data << endl;

    printBinary(root->left, depth + 4);
    printBinary(root->right, depth + 4);
}

void testBSTree(){
    try{
        Node* root = NULL;
        string command;
        while(true){
            cout << "Command> ";
            cin >> command;
            
            if(command == "insert"){
                int value;
                cin >> value;
                insertBST(root, value);
            }
            else if(command == "printBinary"){
                printBinary(root, 0);
            }
            else if(command == "preOrder"){
                preOrder(root);
            }
            else if(command == "exit"){
                break;
            }
            else{
                cout << command << ": command not found" << endl;
            }
        }
    }
    catch(...){
        cout << "Some error occured" << endl;
    }
}

#endif