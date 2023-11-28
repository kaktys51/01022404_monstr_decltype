#include <iostream>
#include <string>
#include <vector>
#include <utility>


using namespace std;

template <typename Tp>
class Monstr
{
protected:
	enum MobType
	{
		Ork,
		Troll,
		Zombie,
		Goblin
	};
	Tp type = static_cast<Tp>(Ork);
	string name;

	int health;
	int attack;
	int attack_speed;
	int agility;
public:
	Monstr(): name("default"), health(1), attack(1), attack_speed(100), agility(1){}
	Monstr(Tp _type, string _name, int _health, int _attack, int _attack_speed, int _agility) : name(_name), health(_health), attack(_attack), attack_speed(_attack_speed), agility(_agility) 
	{ 
		if (_type > static_cast<Tp>(Goblin) || _type < static_cast<Tp>(Ork))
		{
			cout << "Invalid Monster \"Type\"! \n Your monster type set to default " << endl;
			type = static_cast<Tp>(Ork);
		}
		else type = _type;
	}
	Monstr(const Monstr& a) : type(a.type), name(a.name), health(a.health), attack(a.attack), attack_speed(a.attack_speed), agility(a.agility) {} // конструктор копирования
	Monstr(Monstr&& a) noexcept : type(move(a.type)), name(move(a.name)), health(move(a.health)), attack(move(a.attack)), attack_speed(move(a.attack_speed)), agility(move(a.agility)) { a.name = "default"; } // конструктор перемещения
	string getType()
	{
		switch (type)
		{
		case static_cast<Tp>(Ork):
			return "Ork";
		case static_cast<Tp>(Troll):
			return "Troll";
		case static_cast<Tp>(Zombie):
			return "Zombie";
		case static_cast<Tp>(Goblin):
			return "Goblin";
		
		default:
			break;
		}
	}
	void printStats()
	{
		cout << "Type: " << getType() << endl;
		cout << "Name: " << name << endl;
		cout << "Health: " << health << endl;
		cout << "Attack: " << attack<< endl;
		cout << "Attack speed: " << attack_speed<< endl;
		cout << "Agillity: " << agility << endl;
		cout << endl;
	}

	void intName(string _name) { name = _name; }

	Monstr& operator=(const Monstr& a)
	{
		if (&a == this)return *this;

		type = a.type;
		name = a.name;
		health = a.health;
		attack = a.attack;
		attack_speed = a.attack_speed;
		agility = a.agility;
		return *this;
	}
	Monstr& operator=(Monstr&& a) noexcept
	{
		if (&a == this)return *this;

		type = move(a.type);
		name = move(a.name);
		health = move(a.health);
		attack = move(a.attack);
		attack_speed = move(a.attack_speed);
		agility = move(a.agility);
		return *this;
	}
	bool operator==(const Monstr& a) const
	{
		return (type == a.type &&
				name == a.name &&
				health == a.health &&
				attack == a.attack &&
				attack_speed == a.attack_speed &&
				agility == a.agility);
	}


};

int main()
{
	Monstr<int> defo(0, "Ork", 85, 25, 150, 290);					//образцы стандартных типов монстров
	Monstr<int> deft(1, "Troll", 30, 9, 300, 500);
	Monstr<int> defz(2, "Zombie", 60, 15, 180, 320);
	Monstr<int> defg(2, "Goblin", 55, 12, 200, 300);

	Monstr<int> norz(2, "North Zombie", 80, 15, 200, 400);

	auto atzom = Monstr<int>{ 2, "Auto Zombie", 60, 15, 180, 320 };  //создания типом auto

	decltype(defg) decgob = defg;								//создания типом decltype

	decgob.intName("Decl Goblin");

	decgob.printStats();
	norz.printStats();
	atzom.printStats();

	return 0;
}