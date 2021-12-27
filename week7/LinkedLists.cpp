#include <iostream>
using namespace std;
//Linked lists are a class of data structures that are used as builing blocks in many applications
//Dynamic structures that grow and shrink

//a linked list is an arbitrarily long sequence of nodes
    //contains key (data field) and pointer field
    //head pointer points to the first node in the list

class listNode{

    public:
        int key;
        listNode *next;
};

class linkedList{

    public:
        listNode * head;
        void traverseList();
        listNode* LocateInList(int k);
        void insertAtHead(listNode* nptr);
        void insertAtTail(listNode* nptr);
        void insertInMiddle(int k, listNode *ptr);
        void deleteNode(int k);

};

//traversing a list
    //visit each node once, processing its data (print key)

void linkedList :: traverseList(){

    listNode *tptr = head;
    while (tptr != NULL){

        cout << tptr -> key << endl;
        tptr = tptr -> next;
    }
}
//what happpens when the list is empty? -> head pointer is null

//Locating a node

listNode * linkedList :: LocateInList(int k){

    listNode * tptr = head;
    while (tptr != nullptr){
        if (tptr -> key == k){
            break;
        }
        tptr = tptr -> next;
    }
    return tptr;
}

//Insert at head

void linkedList :: insertAtHead(listNode* nptr){ //nptr is the pointer to the node you are trying to insert

    nptr -> next = head;
    head = nptr;
}

//Insert at tail

void linkedList :: insertAtTail(listNode *nptr){

    if (head == nullptr){ //in case list is empty

        head = nptr;
        nptr -> next = nullptr;
    }
    else{

        listNode* tptr = head;
        while (tptr -> next != nullptr){
            tptr = tptr -> next;
        }
        tptr -> next = nptr;
        nptr ->next = nullptr;
    }
}

//Insert at middle

void linkedList :: insertInMiddle(int k, listNode *nptr){

    listNode *tptr = head;
    while (tptr != nullptr){

        if (tptr -> key == k){

            break;
        }
        tptr = tptr ->next;
    }
    nptr -> next = tptr -> next;
    tptr -> next = nptr;

}


//Delete a node
    //have one pointer trail another pointer 

void linkedList :: deleteNode(int k){

    if (head == nullptr){ //empty list

        return;
    }

    listNode *tptr = head;
    listNode *pptr = nullptr;

    while (tptr != nullptr){

        if (tptr -> key == k){

            break;
        }

        pptr = tptr;
        tptr = tptr -> next;
    }
    
    if (tptr == nullptr){ //if key is not found ...

        return;
    }

    if (tptr == head){ //head node deleted (since we haven't assigned pptr yet)

        head = head -> next;
        delete tptr;
        return;
    }

    pptr -> next = tptr ->next;
    delete tptr;

}
 


