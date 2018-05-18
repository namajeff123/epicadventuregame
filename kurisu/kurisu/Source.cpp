#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string> 

using namespace std;

int command;
int command2;
int skillUpCommand;


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
	character user, computer;
	computer.name = "Bestial Geoff\n";

	float attackDamage;
	float hpAdded;

	user.setRegen(42.0);

	cout << "Please enter a name for your character:\n";
	cin >> user.name;
	string direction1;
	cout << "\nYour name is: " << user.name << endl;
	cout << "here are your statistics: \n"
		<< "strength:   " << user.str << endl
		<< "defense:    " << user.def << endl
		<< "hp:     " << user.hp << endl;
	cout << "Press any button to begin your adventure!" << endl;
	cout << "You spawn in the middle of the compsci club." << endl;
	cout << "You see a office to the north and a cave to the south" << endl;
	cout << "Enter 'office' if you want to go north. Enter 'cave' if you want to go south" << endl;
	cin >> direction1;

	cout << "oh no an oppenent appeared in the " << direction1 << "." << endl;
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
	cout << "You have earned a skill point! Type 1 to invest your skill point in strength.\n Type 2 if to invest in defense, type 3 to increase your max health." << endl;
	cin >> skillUpCommand;
	switch (skillUpCommand) {
	case 1:
		user.str += 1;
	case 2:
		user.def += 1;
	case 3:
		user.hp += 10;
	}
	cout << "str: " << user.str << "\t"
		<< "def: " << user.def << "\t"
		<< "hp: " << user.hp << "\t"
		<< "\n\n";
	string direction2;
	cout << "You see a fork in the hallway you can choose to go east or west" << endl;
	cin >> direction2;
	if (direction2 == "east") {
		cout << "You have transcended space and time and are now located in the delta quadrant upon a Borg cube. You see an ominous hallway to the north, you look behind you to the south and see a seemingly infinite number of drones." << endl;
	}
	else if(direction2 == "west"){
		cout << "Your choice has placed you aboard a Ferengi starship, not only does the ship smell unfamiliar but now you have fight off a greedy Ferengi in search of your\n gold-pressed latinum." << endl;
		cout << "Looks like you will have another epic encounter" << endl;
		cout << "what would you like to do: heal (1), attack(2).\n";
		cin >> command2;

		switch (command2)
		{
		case 1:

			hpAdded = user.getHeal();

			cout << "" << user.name << " has regenerated " << hpAdded << " hp.\n";
			break;

		case 2:

			attackDamage = user.getAttack(computer);

			cout << "" << user.name << " did " << attackDamage << " damage to the Ferengi miscreant!\n";

			break;

		default:
			cout << "Please enter a valid choice!";

		}
	}
	else {
		cout << "way to enter the wrong input you prob broke this game lmao" << endl;
	}
	return 0;
}
