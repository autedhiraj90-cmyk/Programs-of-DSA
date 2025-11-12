#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if(top == NULL){
        cout << "\nempty stack";
    }
    else{
        cout << "Popped element is " << top->data;
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        cout << "\nempty stack";
    }
    else{
        cout << "\nTop element is " << top->data;
    }
}

void display(){
    if(top == NULL){
        cout << "\nempty stack";
    }
    else{
        cout << "\nElements are ";
        for(Node* ptr = top; ptr != NULL; ptr = ptr->next){
            cout << ptr->data << " ";
        }
    }
}

int main(){
    int ch, val;

    do{
        cout << "\n1.push";
        cout << "\n2.pop";
        cout << "\n3.peek";
        cout << "\n4.display";
        cout << "\n5.Exit";
        cout << "\nEnter choice ";
        cin >> ch;

        switch(ch){
            case 1:
                cout << "\nEnter element to push ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "\nExit";
                break;
            default:
                cout << "\nWrong choice";
                break;
        }
    }while(ch != 5);

    return 0;
}
