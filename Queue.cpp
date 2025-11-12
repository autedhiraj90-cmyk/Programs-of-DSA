#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int val)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
        rear->next = front;   // circular link
    }
    else
    {
        rear->next = newNode;
        newNode->next = front;
        rear = newNode;
    }

    cout << "Front : " << front->data << endl;
    cout << "Rear : " << rear->data << endl;
}

void dequeue()
{
    if(front == NULL && rear == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;

    // Removing last element
    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

void peek()
{
    if(front == NULL && rear == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Element present at front is " << front->data << endl;
    }
}

void display()
{
    if(front == NULL && rear == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *ptr = front;
    cout << "Front : " << front->data << endl;
    cout << "Rear : " << rear->data << endl;

    cout << "Queue: ";
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    while(ptr != front);

    cout << endl << endl;
}

int main(void)
{
    int ch,val;

    cout<<"1)Enqueue\n";
    cout<<"2)Dequeue\n";
    cout<<"3)Display\n";
    cout<<"4)Peek\n";
    cout<<"5)Exit\n";

    do
    {
        cout<<"Enter choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Element to enqueue: "<<endl;
                cin>>val;
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                cout<<"Exit\n";
                break;

            default:
                cout<<"Incorrect choice!\n";
        }
    }
    while(ch != 5);

    return 0;
}
