#include<bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    node* next;
};
class linkedlist
{
    node* head;
    node* tail;
public:
    linkedlist()
    {
        head = tail = NULL;
    }
  void add2tail(int x)
  {
      node* temp = new node();
      temp->data = x;
      if(head == NULL)
      {
          head=tail=temp;
      }
      else if(head->next == NULL)
      {
          head->next = temp;
          tail = temp;
      }
      else
      {
          node* t = new node();
          t= head;
          while(t->next != NULL)
                {
                    t= t->next;
                }
                t->next = temp;
                tail = temp;
      }
  }
   void reverse()
    {
        node* current = head;
        node *prev = NULL, *n = NULL;

        while (current != NULL)
            {
            n = current->next;
            current->next = prev;

            prev = current;
            current = n;
        }
        head = prev;
    }
   void display()
   {
       node* temp = new node();

       temp = head;
       while(temp->next != NULL)
       {
           cout<<temp->data<<" ";
           temp = temp->next;
       }
       cout<<temp->data;
   }
   void append(int k,int n)
   {
      k = k%n;
      if(k != 0)
       {
           node* t = new node();
            t = head;
                for(int i=0;i<k;i++)
            {
                    t= t->next;
            }
            node* temp = new node();
            temp = t->next;
            tail->next = head;
            head = temp;
            t->next = NULL;
       }
    }
};

int main()
{
    int n;
    cin>>n;
    linkedlist L;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        L.add2tail(x);
    }
   //L.reverse();
   int k;
   cin>>k;
   L.append(k,n);
   L.display();
    return 0;
}
