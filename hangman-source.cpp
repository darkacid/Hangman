#include <iostream>
#include <string>
#include <random>
using namespace std;

/*	
	Future Notes:
	** Use a textfile to load the dictionary 
	*  convert the input from the text file to be all lowercase	
*/



// Functions to keep main() clean

void gamestart(); 
int randomize(int); 
string encode(string);	
void  gameloop(string);

int main()
{
	gamestart();
}

 

	 void  gamestart()
	{
		
		const int wordcount = 5;
		int charcount = 0;

		string chosenword="null";
		string wordarray[wordcount] = { "apple", "banana", "pear", "orange", "pickle" };
		
		chosenword = wordarray[randomize(wordcount)]; //call the randomize function,to decide which word will be chosen for guessing
		charcount =  chosenword.size();

		cout << "The hidden word is : "<<encode(chosenword) << endl;
		gameloop(chosenword);
		
	}

	 

	 int randomize(int wordcount)	
	 
	 {		 
		 random_device rd;
		 mt19937 e2(rd());
		 uniform_real_distribution<> distReal(0, wordcount);
		 return distReal(e2);
	 }

	 string  encode(string chosenword)		//The function takes the word and returns it  as hyphens
	 {	
		 for (int count = 0; count < chosenword.size(); count++)	
																			
																	
			{
				chosenword[count]='-';

			}		
		return chosenword;
	 }

void gameloop(string word)
{
	string uncovered = encode(word);
	int guessed=false;
	
	while( guessed != true)
	{
		char letter; //the input from the user will be stored here
		
		cout<< "Guess a letter : ";
		cin >> letter;
		for(int count=0 ; count < word.size() ; count++ )
			{
				if (word[count] == letter)
					{
						 //cout<<"You guessed a letter"<<endl;
						 cout << endl;
						 uncovered[count] = letter;
						
					}
		
			}
			 for(int count=0;count<word.size();count++)
			 {
				 cout<<uncovered[count];
			}
			cout<<endl;
	}
}
