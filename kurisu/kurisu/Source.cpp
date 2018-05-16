#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string> 



using namespace std;
// declaring function for hit power
//int power( int str, int def);

int command;


class character
{
public:
	character();
	//~character();
	string name;
	float str;
	float def;
	float hp;   // hit points
	float regen;    // hp regen amount
	float roll;     // for random value
	float ouch;     // amount of attack damage
	float getAttack(character& opponent);
	float getHeal(void);
	void setRegen(float reg);
	bool IsAlive() const;
	//void setHeal(float healAmt);

private:


};

character::character()
{
	str = rand() % 30 + 5;
	def = rand() % 30 + 5;
	hp = 100;
	//Output to check the constructor is running properly
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
	//defines the magnitude/power of attack
	//function shows how much damage is inflicted


	// ouch is how much damage is done
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
		cout << "CRITICAL HIT!!" << endl;
	}

	opponent.hp -= ouch;
	cout << "After this attack the opponent has " << opponent.hp << "HP Left." << endl;
	return ouch;

}

float character::getHeal()
{
	//this is what happens when you chose to heal
	regen = rand() % 20 + 3;
	cout << "regen value= " << regen << ".\n";
	hp += regen;
	return regen;
}
/*character::~character()
{
str = 0;
def = 0;
hp = 0;
// Output to check the destructor is running properly
cout << "Character has been destroyed\n";
} */


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

	//Output name and stats to the user 
	cout << "\nYour name is: " << user.name << endl;
	cout << "here are your statistics: \n"
		<< "strength:   " << user.str << endl
		<< "Defense:    " << user.def << endl
		<< "hp:     " << user.hp << endl;

	cout << "oh no an oppenent appeared!!!\n";
	cout << "you will have to fight him!" << endl << endl;

	cout << "opponent's hp: 100" << endl;


	while (user.IsAlive() && computer.IsAlive())
	{
		cout << "Str: " << user.str << "\t"
			<< "Def: " << user.def << "\t"
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

		} //end switch
	}
	cout << "Wow you are truly an epic adventurer! However your adventure has only just begun >:)" << endl;
	return 0;
}
