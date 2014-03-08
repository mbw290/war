#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Cards
{
public:
  int value;
};

class Deck
{
public:
  Cards wDeck[52];
//Populate the deck with cards
  void fillDeck()
  {
  int i =0;
  int cardnum=2;
  while (i<52)
  {
      for (int j=1;j<5;j++)
      {
        wDeck[i].value=cardnum;
        i++;
      }
    cardnum++;
    }
  }
//Print method for debugging
  void printDeck()
  {
    for(int i=0; i<52; i++)
    {
      cout << wDeck[i].value << "\n";
    }
  }

  void shuffleDeck()
{
//srand(time(NULL));
int shuffleNum[52];
Cards shuffledDeck[52];
int x,y;
short randNum=rand() % 52;
int counter,index;
  while(x < 52)
  {
    y = 0;
    shuffleNum[x] = randNum;
    while(y < 52)
    {
      if(shuffleNum[y] == shuffleNum[x] && x != y) //If another number is equal to this one.
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
  while (counter<52)
  {
    index=shuffleNum[counter];
    //shuffledDeck[counter].value=wDeck[index].value;
    cout << index << "\n";
    counter++;
  }
}

};

int main()
{
Deck nDeck;
nDeck.fillDeck();
//nDeck.printDeck();
nDeck.shuffleDeck();
return 0;
}
