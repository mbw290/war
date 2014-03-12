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
	int wDeck[52];
	int shuffledDeck[52];
	//Populate the deck with cards
	void fillDeck()
	{
		int i = 0;
		int cardnum = 1;
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
while(x < 52)
{
 y = 0;
 nums[x] = rand() % 52; //Change the 100 to change the range. This currently has a range 1-100.
    while(y < 52)
    {
       if(nums[y] == nums[x] && x != y) //If another number is equal to this one.
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
while(x < 52)
{
 shuffledDeck[x]=wDeck[nums[x]];
 cout << shuffledDeck[x] << "\n"; 
 ++x;
}

}


};




int main()
{
Deck nDeck;
nDeck.fillDeck();
nDeck.shuffleDeck();
//nDeck.printDeck();
return 0;
}

