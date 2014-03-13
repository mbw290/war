#include<iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;
int funcCount = 0;
class Cards
{
public:
	int value;
};

class Deck
{
public:
  int wDeck[52];
  int shuffledDeck[52];
//Populate the deck with cards
  void fillDeck()
  {
    int i = 0;
    int cardnum = 2;
      while (i<52)
      {
        for (int j = 1; j<5; j++)
	{
	  wDeck[i] = cardnum;
	  i++;
	}
        cardnum++;
      }
    }
	//Print method for debugging
  void printDeck()
  {
    for (int i = 0; i<52; i++)
    {
      switch (shuffledDeck[i])
      {
        case 11:
	cout << "J" << endl;
	break;
	case 12:
	cout << "Q" << endl;
	break;
	case 13:
	cout << "K" << endl;
	break;
	case 14:
	cout << "A" << endl;
	break;
	default: cout << shuffledDeck[i] << endl;
	}
    }
  }
  void shuffleDeck()
  {
  short int nums[52];
  short int x = 0, y = 0;
  srand(time(NULL));
  x = 0;
    while (x < 52)
    {
      y = 0;
      nums[x] = rand() % 52; //Change the 100 to change the range. This currently has a range 1-100.
      while (y < 52)
      {
        if (nums[y] == nums[x] && x != y) //If another number is equal to this one.
	{
	  --x; //Set x back one. 
	  y = 0; //Reset y;
	  break; //Try again.
	}
	else
	{
	  ++y; //Otherwise, check the next number.
	}
      }
     ++x; //When we reach here, if --x happened, we are about to re-do a number that was not unique. Otherwise, do the next number.
   }
  x = 0; //This next bit just outputs the numbers to the console. 
    while (x < 52)
    {
      shuffledDeck[x] = wDeck[nums[x]];
      ++x;
    }

  }
};

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
    newLink->pHand = nHand;
    nHand->value = cValue;
    newLink->Next = First; //makes next null
    First = newLink;
  }

  void AddCardEnd(int cValue)
  {
//We setup two pointers to Link objects
  Link *lastItem = new Link;
  Link *newNode = new Link;
  Hand *nHand = new Hand;
//This pointer called lastItem will start at the first element and go through the list
  lastItem = First;
//Set the parameters of the hand
  newNode->pHand = nHand;
  nHand->value = 1;
//If the first item is null then set it to the new Node
    if (First == NULL)
    {
      First = newNode;
      First->Next = NULL;
    }
    else
    {
//Loop through the linked list to find the last element
      while (lastItem->Next != NULL)
      {
        lastItem = lastItem->Next;
      }
//The item after the last item will be our new item
       lastItem->Next = newNode;
     }
  }


  void RemoveCard()
  {
    delete First->pHand;;
    First = First->Next;
  }

	//Remove the entire linked list
  void RemoveList(LinkedList LL)
  {
    Link *current = new Link;
    Link *temp = new Link;
    current = First;
//Loop through the list for the last item
     while (current != NULL)
     {
//Since we are going to remove the current link, we must store the next node in a temp variable to reuse
       temp = current->Next;
//Remove the hand and the link, then move to the next item by setting current back to temp which held the node after the one we deleted
       delete current->pHand;
       delete current;
       current = temp;
      }
//Since you've reached the end, there is one more link and card that is null that must be deleted
  delete current->pHand;
  delete current;
  }

  void Display()
  {
    int counter=0;
    Link *current = First;
      while (current != NULL)
      {
      AddCard(current->pHand->value);
      }
   }
int turn()
  {
    int val;
    Link *current = First;
    val = current->pHand->value;
    cout << val;
    //First = First->Next;
    return val;
   }
  int war()
  {
    int val1, val2, val3;
    val1 = turn();
    val2 = turn();
    val3 = turn();
    return turn();
  }
};


  int main()
  {
    Deck nDeck;
    LinkedList P1;
    LinkedList P2;
    LinkedList war;
    int x;
    int counter=0;
    nDeck.fillDeck();
    nDeck.shuffleDeck();
      for (int i = 0; i < 52; i++)
      {
        if (i % 2 == 0)
	{
	  P1.AddCard(nDeck.shuffledDeck[i]);
	}
	else
	{
	  P2.AddCard(nDeck.shuffledDeck[i]);
	}
      }
  cout << "-----Player1-----" << endl;
  cout << "-----Player2-----" << endl;
  cout << "-------------------------" << endl;
  int P1Card, P2Card;//holds the value of the turn
	do
	{
          //cout << "Player one's score is "; P1.Display(); cout << "\n";
          //cout << "Player two's score is "; P2.Display(); cout << "\n";
          cout << "\nEnter 1 to play" << endl;
	  cin >> x;
	  cout << "P1 card: ";
	  P1Card = P1.turn();
	  cout << endl << "P2 card : ";
	  P2Card = P2.turn();
	  cout << endl;
//these ifs compare the value of the cards turned
  	  if (P1Card > P2Card)
	  {
	    cout << "Player1 wins this round!";
            war.Display();
            P1.RemoveCard();
            P1.AddCardEnd(P1Card);
	    P1.AddCardEnd(P2Card);
            P2.RemoveCard();
            cout << "Player 1 now has ";
            P1.Display();
	  }
	  if (P2Card > P1Card)
	  {
	    cout << "Player2 wins this round!";
            P2.RemoveCard();
	    P2.AddCardEnd(P2Card);
            P2.AddCardEnd(P1Card);
            P1.RemoveCard(); 
            cout << "Player 2 now has ";
            P2.Display();
	  }
	  if (P1Card == P2Card)
	  {
	    cout << "WAR" << "\n";
            war.AddCard(P1.turn());
            war.AddCard(P1.turn());
            war.AddCard(P1.turn());
            P1.RemoveCard();
            P1.RemoveCard();
            P1.RemoveCard();
            P1.RemoveCard();

            war.AddCard(P2.turn());
            war.AddCard(P2.turn());
            war.AddCard(P2.turn());
            P2.RemoveCard();
            P2.RemoveCard();
            P2.RemoveCard();
            P2.RemoveCard();
	  }
	} while (x==1);
	
	return 0;
  }
