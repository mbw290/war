#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Cards
{
public:
  int value;
  bool Card operator ==(Card c1)
  {
    return(value == c1.value)?true:false;
  }
<<<<<<< HEAD
=======
  
  bool Card operator >(Card c1)
  {
    return(value > c1.value)?true:false;
>>>>>>> 16ddd23ef3c77ee88afcac45353197316d8612d8
  }
};

class Deck
{
public:
  int wDeck[52];
  int shuffledDeck[52];
//Populate the deck with cards
  void fillDeck()
  {
  int i =0;
  int cardnum=2;
  while (i<52)
  {
      for (int j=1;j<5;j++)
      {
        wDeck[i]=cardnum;
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
      cout << shuffledDeck[i] << "\n";
    }
  }

void shuffleDeck()
{
//srand(time(NULL));
int shuffleNum[52];
int x=0;
int y =0;
int count=0;
int counter,index;
  while(x < 52)
  {
    shuffleNum[x] = rand() % 52;
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
    shuffledDeck[counter]=wDeck[index];
    counter++;
  }
}

};




int main()
{
Deck nDeck;
nDeck.fillDeck();
nDeck.shuffleDeck();
nDeck.printDeck();
return 0;
}
