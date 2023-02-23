#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} node;

node *head = NULL;


node *create_node()
{
    node *new_node = malloc(sizeof(node));
    printf("Enter an number  ");
    scanf("%d", &new_node->number);
    new_node->next = NULL;
    return new_node;
}

void print_node(){
    node *iterator = head;

    if(iterator == NULL){
        printf("List is Empty");
        return;
    }

    while(iterator != NULL){
        printf("%d ", iterator->number);
        iterator = iterator->next;
    }
    printf("\n");
}

void count_node(){
    int count = 0;
    node *iterate = head;
    if(iterate == NULL){
        printf("Total length is %d\n", count);
        return;
    }
    while(iterate != NULL){
        count += 1;
        iterate = iterate->next;
    }
    printf("Total length is %d\n", count);
}


void insert_node(){
    node *new_node = create_node();
    node *iterator = head;
    if(iterator == NULL){
        head = new_node;
        return ;
    }

    while(iterator->next != NULL){
        iterator = iterator->next;
    }

    iterator->next = new_node;
    return ;
}


int main(){
    insert_node();
    insert_node();
    print_node();
    insert_node();
    insert_node();
    print_node();
    count_node();

    return 0;
}