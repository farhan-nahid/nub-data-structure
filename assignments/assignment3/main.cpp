#include<iostream>

using namespace std;

struct Node {
    int elem;
    Node *next = NULL;
};


void printList(Node* root){
    Node *temp = root;
    while(true){
        if(temp == nullptr){
            break;
        } else{
            cout<<temp->elem<<" ";
            temp = temp->next;
        }
    } 
    cout << endl;
}

// Count the number of nodes in the list
void countNode(Node *root){
    Node *temp = root;
    int count = 0;

    while(true){
        if(temp == nullptr){
            break;
        } else{
            count += 1;
            temp = temp->next;
        }
    } 

   cout << count << endl;
}

// Print elements in the list
Node* makeList(int arr[]){

    Node *root = new Node;
    root->elem = arr[0];
    Node *temp = root;

    for(int i =1;i<5;i++){
        Node *newNode = new Node;
        newNode->elem = arr[i];

        temp->next = newNode;
        temp = newNode;

    }

    return root;
}

// returns the reference of the Node at the given index. For invalid index return None.
void nodeAt(Node *root, int idx){}


int main(){
    int arr[5] = {3,5,6,8,9};

    Node *root  = makeList(arr);

    printList(root);
    countNode(root);

}
