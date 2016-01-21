// Pokemon_Battle_Advanced.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

//**********************************************Pokemon Utility********************************************************

const int NUMBER_OF_POKEMON = 4;
const int POTION_STR = 100;
const int MAX_HEALTH = 200;
const int MAX_POTION = 6;
const int CRITICAL_HIT = 3;
const int CRITICAL_HIT_FACTOR = 5;
const int RECOVER_FACTOR = 10;
const int DEMOBILIZE_FACTOR = 3;
const int MISS_FACTOR = 5;
const double EFFECTIVE_FACTOR = 1.5;
const double NON_EFFECTIVE_FACTOR = 0.75;

//**********************************************Pokemon Abstract Class*************************************************
class Pokemon
{
public:
	Pokemon(double health = MAX_HEALTH, bool conscious = true);
	virtual void Greet() const = 0;
	void Potion();
	void DisplayHealth() const;
	
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);

	double m_Health;
	bool m_Conscious;
	
	string m_type;
};

Pokemon::Pokemon(double health, bool conscious) : m_Health(health), m_Conscious(conscious)
{

}

void Pokemon::Potion()
{
	m_Health += POTION_STR;
	if (m_Health > MAX_HEALTH)
		m_Health = MAX_HEALTH;
}

void Pokemon::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

void Pokemon::move1(Pokemon& opponent)
{

}

void Pokemon::move2(Pokemon& opponent)
{

}

void Pokemon::move3(Pokemon& opponent)
{

}

void Pokemon::move4(Pokemon& opponent)
{

}

//************************************************Pikachu Class*********************************************************

const int ELECTRIC_SHOCK_STR = 5;
const int QUICK_ATTACK_STR = 10;
const int THUNDER_SHOCK_STR = 15;
const int THUNDER_STR = 20;

class Pikachu : public Pokemon
{
public:
	virtual void Greet() const;
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);
};

void Pikachu::Greet() const
{
	cout << "Pika Pika!\n";
}

void Pikachu::move1(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "water")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "grass")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Pikachu!\n";
		opponent.m_Health -= multiplier * ELECTRIC_SHOCK_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * ELECTRIC_SHOCK_STR;
	}
	if (rand() % DEMOBILIZE_FACTOR == 0)
	{
		opponent.m_Conscious = false;
		cout << "Pikachu has demobilized the opponent!\n";
	}
}

void Pikachu::move2(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Pikachu!\n";
		opponent.m_Health -= QUICK_ATTACK_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= QUICK_ATTACK_STR;
	}
}

void Pikachu::move3(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "water")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "grass")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Pikachu!\n";
		opponent.m_Health -= multiplier * THUNDER_SHOCK_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * THUNDER_SHOCK_STR;
	}
}

void Pikachu::move4(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "water")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "grass")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % MISS_FACTOR != 0)
	{
		if (rand() % CRITICAL_HIT_FACTOR == 0)
		{
			cout << "Critical Hit from Pikachu!\n";
			opponent.m_Health -= multiplier * THUNDER_STR*CRITICAL_HIT;
		}
		else
		{
			opponent.m_Health -= multiplier * THUNDER_STR;
		}
	}
	else
	{
		cout << "Pikachu's Thunder missed...\n";
	}
}

//***************************************************Bulbasaur Class*****************************************************

const int VINE_WHIP_STR = 5;
const int POISON_POWDER_STR = 10;
const int RAZOR_LEAF_STR = 15;
const int SEED_BOMB_STR = 20;

class Bulbasaur : public Pokemon
{
public:
	virtual void Greet() const;
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);
};

void Bulbasaur::Greet() const
{
	cout << "Da-ne Da-ne!\n";
}

void Bulbasaur::move1(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "water")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "fire")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Bulbasaur!\n";
		opponent.m_Health -= multiplier * VINE_WHIP_STR*CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * VINE_WHIP_STR;
	}
	if (rand() % DEMOBILIZE_FACTOR == 0)
	{
		opponent.m_Conscious = false;
		cout << "Bulbasaur has demobilized the opponent!\n";
	}
}

void Bulbasaur::move2(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Bulbasaur!\n";
		opponent.m_Health -= POISON_POWDER_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= POISON_POWDER_STR;
	}
}

