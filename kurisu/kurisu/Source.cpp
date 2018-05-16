#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string> 

using namespace std;

int command;


class character
{
public:
	character();
	string name;
	float str;
	float def;
	float hp; 
	float regen;   
	float roll;   
	float ouch;    
	float getAttack(character& opponent);
	float getHeal(void);
	void setRegen(float reg);
	bool IsAlive() const;

private:


};

character::character()
{
	str = rand() % 30 + 5;
	def = rand() % 30 + 5;
	hp = 100;
	cout << "Character has been created.\n";
}

bool character::IsAlive() const
{
	return hp > 0.0f;
}

void character::setRegen(float reg)
{
	regen = reg;
}


float character::getAttack(character& opponent)
{


	roll = rand() % 20 + 1; 

	if (roll <= 11)
	{
		ouch = str - (def / 2);
	}

	else if ((roll <= 17) && (roll >= 12))
	{
		ouch = (str * 2) - (def / 2);
	}

	else if ((roll <= 20) && (roll >= 18))
	{
		ouch = (str * 3) - (def / 2);
	}

	opponent.hp -= ouch;
	cout << "After this attack the opponent has " << opponent.hp << " hp left." << endl;
	return ouch;

}

float character::getHeal()
{
	regen = rand() % 20 + 3;
	cout << "regen value= " << regen << ".\n";
	hp += regen;
	return regen;
}


int main()
{
	srand(time_t(NULL));
	cout << "Welcome to Cool Adventure Game!" << endl;
	character user, computer;
	computer.name = "Bestial Geoff\n";

	float attackDamage;
	float hpAdded;

	user.setRegen(42.0);

	cout << "Please enter a name for your character:\n";
	cin >> user.name;

	cout << "\nYour name is: " << user.name << endl;
	cout << "here are your statistics: \n"
		<< "strength:   " << user.str << endl
		<< "defense:    " << user.def << endl
		<< "hp:     " << user.hp << endl;

	cout << "oh no an oppenent appeared!!!\n";
	cout << "you will have to fight him!" << endl << endl;

	cout << "opponent's hp: 100" << endl;


	while (user.IsAlive() && computer.IsAlive())
	{
		cout << "str: " << user.str << "\t"
			<< "def: " << user.def << "\t"
			<< "hp: " << user.hp << "\t"
			<< "\n";

		cout << "what would you like to do: heal (1), attack(2).\n";
		cin >> command;

		switch (command)
		{
		case 1:

			hpAdded = user.getHeal();

			cout << "" << user.name << " has regenerated " << hpAdded << " hp.\n";
			break;

		case 2:

			attackDamage = user.getAttack(computer);

			cout << "" << user.name << " did " << attackDamage << " damage to the opponent!\n";

			break;

		default:
			cout << "Please enter a valid choice!";

		}
		
	}
	cout << "Wow you are truly an epic adventurer! However your adventure has only just begun >:)" << endl;
	return 0;
}
