#include <iostream>
#include <random>
#include <ctime>

using namespace std;

bool stay(int corectAnswer) {
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> trzy(1, 3);
	int answer = trzy(generator);
	int notTrue{};

	do
	{
		notTrue = trzy(generator);										//generowanie podpowiedzi
	} while (notTrue != corectAnswer && notTrue != answer);

	if (answer == corectAnswer)return true;
	return false;
}

bool change(int corectAnswer){
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> trzy(1, 3);
	int answer = trzy(generator);
	int notTrue{};

	do
	{
		notTrue = trzy(generator);									//generowanie podpowiedzi
	} while (notTrue == corectAnswer || notTrue == answer);

	int newAnswer{};

	do
	{
		newAnswer = trzy(generator);
	} while (newAnswer == answer || newAnswer == notTrue);          //generowanie nowej odpowiedzi
	
	if (newAnswer == corectAnswer)return true;
	return false;
}

int main() {
	int corectAnswer{}, stayCorect{}, changeCorect{}, notTrue{}, j{};
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> trzy(1, 3);
	for (int i = 0; i < 1000; i++)
	{
		corectAnswer = trzy(generator);   //generowanie poprawnej odpowiedzi od 0 do 2
	
		if(stay(corectAnswer))stayCorect++;  
		if(change(corectAnswer))changeCorect++;
		j++;
	}
	cout << "dla funkcji ktora nie zmiennia odpowiedzi wynik wynosi: " << stayCorect<<endl;
	cout << "dla funkcji ktora zmiennia odpowiedz wynik wynosi: " << changeCorect<<endl;
	cout << "program wykonal sie za pomoca Mersenne Twister w"<<clock()<<" milisekund";
}