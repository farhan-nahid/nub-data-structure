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

   cout << "Total node number is " << count << endl;
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


int main(){
    int arr[5] = {3,5,6,8,9};

    Node *root  = makeList(arr);

    printList(root);
    countNode(root);

    nodeAt(root, 9);
    setNode(root, 1, 1);
    indexOf(root, 6);
    indexOf(root, 90);

    return 0;
}