void Bulbasaur::move3(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "water")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "fire")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Bulbasaur!\n";
		opponent.m_Health -= multiplier * RAZOR_LEAF_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * RAZOR_LEAF_STR;
	}
}

void Bulbasaur::move4(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "water")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "fire")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % MISS_FACTOR != 0)
	{
		if (rand() % CRITICAL_HIT_FACTOR == 0)
		{
			cout << "Critical Hit from Bulbasaur!\n";
			opponent.m_Health -= multiplier * SEED_BOMB_STR * CRITICAL_HIT;
		}
		else
		{
			opponent.m_Health -= multiplier * SEED_BOMB_STR;
		}
	}
	else
	{
		cout << "Bulbasaur's Seed Bomb missed...\n";
	}
}

//***************************************************Charmander Class*****************************************************

const int SCRATCH_STR = 5;
const int EMBER_STR = 10;
const int FLAME_BURST_STR = 15;
const int DRAGON_RAGE_STR = 20;

class Charmander : public Pokemon
{
public:
	virtual void Greet() const;
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);
};

void Charmander::Greet() const
{
	cout << "Hi-to Hi-to!\n";
}

void Charmander::move1(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Charmander!\n";
		opponent.m_Health -= SCRATCH_STR*CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= SCRATCH_STR;
	}
	if (rand() % DEMOBILIZE_FACTOR == 0)
	{
		opponent.m_Conscious = false;
		cout << "Charmander has demobilized the opponent!\n";
	}
}

void Charmander::move2(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "grass")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "water")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Charmander!\n";
		opponent.m_Health -= multiplier * EMBER_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * EMBER_STR;
	}
}

void Charmander::move3(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "grass")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "water")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Charmander!\n";
		opponent.m_Health -= multiplier * FLAME_BURST_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * FLAME_BURST_STR;
	}
}

void Charmander::move4(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % MISS_FACTOR != 0)
	{
		if (rand() % CRITICAL_HIT_FACTOR == 0)
		{
			cout << "Critical Hit from Charmander!\n";
			opponent.m_Health -= DRAGON_RAGE_STR * CRITICAL_HIT;
		}
		else
		{
			opponent.m_Health -= DRAGON_RAGE_STR;
		}
	}
	else
	{
		cout << "Charmander's Seed Bomb missed...\n";
	}
}

//***************************************************Squirtle Class*****************************************************

const int TACKLE_STR = 5;
const int WATER_GUN_STR = 10;
const int BUBBLE_STR = 15;
const int RAPID_SPIN_STR = 20;

class Squirtle : public Pokemon
{
public:
	virtual void Greet() const;
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);
};

void Squirtle::Greet() const
{
	cout << "Ga-me Ga-me!\n";
}

void Squirtle::move1(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Squirtle!\n";
		opponent.m_Health -= TACKLE_STR*CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= TACKLE_STR;
	}
	if (rand() % DEMOBILIZE_FACTOR == 0)
	{
		opponent.m_Conscious = false;
		cout << "Squirtle has demobilized the opponent!\n";
	}
}

void Squirtle::move2(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "fire")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "grass" || opponent.m_type == "electric")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Squirtle!\n";
		opponent.m_Health -= multiplier * WATER_GUN_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * WATER_GUN_STR;
	}
}

void Squirtle::move3(Pokemon& opponent)
{
	double multiplier;
	if (opponent.m_type == "fire")
	{
		multiplier = EFFECTIVE_FACTOR;
		cout << "The attack was super effective!\n";
	}
	else if (opponent.m_type == "grass" || opponent.m_type == "electric")
	{
		multiplier = NON_EFFECTIVE_FACTOR;
		cout << "The attack was not very effective...\n";
	}
	else
	{
		multiplier = 1;
	}

	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Squirtle!\n";
		opponent.m_Health -= multiplier * BUBBLE_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= multiplier * BUBBLE_STR;
	}
}

void Squirtle::move4(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % MISS_FACTOR != 0)
	{
		if (rand() % CRITICAL_HIT_FACTOR == 0)
		{
			cout << "Critical Hit from Squirtle!\n";
			opponent.m_Health -= RAPID_SPIN_STR * CRITICAL_HIT;
		}
		else
		{
			opponent.m_Health -= RAPID_SPIN_STR;
		}
	}
	else
	{
		cout << "Squirtle's Seed Bomb missed...\n";
	}
}

