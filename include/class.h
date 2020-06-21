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
			printf("Àâòîìàò óæå ðàáîòàåò\n");
		}
	}

	int off()
	{
		state = OFF;
		if (cash != 0)
		{
			cout << "Âàøà ñäà÷à - " << cash;
			return cash;
		}
	}

	void coin(int money)
	{
		if (state == ACCEPT)
		{
			cash += money;
			printf("Âû ïîëîæèëè %d â àâòîìàò\n", cash);
		}
		else if (state == WAIT)
		{
			state = ACCEPT;
			cash += money;
			printf("Âû ïîëîæèëè %d â àâòîìàò\n", cash);
		}
	}

	void PrintMenu()
	{
		int size = menu.size();
		for (int i = 0; i < size; i++)
		{
			cout << menu[i] << " - " << prices[i] << " - êíîïêà " << button[i] <<" \n";
		}
	}

	void PrintState()
	{
		cout << "Â äàííûé ìîìåíò àâòîìàò " << states[state] << "\n";
	}

	void choice(int button)
	{
		if ((state == ACCEPT) || (state == WAIT))
		{
			if ((button >= 0) && (button <= 4))
			{
				cout << "Âû âûáðàëè " << menu[button] << "\n";
				state = CHECK;
				check(button);
			}
			else
			{
				printf("Âû íàæàëè íåâåðíóþ êíîïêó\n");
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
				printf("Íåäîñòàòî÷íî ñðåäñòâ\n");
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
		printf("Ãîòîâèì âàø íàïèòîê.....\n");
		finish(button);
	}

	void finish(int button)
	{
		state = WAIT;
		cout << "Âàø íàïèòîê - " << menu[button] << " ãîòîâ.\n";
	}
	
	string ReturnState()
	{
		return states[state];
	}

};
