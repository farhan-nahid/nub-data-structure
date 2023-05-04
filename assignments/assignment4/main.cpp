#include<iostream>

using namespace std;

struct Node {
    int elem;
    Node *next = NULL;
    Node *prev = NULL;
};

// Count the number of nodes in the list
int countNode(Node *root){
    int count = 0;
    Node *current = root;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

// Print elements in the list
void printList(Node* root){
    Node *current = root;
    while(current != NULL){
        cout << current->elem << " ";
        current = current->next;
    }
    cout << endl;
}

// print the list in reverse order
void printReverse(Node* root){
    Node *current = root;
    while(current->next != NULL){
        current = current->next;
    }
    while(current != NULL){
        cout << current->elem << " ";
        current = current->prev;
    }
    cout << endl;
}

// returns the reference of the Node at the given index. For invalid index return None.
Node* nodeAt(Node *root, int idx){
    Node *current = root;
    int i = 0;
    while(current != NULL && i < idx){
        current = current->next;
        i++;
    }
    return current;
}

// create node
Node *create_node(int elem){
    Node *node = new Node;
    node->elem = elem;
    return node;
}

// create linked list from array
Node* makeList(int arr[]){
    Node *root = NULL;
    Node *prev = NULL;
    for(int i=0; i<5; i++){
        Node *node = create_node(arr[i]);
        if(root == NULL){
            root = node;
        } else {
            prev->next = node;
            node->prev = prev;
        }
        prev = node;
    }
    return root;
}

// updates the element of the Node at the given index.
// Returns the old element that was replaced. For invalid index return None.
// parameter{} index, element
int setNode(Node *root,int idx, int elem){
    Node *node = nodeAt(root, idx);
    if(node != NULL){
        int old_elem = node->elem;
        node->elem = elem;
        return old_elem;
    } else {
        return -1;
    }
}

// returns the index of the Node containing the given element.
// if the element does not exist in the List, return -1.
int indexOf(Node *root, int elem){
    Node *current = root;
    int idx = 0;
    while(current != NULL){
        if(current->elem == elem){
            return idx;
        }
        current = current->next;
        idx++;
    }
    return -1;
}

// returns true if the element exists in the List, return false otherwise.
bool contains(Node *root, int elem){
    return indexOf(root, elem) != -1;
}

// Makes a duplicate copy of the given List. Returns the reference of the duplicate list.
Node* copyList(Node* root) {
    Node *new_root = NULL;
    Node *prev = NULL;
    Node *current = root;
    while(current != NULL){
        Node *node = create_node(current->elem);
        if(new_root == NULL){
            new_root = node;
        } else {
            prev->next = node;
            node->prev = prev;
        }
        prev = node;
        current = current->next;
    }
    return new_root;
}

// Makes a reversed copy of the given List. Returns the head reference of the reversed list.
Node* reverseList(Node* root) {
    Node *current = root;
    Node *prev = NULL;
    Node *new_root = NULL;
    while (current != NULL) {
        Node *new_node = create_node(current->elem);
        if (new_root == NULL) {
            new_root = new_node;
        } else {
            new_node->next = new_root;
            new_root = new_node;
        }
        current = current->next;
    }
    return new_root;
}

// inserts Node containing the given element at the given index
// Check validity of index.
void insertNode(Node *root, int elem, int idx) {
    // Check validity of index
    int count = countNode(root);
    if (idx < 0 || idx > count) {
        return;
    }

    // Create a new node with the given element
    Node *newNode = create_node(elem);

    if (idx == 0) {
        // Inserting at the beginning of the list
        newNode->next = root;
        root->prev = newNode;
        root = newNode;
    } else {
        // Traverse the list until the node at the index is reached
        Node *currentNode = root;
        for (int i = 0; i < idx - 1; i++) {
            currentNode = currentNode->next;
        }

        // Insert the new node between the current node and its previous node
        newNode->prev = currentNode;
        newNode->next = currentNode->next;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    }
}

// removes Node at the given index. returns element of the removed node.
// Check validity of index. return None if index is invalid.
void removeNode(Node *root, int idx) {
    if (idx < 0) { // Check if the index is valid
        cout << "Invalid index." << endl;
        return;
    }

    if (idx == 0) { // Special case for removing the first node
        Node *temp = root;
        root = root->next;
        delete temp;
        return;
    }

    // Traverse the list to find the node at the given index
    Node *curr = root;
    Node *prev = NULL;
    int i = 0;
    while (curr != NULL && i < idx) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr == NULL) { // Check if the index is invalid
        cout << "Invalid index." << endl;
        return;
    }

    prev->next = curr->next; // Remove the node at the given index
    delete curr;
}

// shifts the list to the left by 1 position.
void shiftLeft(Node *root) {
    if (root == NULL || root->next == NULL) {
        // nothing to shift if list is empty or has only one element
        return;
    }

    // store the second node (new root)
    Node *newRoot = root->next;

    // update next and prev pointers of nodes
    root->next = newRoot->next;
    newRoot->prev = NULL;

    // check if second node exists
    if (newRoot->next != NULL) {
        newRoot->next->prev = root;
    }

    // attach new root at the end
    Node *lastNode = root;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newRoot;
    newRoot->prev = lastNode;
}

// shifts the list to the right by 1 position.
Node* shiftRight(Node* root) {
    if (root == NULL || root->next == NULL) {
        // list is empty or contains only one element, nothing to do
        return root;
    }

    // find the last node
    Node* last = root;
    while (last->next != NULL) {
        last = last->next;
    }

    // remove the last node
    last->prev->next = NULL;

    // insert the last node at the beginning
    last->prev = NULL;
    last->next = root;
    root->prev = last;

    // the new root is the last node
    return last;
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

   
    cout << "Before shift right ==========="  << endl;
    printList(root);
    shiftRight(root);
    cout << "After shift right ==========="  << endl;
    printList(root);


    cout << "Before shift left ==========="  << endl;
    printList(root);
    shiftLeft(root);

    return 0;
}