//***************************************************Program Utility******************************************************

Pokemon* PokemonSelect(Pikachu& Pika, Bulbasaur& Bulba, Charmander& Charma, Squirtle& Squirt, int choice);

string PokemonName(int choice);

void new_line();

int player1_win = 0;
int player2_win = 0;
int g_round = 1;

const int MAX_ROUND = 3;

int main()
{
	cout << "Welcome to Pokemon Battle Arena!\n\n";
	cout << "Please enter your name: ";

	string player_name;
	cin >> player_name;
	new_line();

	ofstream fout;
	fout.open("Pokemon_Battle_Scores.txt", ios::app);

	if (fout.fail())
	{
		cout << "Scores file opening failed.";
		exit(1);
	}

	time_t t = time(NULL);
	tm timeinfo;
	localtime_s(&timeinfo, &t);

	fout << "\n\n\n\nPlayer name: " << player_name << "\t\t\t\t\t";
	fout << "Date:  " << (timeinfo.tm_mday) << "/" << (timeinfo.tm_mon) + 1 << "/" << (timeinfo.tm_year) + 1900 << endl << endl;
	
	cout << player_name << ", you will be fighting against Gary. ";
	cout << "You will be able to pick a pokemon of your choice for each round of the battle.\n";
	cout << "For this battle, you and Gary are each given " << MAX_POTION << " potions.\n\n";
	cout << "There are " << MAX_ROUND << " rounds to this battle. The first person to get to " << (MAX_ROUND / 2 + 1) << " wins is the winner.\n";
	cout << "Please select a pokemon from the following: \n";
	cout << "1 - Pikachu\n";
	cout << "2 - Bulbasaur\n";
	cout << "3 - Charmander\n";
	cout << "4 - Squirtle\n";
	cout << "Otherwise, if you would like to take a break from Pokemon Battle, please press 5 to leave the game.\n";

	int choice;
	cin >> choice;

	while (choice != 5 && g_round <= MAX_ROUND && player1_win < ((MAX_ROUND/2)+1) && player2_win < ((MAX_ROUND/2)+1))
	{

		cout << "**************************************************************************************************\n";
		cout << setw(50) << "ROUND " << g_round << endl;
		cout << "**************************************************************************************************\n";

		int compchoice;
		do
		{
			srand(time(0));
			compchoice = (rand() % NUMBER_OF_POKEMON) + 1;
		} while (choice == compchoice);

		Pikachu Pika;
		Bulbasaur Bulba;
		Charmander Charma;
		Squirtle Squirt;

		Pika.m_type = "electric";
		Bulba.m_type = "grass";
		Charma.m_type = "fire";
		Squirt.m_type = "water";

		Pokemon* Player1 = PokemonSelect(Pika, Bulba, Charma, Squirt, choice);
		Pokemon* Player2 = PokemonSelect(Pika, Bulba, Charma, Squirt, compchoice);

		int potion_count_p1 = MAX_POTION;
		int potion_count_p2 = MAX_POTION;

		(*Player1).Greet();

		if (choice == 1)
		{
			cout << "You have chosen a Pikachu!\n";
		}
		else if (choice == 2)
		{
			cout << "You have chosen a Bulbasaur!\n";
		}
		else if (choice == 3)
		{
			cout << "You have chosen a Charmander!\n";
		}
		else
		{
			cout << "You have chosen a Squirtle!\n";
		}

		if (compchoice == 1)
		{
			cout << "Gary has chosen a Pikachu!\n\n";
		}
		else if (compchoice == 2)
		{
			cout << "Gary has chosen a Bulbasaur.\n\n";
		}
		else if (compchoice == 3)
		{
			cout << "Gary has chosen a Charmander!\n\n";
		}
		else
		{
			cout << "Gary has chosen a Squirtle!\n\n";
		}

		while (((*Player1).m_Health > 0) && ((*Player2).m_Health > 0))
		{
			cout << "Your " << PokemonName(choice) << "'s health is now " << (*Player1).m_Health << ".\n";
			cout << "Gary's " << PokemonName(compchoice) << "'s health is now " << (*Player2).m_Health << ".\n\n";

			int move;
			cout << "Please select your next move from the following: \n";

			if (choice == 1)
			{
				cout << "1 - Electric Shock\n";
				cout << "2 - Quick Attack\n";
				cout << "3 - Thunder Shock\n";
				cout << "4 - Thunder\n";
				cout << "5 - Take a Potion\n";
			}
			else if (choice == 2)
			{
				cout << "1 - Vine Whip\n";
				cout << "2 - Poison Powder\n";
				cout << "3 - Razor Leaf\n";
				cout << "4 - Seed Bomb\n";
				cout << "5 - Take a Potion\n";
			}
			else if (choice == 3)
			{
				cout << "1 - Scratch\n";
				cout << "2 - Amber\n";
				cout << "3 - Flame Burst\n";
				cout << "4 - Dragon Rage\n";
				cout << "5 - Take a Potion\n";
			}
			else
			{
				cout << "1 - Tackle\n";
				cout << "2 - Water Gun\n";
				cout << "3 - Bubble\n";
				cout << "4 - Rapid Spin\n";
				cout << "5 - Take a Potion\n";
			}

			cin >> move;
			while (move != 1 && move != 2 && move != 3 && move != 4 && move != 5)
			{
				cout << "You have made an invalid move. Please select your move again: \n";
				cin >> move;
			}
			if ((*Player1).m_Conscious)
			{
				switch (move)
				{
				case 1:
				{
					if (choice == 1)
					{
						cout << "Pikachu uses Electric Shock.\n\n";
					}
					else if (choice == 2)
					{
						cout << "Bulbasaur uses Vine Whip.\n\n";
					}
					else if (choice == 3)
					{
						cout << "Charmander uses Scratch.\n\n";
					}
					else
					{
						cout << "Squirtle uses Tackle.\n\n";
					}
					(*Player1).move1(*Player2);
					break;
				}
				case 2:
				{
					if (choice == 1)
					{
						cout << "Pikachu uses Quick Attack.\n\n";
					}
					else if (choice == 2)
					{
						cout << "Bulbasaur uses Poison Powder.\n\n";
					}
					else if (choice == 3)
					{
						cout << "Charmander uses Amber.\n\n";
					}
					else
					{
						cout << "Squirtle uses Water Gun.\n\n";
					}
					(*Player1).move2(*Player2);
					break;
				}
				case 3:
				{
					if (choice == 1)
					{
						cout << "Pikachu uses Thunder Shock.\n\n";
					}
					else if (choice == 2)
					{
						cout << "Bulbasaur uses Razor Leaf.\n\n";
					}
					else if (choice == 3)
					{
						cout << "Charmander uses Flame Burst.\n\n";
					}
					else
					{
						cout << "Squirtle uses Bubble.\n\n";
					}
					(*Player1).move3(*Player2);
					break;
				}
				case 4:
				{
					if (choice == 1)
					{
						cout << "Pikachu uses Thunder.\n\n";
					}
					else if (choice == 2)
					{
						cout << "Bulbasaur uses Seed Bomb.\n\n";
					}
					else if (choice == 3)
					{
						cout << "Charmander uses Dragon Rage.\n\n";
					}
					else
					{
						cout << "Squirtle uses Rapid Spin.\n\n";
					}
					(*Player1).move4(*Player2);
					break;
				}
				case 5:
				{
					if (potion_count_p1 > 0)
					{
						if (choice == 1)
						{
							cout << "Pikachu uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
						}
						else if (choice == 2)
						{
							cout << "Bulbasaur uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
						}
						else if (choice == 3)
						{
							cout << "Charmander uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
						}
						else
						{
							cout << "Squirtle uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
						}
						(*Player1).Potion();
						potion_count_p1--;
						break;
					}
					else
					{
						cout << "You've run out of potion!.\n\n";
						break;
					}
				}
				}
			}
			else
			{
				if (choice == 1)
				{
					cout << "Sorry, your Pikachu is still unable to move. You miss a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player1).m_Conscious = true;
						cout << "Your Pikachu has recovered and is once again ready for battle in the next round!\n";
					}
				}
				else if (choice == 2)
				{
					cout << "Sorry, your Bulbasaur is still unable to move. You miss a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player1).m_Conscious = true;
						cout << "Your Bulbasaur has recovered and is once again ready for battle in the next round!\n";
					}
				}
				else if (choice == 3)
				{
					cout << "Sorry, your Charmander is still unable to move. You miss a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player1).m_Conscious = true;
						cout << "Your Charmander has recovered and is once again ready for battle in the next round!\n";
					}
				}
				else
				{
					cout << "Sorry, your Squirtle is still unable to move. You miss a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player1).m_Conscious = true;
						cout << "Your Squirtle has recovered and is once again ready for battle in the next round!\n";
					}
				}
			}

			if (((*Player2).m_Health) > 0 && ((*Player2).m_Conscious))
			{
				cout << "You've made your move. Now, it's Gary's turn!\n\n";

				if ((*Player2).m_Health <= 20 && (potion_count_p2 != 0) && (potion_count_p2 - (MAX_ROUND - g_round)*(MAX_POTION/MAX_ROUND) > 0))
				{
					if (compchoice == 1)
					{
						cout << "Pikachu uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
					}
					else if (compchoice == 2)
					{
						cout << "Bulbasaur uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
					}
					else if (compchoice == 3)
					{
						cout << "Charmander uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
					}
					else
					{
						cout << "Squirtle uses Potion. Health replenished by " << POTION_STR << " HP.\n\n";
					}
					(*Player2).Potion();
					potion_count_p2--;
				}
				else
				{
					srand(time(0));
					int retaliate = ((rand() % 4) + 1);
					switch (retaliate)
					{
					case 1:
					{
						if (compchoice == 1)
						{
							cout << "Pikachu uses Electric Shock.\n\n";
						}
						else if (compchoice == 2)
						{
							cout << "Bulbasaur uses Vine Whip.\n\n";
						}
						else if (compchoice == 3)
						{
							cout << "Charmander uses Scratch.\n\n";
						}
						else
						{
							cout << "Squirtle uses Tackle.\n\n";
						}
						(*Player2).move1(*Player1);
						break;
					}
					case 2:
					{
						if (compchoice == 1)
						{
							cout << "Pikachu uses Quick Attack.\n\n";
						}
						else if (compchoice == 2)
						{
							cout << "Bulbasaur uses Poison Powder.\n\n";
						}
						else if (compchoice == 3)
						{
							cout << "Charmander uses Amber.\n\n";
						}
						else
						{
							cout << "Squirtle uses Water Gun.\n\n";
						}
						(*Player2).move2(*Player1);
						break;
					}
					case 3:
					{
						if (compchoice == 1)
						{
							cout << "Pikachu uses Thunder Shock.\n\n";
						}
						else if (compchoice == 2)
						{
							cout << "Bulbasaur uses Razor Leaf.\n\n";
						}
						else if (compchoice == 3)
						{
							cout << "Charmander uses Flame Burst.\n\n";
						}
						else
						{
							cout << "Squirtle uses Bubble.\n\n";
						}
						(*Player2).move3(*Player1);
						break;
					}
					case 4:
					{
						if (compchoice == 1)
						{
							cout << "Pikachu uses Thunder.\n\n";
						}
						else if (compchoice == 2)
						{
							cout << "Bulbasaur uses Seed Bomb.\n\n";
						}
						else if (compchoice == 3)
						{
							cout << "Charmander uses Dragon Rage.\n\n";
						}
						else
						{
							cout << "Squirtle uses Rapid Spin.\n\n";
						}
						(*Player2).move4(*Player1);
						break;
					}
					}
				}
			}
			else if (!(*Player2).m_Conscious)
			{
				if (compchoice == 1)
				{
					cout << "Gary's Pikachu is unable to move. Gary misses a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player2).m_Conscious = true;
						cout << "Pikachu has recovered and is once again ready for battle in the next round!\n";
					}
				}
				else if (compchoice == 2)
				{
					cout << "Gary's Bulbasaur is unable to move. Gary misses a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player2).m_Conscious = true;
						cout << "Bulbasaur has recovered and is once again ready for battle in the next round!\n";
					}
				}
				else if (compchoice == 3)
				{
					cout << "Gary's Charmander is unable to move. Gary misses a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player2).m_Conscious = true;
						cout << "Charmander has recovered and is once again ready for battle in the next round!\n";
					}
				}
				else
				{
					cout << "Gary's Squirtle is unable to move. Gary misses a turn.\n";
					srand(time(0));
					if (rand() % RECOVER_FACTOR != 0)
					{
						(*Player2).m_Conscious = true;
						cout << "Squirtle has recovered and is once again ready for battle in the next round!\n";
					}
				}
			}
			else
			{
				if (compchoice == 1)
				{
					cout << "Congratulations! You've defeated Gary and his Pikachu in this round.\n";
				}
				else if (compchoice == 2)
				{
					cout << "Congratulations! You've defeated Gary and his Bulbasaur in this round.\n";
				}
				else if (compchoice == 3)
				{
					cout << "Congratulations! You've defeated Gary and his Charmander in this round.\n";
				}
				else
				{
					cout << "Congratulations! You've defeated Gary and his Squirtle in this round.\n";
				}
				cout << "Your " << PokemonName(choice) << "'s remaining health is " << (*Player1).m_Health << ".\n\n";
				player1_win++;
			}
		}

		if ((*Player1).m_Health <= 0)
		{
			if (choice == 1)
			{
				cout << "Your Pikachu has fainted. Game Over!\n";
				cout << "Better luck next time.\n";
			}
			else if (choice == 2)
			{
				cout << "Your Bulbasaur has fainted. Game Over!\n";
				cout << "Better luck next time.\n";
			}
			else if (choice == 3)
			{
				cout << "Your Charmander has fainted. Game Over!\n";
				cout << "Better luck next time.\n";
			}
			else
			{
				cout << "Your Squirtle has fainted. Game Over!\n";
				cout << "Better luck next time.\n";
			}
			player2_win++;
		}

		fout << "Round " << g_round << " Summary: \n";
		fout << player_name << " used a " << PokemonName(choice) << endl;
		fout << "Gary used a " << PokemonName(compchoice) << endl;
		fout << player_name << " wins: " << player1_win << endl;
		fout << "Gary wins: " << player2_win << "\n\n";

		if ((g_round == MAX_ROUND && (player1_win > player2_win)) || (player1_win >= ((MAX_ROUND / 2) + 1)))
		{
			fout << "The grand winner is..." << player_name << "! \n\n\n\n";
			cout << "The grand winner is..." << player_name << "! \n\n";
		}
		else if ((g_round == MAX_ROUND && (player1_win < player2_win)) || (player2_win >= (MAX_ROUND/2)+1))
		{
			fout << player_name << " got beaten by Gary in this Pokemon Battle...\n\n\n\n";
			cout << player_name << " got beaten by Gary in this Pokemon Battle...\n\n\n\n";
		}

		g_round++;

		if (g_round <= MAX_ROUND && (player1_win < (MAX_ROUND/2)+1) && (player2_win < (MAX_ROUND/2)+1))
		{
			cout << "Please select a pokemon from the following: \n";
			cout << "1 - Pikachu\n";
			cout << "2 - Bulbasaur\n";
			cout << "3 - Charmander\n";
			cout << "4 - Squirtle\n";
			cout << "Otherwise, if you would like to take a break from Pokemon Battle, please press 5 to leave the game.\n";
			cin >> choice;
		}
	}
	cout << "Hope you had fun with Pokemon Battle. Please play again soon!\n\n";

	fout.close();

    return 0;
}


Pokemon* PokemonSelect(Pikachu& Pika, Bulbasaur& Bulba, Charmander& Charma, Squirtle& Squirt, int choice)
{
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		cout << "You have entered an invalid choice. Please choose again: ";
		cin >> choice;
	}
	if (choice == 1)
	{
		Pikachu* pPika = &Pika;
		return pPika;
	}
	else if (choice == 2)
	{
		Bulbasaur* pBulba = &Bulba;
		return pBulba;
	}
	else if (choice == 3)
	{
		Charmander* pCharma = &Charma;
		return pCharma;
	}
	else
	{
		Squirtle* pSquirt = &Squirt;
		return pSquirt;
	}
}

string PokemonName(int choice)
{
	if (choice== 1)
	{
		return "Pikachu";
	}
	else if (choice == 2)
	{
		return "Bulbasaur";
	}
	else if (choice == 3)
	{
		return "Charmander";
	}
	else
	{
		return "Squirtle";
	}
}

void new_line()
{
	char symbol;
	do
	{
		cin.get(symbol);
	} while (symbol != '\n');
}