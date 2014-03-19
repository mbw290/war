#include<iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;
/*COM252 War midterm project
 * Rob Mancuso, Matthew Wimpelberg
*/

int funcCount = 0;

//Deck class to hold an array of cards
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
		//Start with card 2 and fill 4 of each up to 14 
		//We will handle printing J Q K A later from 11-14
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
                        //Generate a random number in the range of 0-52
			nums[x] = rand() % 52; 
                        //Check each number in the array to make sure the current random number isn't in it
			while (y < 52)
			{
				//If another number is equal to this one.
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
			++x; //When we reach here, if --x happened, we need to start over.
		}
		x = 0; 
		//Fill the empty array of shuffled cards with the value of a random array element as the index of the ordered deck
		while (x < 52)
		{
			shuffledDeck[x] = wDeck[nums[x]];
			++x;
		}

	}
};

//Class to hold each players hand as a linked list
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
//Add a card to the beginning of the list
	void AddCard(int cValue)
	{
		Link *newLink = new Link;
		Hand *nHand = new Hand;
		newLink->pHand = nHand;
		nHand->value = cValue;
		newLink->Next = First; //makes next null
		First = newLink;
	}
//Add a card at the end or in this case the bottom of the pile so that it's not used by the player in the next hand after a winning one
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
			//Remove the hand and the link, then move to the next item by setting current back to temp which held the node after the one we delet
			delete current->pHand;
			delete current;
			current = temp;
		}
		//Since you've reached the end, there is one more link and card that is null that must be deleted
		delete current->pHand;
		delete current;
	}

	int Display()
	{
        int counter=0;
        Link *current = First;
          while (current != NULL)
          {
          current = current->Next;
          counter++;
          }
         return counter;
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
	//Deal out three cards from each player if there is a tie aka war
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
//Setup a deck object to hold the shuffled array and two linkedlist for a players hand
	Deck nDeck;
	LinkedList P1;
	LinkedList P2;
	LinkedList war;
	int x;
	int counter = 0;
//Fill in the deck then shuffle it
	nDeck.fillDeck();
	nDeck.shuffleDeck();
        int p1count,p2count;
//Deal out the cards to each player from the shuffled deck
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
	int P1Card, P2Card, wCard1, wCard2;//holds the value of the turn
	int wCount = 0;
	do
	{
		cout <<"count" << p1count << "\n";
                 p1count= P1.Display();
                 p2count = P2.Display();
		//cout << "Player two's score is "; P2.Display(); cout << "\n";
		//cout << "\nEnter 1 to play" << endl;
		//cin >> x;
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
		do
		{
			if (P1Card == P2Card)
			{
				wCount=wCount+10;
				cout << "WAR" << "\n";
				war.AddCard(P1.turn());
				war.AddCard(P1.turn());
				war.AddCard(P1.turn());
				wCard1 = P1.turn();
				war.AddCard(wCard1);
				war.AddCard(P1Card);
				P1.RemoveCard();

				war.AddCard(P2.turn());
				war.AddCard(P2.turn());
				war.AddCard(P2.turn());
				war.AddCard(P2Card);
				wCard2 = P2.turn();
				war.AddCard(wCard2);
				P2.RemoveCard();
				cout << "P1 drew " << wCard1 << "\n";
				cout << "P2 drew " << wCard2 << "\n";

				cout << "wcount is " << wCount << "\n";
				if (wCard1 > wCard2)
				{
				cout << "P1 wins war" << "\n";
					for (int i =0; i<(wCount/10); i++)
					{
						P1.AddCardEnd(war.turn());
					}

					for (int j = 0; j < (wCount/10);j++)
					{
						P1.RemoveCard();
					}
				break;
				}
				if (wCard1 < wCard2)
				{
				cout << "P2 wins war" << "\n";
					for (int i = 1; i < wCount; i++)
					{
						P2.AddCardEnd(war.turn());
					}

				break;
				}
			}	
		} while (wCard1 == wCard2);//repeats war while the cards turned last in both hands equal each other
	} while (p1count<52);

	return 0;
}

