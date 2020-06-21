#include <iostream>
#include <vector>
#include <string>
#include "class.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	vector <string> menu = { "Cappuccino", "Latte", "Espresso", "Americano", "Barista" };
	vector <int> button = { 0, 1, 2, 3, 4 };
	vector <int> prices = { 10, 20, 30, 40, 50 };
	vector <string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };

	int money = 20;
	Automata Machine(menu, button, prices, states);
	Machine.PrintState();
	Machine.on();
	Machine.PrintState();
	Machine.PrintMenu();

	Machine.coin(money);
	Machine.PrintState();

	Machine.choice(2);
	Machine.PrintState();

	Machine.choice(1);
	Machine.PrintState();

	Machine.coin(100);
	Machine.choice(5);
	Machine.choice(4);
	Machine.off();
}

