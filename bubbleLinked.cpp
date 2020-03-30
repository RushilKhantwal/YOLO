#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};
struct node* swap(struct node* ptr1, struct node* ptr2)
{
    struct node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
class LinkedList
{
    node* head;
    node* tail;
public:
    LinkedList()
        {
           head = tail = NULL;
        }
   void  add2head(int x)
    {
        node* temp = new node();
        temp->data = x;
        if(head == NULL)
        {
                head = temp;
                tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void add2tail(int x)
    {
        node* temp = new node();
        temp->data = x;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            node* t= new node();

            t= head;
            while(t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
            tail = temp;
        }
    }
    void display()
    {
        if(head == NULL)
        {
            cout<<"\nList Empty!";
        }
        else
        {
            node* t = new node();
            t = head;
            while(t->next != NULL)
            {
                cout<<t->data<<" ";
                t=t->next;
            }
            cout<<t->data;

        }
    }

void bsort(int n)
{
    node* temp = new node();

    int i=0,j=0;
    int t;
    for(i=0;i<n;i++)
    {
         temp = head;
        while(temp->next != NULL)
        {
         if(temp->data > temp ->next->data )
            {
                        t = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = t;
            }
            temp = temp->next;
        }
    }

}


};

int main()
{
        LinkedList L;
        int  n;
        cin>>n;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            L.add2head(x);
        }
        L.bsort(n);
        L.display();

    return 0;
}
