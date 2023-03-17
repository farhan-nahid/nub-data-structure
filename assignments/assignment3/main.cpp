#include<iostream>

using namespace std;

struct Node {
    int elem;
    Node *next = NULL;
};



// Count the number of nodes in the list
int countNode(Node *root){
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

   return count;
}



// Print elements in the list
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



// returns the reference of the Node at the given index. For invalid index return None.
void nodeAt(Node *root, int idx){
    Node *temp = root;
    int i = 0;

    while(i < idx){
        if(temp == nullptr){
            cout << "None" << endl;
            return;
        }
        temp = temp->next;
        i+=1;
    }

    cout << temp->elem << endl;

}



// create node
Node *create_node(int elem){
    Node *new_node = new Node;
    new_node->elem = elem;
    new_node->next = NULL;
    return new_node;
}



// Print elements in the list
Node* makeList(int arr[]){

    Node *root = new Node;
    root->elem = arr[0];
    Node *temp = root;

    for(int i =1; i<5; i++){
        Node *newNode = new Node;
        newNode->elem = arr[i];

        temp->next = newNode;
        temp = newNode;

    }

    return root;
}



// updates the element of the Node at the given index.
// Returns the old element that was replaced. For invalid index return None.
// parameter{} index, element
void setNode(Node *root,int idx, int elem){
    Node *temp = root;
    int i = 0;

    while(i < idx){
        if(temp == nullptr){
            cout << "None" << endl;
            return;
        }
        temp = temp->next;
        i+=1;
    }

    cout << "old element " << temp->elem << endl;
    temp->elem = elem;  
    cout << "replaced element " << temp->elem << endl;  
}



// returns the index of the Node containing the given element.
// if the element does not exist in the List, return -1.
void indexOf(Node *root, int elem){
    Node *temp = root;
    int index = 0;
    bool isMatched = false;

    while(true){
        if(temp == nullptr){
            break;
        } else {
            if(temp->elem == elem){
                isMatched = true;
                break;
            }
            temp = temp->next;
            index +=1;
        }
    } 

    if(isMatched){
        cout << index << endl;
    } else{
        cout << -1 << endl;
    }
}



// returns true if the element exists in the List, return false otherwise.
void contains(Node *root, int elem){
    Node *temp = root;
    int index = 0;
    bool isMatched = false;

    while(true){
        if(temp == nullptr){
            break;
        } else {
            if(temp->elem == elem){
                isMatched = true;
                break;
            }
            temp = temp->next;
            index +=1;
        }
    } 

    if(isMatched){
        cout << "True" << endl;
    } else{
        cout << "False" << endl;
    }
}



// Makes a duplicate copy of the given List. Returns the reference of the duplicate list.
Node* copyList(Node* root) {
    Node* newRoot = nullptr;
    Node* tail = nullptr;
    while (root != nullptr) {
        Node* newNode = new Node();
        newNode->elem = root->elem;
        if (newRoot == nullptr) {
            newRoot = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        root = root->next;
    }
    return newRoot;
}



// Makes a reversed copy of the given List. Returns the head reference of the reversed list.
Node* reverseList(Node* root) {
    Node* reversedRoot = nullptr;
    while (root != nullptr) {
        Node* newNode = new Node();
        newNode->elem = root->elem;
        newNode->next = reversedRoot;
        reversedRoot = newNode;
        root = root->next;
    }
    return reversedRoot;
}



// inserts Node containing the given element at the given index
// Check validity of index.
void insertNode(Node *root, int elem, int idx){
    int listLength = countNode(root);

    if(listLength < idx){
        cout << "Invalid Position" << endl;
        return;
    }

    Node* new_node = create_node(elem);
  
    Node *temp = root, *next, *prev;
    int index = 1;
    while(index < idx){
        if(temp == nullptr){
            break;
        } else {
            next = temp->next->next;
            prev = temp;
            temp = temp->next;
            index +=1;
        }
    } 
    prev->next = new_node;
    new_node->next = next;
}



// removes Node at the given index. returns element of the removed node.
// Check validity of index. return None if index is invalid.
void removeNode(Node *root, int idx){
    int listLength = countNode(root);

    if(listLength < idx){
        cout << "None. Invalid Position" << endl;
        return;
    }
    Node *temp = root, *prev;
    int index = 1;
    while(index < idx){
        if(temp == nullptr){
            break;
        } else {
            prev = temp;
            temp = temp->next;
            index +=1;
        }
    } 

    prev->next = temp->next;
}



// shifts the list to the left by 1 position.
void shiftLeft(Node *root) {
    if (root == nullptr || root->next == nullptr) {
        return; // nothing to shift
    }
    Node* newRoot = root->next;
    Node* tail = root;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = root;
    root->next = nullptr;
    root = newRoot;
    cout << "After shift left ==========="  <<endl;
    printList(root);
}



// shifts the list to the right by 1 position.
void shiftRight(Node* root) {
    if (root == nullptr || root->next == nullptr) {
        return; // nothing to shift
    }
    Node* tail = root;
    while (tail->next->next != nullptr) {
        tail = tail->next;
    }
    Node* newRoot = tail->next;
    newRoot->next = root;
    tail->next = nullptr;
   
    root = newRoot;
}



int main(){
    int arr[5] = {3,5,6,8,9};

    Node *root  = makeList(arr);

    printList(root);
    int count = countNode(root);
    cout << "Total node number is " << count << endl;

    nodeAt(root, 9);
    setNode(root, 1, 1);
    indexOf(root, 6);
    indexOf(root, 90);
    contains(root, 6);
    insertNode(root, 90, 3);
    printList(root);
    removeNode(root, 3);
    printList(root);

    Node* copiedRoot = copyList(root);
    printList(copiedRoot);

    Node* reversedRoot = reverseList(root);
    printList(reversedRoot);

   
    cout << "Before shift right ==========="  <<endl;
    printList(root);
    shiftRight(root);
    cout << "After shift right ==========="  <<endl;
    printList(root);


    cout << "Before shift left ==========="  <<endl;
    printList(root);
    shiftLeft(root);

    return 0;
}
