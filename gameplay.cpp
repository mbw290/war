#include<iostream>
#include <stdio.h>

using namespace std;

class Hand
{
  public:
    int value;
};

class Link
{
  public:
   Hand *pHand;
   Link *Next;
};

class LinkedList
{
  private:
    Link *First;
    Link *Last;
  public:
    LinkedList()
    {
      First = NULL;
    }

   void AddCard(int cValue)
   {
     Link *newLink = new Link;
     Hand *nHand = new Hand;
     newLink->pHand= nHand;
     nHand->value=cValue;
     newLink->Next=First; //makes next null
     First=newLink;
  }


   void AddCardEnd(int cValue)
   {
     //We setup two pointers to Link objects
     Link *lastItem=new Link;
     Link *newNode=new Link;
     Hand *nHand = new Hand;
     //This pointer called lastItem will start at the first element and go through the list
     lastItem=First;	
     //Set the parameters of the hand
     newNode->pHand=nHand;
     nHand->value=1;
     //If the first item is null then set it to the new Node
       if (First==NULL)
       {
         First=newNode;
         First->Next=NULL;
       }
       else
       {
       //Loop through the linked list to find the last element
         while (lastItem->Next != NULL)
         {
           lastItem=lastItem->Next;
         }  
       //The item after the last item will be our new item
       lastItem->Next=newNode;
       }
    }


  void RemoveCard()
  {
   delete First->pHand;;
   First=First->Next;
  }
 
  //Remove the entire linked list
  void RemoveList(LinkedList LL)
  {
     Link *current=new Link;
     Link *temp = new Link;
     current=First;
  //Loop through the list for the last item
       while (current != NULL)
       {
  //Since we are going to remove the current link, we must store the next node in a temp variable to reuse
       temp=current->Next; 
  //Remove the hand and the link, then move to the next item by setting current back to temp which held the node after the one we deleted
       delete current->pHand;
       delete current;
       current=temp;
       }
  //Since you've reached the end, there is one more link and card that is null that must be deleted
    delete current->pHand;
    delete current;
  }

  void Display()
  {
   Link *current=First;
   while (current != NULL)
   {
     cout << "You have: " << current->pHand->value<<"\n";
     current = current->Next;
   }
  }
};
  int main()
{
  LinkedList LL; 
  int matt=1; 
  LL.AddCard(matt); 
  int rob=2;
  LL.AddCard(rob);
  LL.Display();
  return 0;
}
