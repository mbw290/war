#include<iostream>

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
};

int main()
{
Deck nDeck;
nDeck.fillDeck();
nDeck.printDeck();
return 0;
}
