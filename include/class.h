#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Automata
{
private:

	int cash;
	vector <string> menu;
	vector <int> button;
	vector <int> prices;
	enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
	STATES state;
	vector <string> states;

public:

	Automata(vector <string> menu, vector <int> button, vector <int> prices, vector <string> states)
	{
		state = OFF;
		cash = 0;
		this->menu = menu;
		this->button = button;
		this->prices = prices;
		this->states = states;
	}

	void on()
	{
		if (state == OFF)
		{
			state = WAIT;
		}
		else
		{
			printf("Автомат уже работает\n");
		}
	}

	int off()
	{
		state = OFF;
		if (cash != 0)
		{
			cout << "Ваша сдача - " << cash;
			return cash;
		}
	}

	void coin(int money)
	{
		if (state == ACCEPT)
		{
			cash += money;
			printf("Вы положили %d в автомат\n", cash);
		}
		else if (state == WAIT)
		{
			state = ACCEPT;
			cash += money;
			printf("Вы положили %d в автомат\n", cash);
		}
	}

	void PrintMenu()
	{
		int size = menu.size();
		for (int i = 0; i < size; i++)
		{
			cout << menu[i] << " - " << prices[i] << " - кнопка " << button[i] <<" \n";
		}
	}

	void PrintState()
	{
		cout << "В данный момент автомат " << states[state] << "\n";
	}

	void choice(int button)
	{
		if ((state == ACCEPT) || (state == WAIT))
		{
			if ((button >= 0) && (button <= 4))
			{
				cout << "Вы выбрали " << menu[button] << "\n";
				state = CHECK;
				check(button);
			}
			else
			{
				printf("Вы нажали неверную кнопку\n");
			}
		}
	}

	void check(int button)
	{
		if (state == CHECK)
		{
			if (cash >= prices[button])
			{
				cash = cash - prices[button];
				state = COOK;
				cook(button);
			}
			else
			{
				printf("Недостаточно средств\n");
				state = WAIT;
			}
		}
	}

	void cancel()
	{
		if ((state == ACCEPT) || (state == CHECK))
		{
			state = WAIT;
		}
	}

	void cook(int button)
	{
		printf("Готовим ваш напиток.....\n");
		finish(button);
	}

	void finish(int button)
	{
		state = WAIT;
		cout << "Ваш напиток - " << menu[button] << " готов.\n";
	}

};