#include "gtest/gtest.h"
#include "class.h"

TEST(laba4, test1)
{
    vector <string> menu = { "Cappuccino", "Latte", "Espresso", "Americano", "Barista" };
	vector <int> button = { 0, 1, 2, 3, 4 };
	vector <int> prices = { 10, 20, 30, 40, 50 };
	vector <string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
    Automata Machine(menu, button, prices, states);
    string state = Machine.ReturnState();
    EXPECT_EQ("OFF", state);
}

TEST(laba4, test2)
{
    vector <string> menu = { "Cappuccino", "Latte", "Espresso", "Americano", "Barista" };
	vector <int> button = { 0, 1, 2, 3, 4 };
	vector <int> prices = { 10, 20, 30, 40, 50 };
	vector <string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
    Automata Machine(menu, button, prices, states);
    
    int money = 20;
    Machine.on();
    Machine.coin(money);
    
    EXPECT_EQ(20, cash);
}


TEST(laba4, test3)
{
    vector <string> menu = { "Cappuccino", "Latte", "Espresso", "Americano", "Barista" };
	vector <int> button = { 0, 1, 2, 3, 4 };
	vector <int> prices = { 10, 20, 30, 40, 50 };
	vector <string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
    Automata Machine(menu, button, prices, states);
    
    int money = 20;
    Machine.on();
    Machine.coin(money);
    Machine.choice(2);
    
    string state = Machine.ReturnState();
    EXPECT_EQ("WAIT", state);
}

TEST(laba4, test4)
{
    vector <string> menu = { "Cappuccino", "Latte", "Espresso", "Americano", "Barista" };
	vector <int> button = { 0, 1, 2, 3, 4 };
	vector <int> prices = { 10, 20, 30, 40, 50 };
	vector <string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
    Automata Machine(menu, button, prices, states);
    
    int money = 20;
    Machine.on();
    Machine.coin(money);
    money = 30;
    Machine.coin(money);
    
    EXPECT_EQ(50, cash);
}


TEST(laba4, test5)
{
    vector <string> menu = { "Cappuccino", "Latte", "Espresso", "Americano", "Barista" };
	vector <int> button = { 0, 1, 2, 3, 4 };
	vector <int> prices = { 10, 20, 30, 40, 50 };
	vector <string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
    Automata Machine(menu, button, prices, states);
    
    int money = 100;
    Machine.on();
    Machine.coin(money);
    Machine.choice(4);
    int money = Machine.off();
    EXPECT_EQ(50, money);
}
