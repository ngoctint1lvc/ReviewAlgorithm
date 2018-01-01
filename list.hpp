#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

using namespace std;

namespace MyList{
    struct Node{
        int data;
        Node* next;
        Node(int value){
            data = value;
            next = NULL;
        }
    };

    void insertLast(Node*& head, int value){
        if(head == NULL){
            head = new Node(value);
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Node(value);
    }

    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* buildListFromArr(int* arr, int size){
        try{
            Node* head = NULL;
            for(int i = 0; i < size; i++){
                insertLast(head, arr[i]);
            }
            return head;
        }
        catch(...){
            cout << "Some error occured when trying to convert arr to list" << endl;
        }
    }

    void swap(Node*& head, int x, int y){
        if(x == y) return;

        Node *prevX = NULL, *prevY = NULL;
        Node *curX, *curY;

        // Search for x y
        for(curX = head; curX && curX->data != x; curX = curX->next){
            prevX = curX;
        }
        for(curY = head; curY && curY->data != y; curY = curY->next){
            prevY = curY;
        }

        // Can not find x or y
        if(curX == NULL || curY == NULL){
            return;
        }

        // swap x and y
        if(prevX){
            prevX->next = curY;
        }
        else{
            head = curY;
        }

        if(prevY){
            prevY->next = curX;
        }
        else{
            head = curX;
        }

        Node* temp = curX->next;
        curX->next = curY->next;
        curY->next = temp;
    }

    void moveOneNode(Node*& dest, Node*& source){
        Node* temp = new Node(source->data);
        dest = temp;
    }

    void mergeSort(Node*& head){
        
    }

    Node* mergeTwoList(Node* head1, Node* head2){
        Node* result = NULL;
        Node** lastRef = &result;

        while(true){
            if(head1 == NULL){
                *lastRef = head2;
                break;
            }
            else if(head2 == NULL){
                *lastRef = head1;
                break;
            }

            if(head1->data <= head2->data){
                moveOneNode(*lastRef, head1);
            }
            else{
                moveOneNode(*lastRef, head2);
            }

            lastRef = &((*lastRef)->next);
        }

        return result;
    }
}

#endif