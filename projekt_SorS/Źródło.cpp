#include <iostream>
#include <random>

using namespace std;

bool stay(int corectAnswer) {
	int answer = rand() % 3;
	int notTrue{};

	do
	{
		notTrue = rand() % 3;										//generowanie podpowiedzi
	} while (notTrue != corectAnswer && notTrue != answer);

	if (answer == corectAnswer)return true;
	return false;
}

bool change(int corectAnswer){
	int answer = rand() % 3;
	int notTrue{};

	do
	{
		notTrue = rand() % 3;										//generowanie podpowiedzi
	} while (notTrue != corectAnswer && notTrue != answer);

	int newAnswer{};

	do
	{
		newAnswer = rand() % 3;
	} while (newAnswer != answer && newAnswer != notTrue);          //generowanie nowej odpowiedzi
	
	if (newAnswer == corectAnswer)return true;
	return false;
}

int main() {
	int corectAnswer{}, stayCorect{}, changeCorect{}, notTrue{}, j{};
	for (int i = 0; i < 1000; i++)
	{
		corectAnswer = rand() % 3;   //generowanie poprawnej odpowiedzi od 0 do 2
	
		if(stay(corectAnswer))stayCorect++;  
		if(change(corectAnswer))changeCorect++;
		j++;
	}
	cout << "dla funkcji ktora nie zmiennia odpowiedzi wynik wynosi: " << stayCorect<<endl;
	cout << "dla funkcji ktora zmiennia odpowiedz wynik wynosi: " << changeCorect;
}