#include<iostream>
#include <chrono>
#include <thread>

//#include <windows.h>
//#pragma comment(lib, "Winmm.lib")

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// PARTS OF PLAYER /////////////////////////////////////////
/////////////////////////////// CLASSES MAKING COMPOSITION/AGGREGATION WITH PLAYER ////////////////////

class GUN {
private:
	string _gunName;
	int _shootingPowerPerBullet;
	int _ammoCapacity;
public:
	GUN() {
		_gunName = "None";
		_shootingPowerPerBullet = 0;
		_ammoCapacity = 0;
	}
	GUN(string gn, int sppb, int acap) {
		_gunName = gn;
		_shootingPowerPerBullet = sppb;
		_ammoCapacity = acap;
	}
	void setGunName(string gn) {
		_gunName = gn;
	}
	void setShootingPowerPB(int sppb) {
		_shootingPowerPerBullet = sppb;
	}
	void setAmmoCapacity(int acap) {
		_ammoCapacity = acap;
	}
	string getGunName() {
		return _gunName;
	}
	int getshootingPowerPerBullet() {
		return _shootingPowerPerBullet;
	}
	int getAmmoCapacity() {
		return _ammoCapacity;
	}

};

class MEDIKIT
{
	int medkitpower;
	int numberofmedi;
public:
	MEDIKIT()
	{
		medkitpower = 0;
		numberofmedi = 0;
	}
	MEDIKIT(int mip, int nom)
	{
		medkitpower = mip;
		numberofmedi = nom;
	}
	void setmedipower(int mip)
	{
		medkitpower = mip;
	}
	int getmedipower()
	{
		return medkitpower;
	}
	void setnumberofmedi(int nom)
	{
		numberofmedi = nom;
	}
	int getnumberofmedi()
	{
		return numberofmedi;
	}

};
class HEALTH
{
	int healthpower;
	int ep;
public:
	HEALTH()
	{
		healthpower = 0;
		ep = 0;
	}
	HEALTH(int hp, int ep)
	{
		healthpower = hp;
		this->ep = ep;

	}
	void sethealthpower(int hp)
	{
		healthpower = hp;
	}
	int gethealthpower()
	{
		return healthpower;
	}
	void setep(int)
	{
		this->ep = ep;
	}
	int getep()
	{
		return ep;
	}
};
class BACKPACK
{
	int level;
	string color;
public:
	BACKPACK()
	{
		level = 0;
		color = "None";
	}
	BACKPACK(int lv, string clr)
	{
		level = lv;
		color = clr;
	}
	void setlevel(int lv)
	{
		level = lv;
	}
	int getlevel()
	{
		return level;

	}
	void setcolor(string clr)
	{
		color = clr;

	}
	string setcolor()
	{
		return color;
	}
};

class VEHICLE
{
private:
	string vType;
	string name;
	string color;
public:
	VEHICLE()
	{
		vType = "";
	}
	VEHICLE(string vType, string vn, string vClr) //Peramatrized Constructor
	{
		name = vn;
		color = vClr;
	}
	void drive()
	{

	}
	void setVehicleName(string n)
	{
		name = n;
	}
	void setVehicleColor(string vClr)
	{
		color = vClr;
	}
	string getVehicleName()
	{
		return name;
	}
	string getVehicleColor()
	{
		return color;
	}
};

class PET
{
private:
	int level;
	string petName;
public:
	PET()
	{
		level = 0;
		petName = "";
	}
	PET(int l , string pName)
	{
		petName = pName;
		level = l;
	}
	void setPetName(string pName)
	{
		petName = pName;
	}
	string getName()
	{
		return petName;
	}
	void setLevel(int l) {
		level = l;
	}
	int getLevel() {
		return level;
	}
	void walk()
	{

	}
	void ability()
	{

	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////  PLAYER ////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class PLAYER {
private:
	string playerName;
	int numberOfKills;

public:
	//OBJECTS AS DATAMEMBERS IN PLAYER, due to composition of player with classes of these object
	
	string nameBackup_0;
	string nameBackup_1;

	PLAYER()
	{
		playerName = "";
		numberOfKills = 0;
	}

	//PURE VIRTUAL FUNCTIONS OF PLAYER........
	virtual void walk() = 0;
	virtual void mediKit() = 0;
	virtual void shoot(PLAYER*, int) = 0;
	virtual void throughGernade(PLAYER*) = 0;

	//virtual friend istream& operator>> (ostream& is, const PLAYER* obj) {}
	//virtual friend ostream& operator<< (ostream& os, const PLAYER* obj) {}

	void startGame() {

		int i = 0;

		cout << "                                   INITIATING GAME" << endl;
		cout << "                            _______________________________" << endl;

		string loader[3] = { ":::::::::",":::::::::::::::",":::::::::::::::::::::::::::::::" };
		while (i <= 2) {
			cout << "                            ";
			cout << loader[i] << endl;
			i++;
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << endl << "                            _______________________________" << endl<<endl;

	}

	void setPlayerName(string pn) {
		playerName = pn;
	}
	//This is made virtual because this function is inherited to both (YOU & ENEMY)  
	//                                                                  |       |     
	//                                                               ROBOT    SOLIDER    and then goes to (GAMERESULT)
	virtual string getPlayerName() {
		return playerName;
	}
	void setNumberOfKills(int nok) {
		numberOfKills = nok;
	}
	//This is made virtual because this function is inherited to both (YOU & ENEMY)  
	//                                                                  |       |     
	//                                                               ROBOT    SOLIDER    and then goes to (GAMERESULT)
	virtual int getNumberOfKills() {

		return numberOfKills;
	}
	virtual void printGameResult(PLAYER* p1, PLAYER* p2)
	{}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// ENEMY ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

class ENEMY : public PLAYER {

public:

	int numberOfKillsfor_enemy;

	ENEMY() {
		/*cout << " XXXXXXXX--------         GET Ready the Enemy Is On You        ------- XXXXXXX" << endl<<endl;
		this_thread::sleep_for(chrono::seconds(1));*/
		numberOfKillsfor_enemy = 0;
	}
	void walk() {
		cout<<"Enemy Is Walking........." << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	
	virtual ~ENEMY() {}
};


class SOLIDER : public ENEMY {

	GUN _gun;
	MEDIKIT _midikit;
	BACKPACK _backpack;
	HEALTH hp;
	VEHICLE* vchl;
	PET pet;
public:
	/*GUN g = getGun();
	MEDIKIT m = getMedikit();
	BACKPACK b = getBackpack();
	HEALTH h = getHealth();
	PET p = getPet();*/
	

	SOLIDER() : _gun(), _midikit(), _backpack(), hp(), pet()
		// This initializing list will call the Default Constructors of 
	   // classes Making COMPOSITION with PLAYER 
	{

		setPlayerName("None");
		setNumberOfKills(0);
	}

	//Peramatrized Constructor 
	SOLIDER(string pname, string gname, int sppb, int acap, int mip, int nom, int blv,
		string bclr, int healthp, int ep, int l, string petName)
		: _gun(gname, sppb, acap), _midikit(mip, nom), _backpack(blv, bclr), hp(healthp, ep), pet(l, petName)

		// This initializing list will call the Parametrized Constructors of 
	   // classes Making COMPOSITION with PLAYER 
	{
		cout << "/////////////////////////////  ENEMY ON THE BATTLEFIELD \\\\\\\\\\\\\\\\\\\\\\\\\\\\ " << endl << endl;
		this_thread::sleep_for(chrono::seconds(1));

		
		this_thread::sleep_for(chrono::seconds(1));
		setPlayerName(pname);
		setNumberOfKills(0);

		cout << "                      Player Name  : " << getPlayerName() << endl;
		cout << "                      Player has Health  : " << hp.gethealthpower() << endl;
		cout << "                      Player equiped Gun  : " << _gun.getGunName() << endl;
		cout << "                      Player has pet  : " << pet.getName() << endl;
	}

	

	/*friend ostream& operator<< (ostream& os, const PLAYER* obj)
	{

		os << "                      Player Name  : " << obj->playerName << endl;
		os << "                      Player has Health  : " << obj->gethealthpower() << endl;
		os << "                      Player equiped Gun  : " << obj->getGunName() << endl;
		os << "                      Player has pet  : " << obj->getName() << endl;
		return os;
	}*/

	void mediKit() {
		if (hp.gethealthpower() < 100) {

			if (_midikit.getnumberofmedi() >= 1)
			{
				hp.sethealthpower(hp.gethealthpower() + 50);
				if (hp.gethealthpower() > 100) {
					hp.sethealthpower(100);
				}
			}
			else
				cout << "                           XXXXXXXX........You are out of Medikits....XXXXXXXXXXX" << endl;
		}
		else {
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Can't Heal Because, Your Health Is Full." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << "| Medikits  ------------------ " << _midikit.getnumberofmedi() << " Left " << endl;
	}
	}
	
	void shoot(PLAYER* obj, int numberOfBullets) {
		this_thread::sleep_for(chrono::seconds(1));
		int damage = numberOfBullets * _gun.getshootingPowerPerBullet();
		cout << "-----    ENEMY shooted " << numberOfBullets << " bullets on YOU   -------" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << "-----    YOU GOT " << damage << " OF Damage   -------" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		if ((damage) >= hp.gethealthpower()) {


			cout << "        xxxxx------------   YOU (ROBOT ) KILLED  ------------XXXXX" << endl;
			setNumberOfKills(getNumberOfKills() + 1);
			nameBackup_1 = getPlayerName();
			delete[]obj;
		}
		else
		{
			hp.sethealthpower(hp.gethealthpower() - damage);
			cout << "YOUR health is now  ------ " << hp.gethealthpower() << " hp" << endl;
		}

	}
	void throughGernade(PLAYER* obj) {

		cout << "xxxxxxxxx           Solider threw a hand gernade on You           xxxxxxxx" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		hp.sethealthpower(0);
		cout << "        xxxxx------------   You (Robot ) Where KILLED  ------------XXXXX" << endl;
		delete[]obj;
	}
	
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////// YOU ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

class YOU : public PLAYER
{
public:
	//Getting all the objects of classes making composition with PLAYER abstract class
	
	int numberOfKillsfor_robot;

	YOU() {
		
		/*cout << "|______________________________________________________________________________________" << endl;
		cout << " ----------------------- YOU ARE ABOUT TO FACE YOUR ENEMY ---------------------------" << endl;
		this_thread::sleep_for(chrono::seconds(1));*/
		numberOfKillsfor_robot = 0;
	}

	void walk() {
		cout << "YOU are Walking........." << endl;
	}
};

class ROBOT : public YOU
{
	GUN _gun;
	MEDIKIT _midikit;
	BACKPACK _backpack;
	HEALTH hp;
	VEHICLE* vchl;
	PET pet;
public:
	
	//Default Constructor Of ROBOT
	ROBOT() : _gun(), _midikit(), _backpack(), hp(), pet()
		// This initializing list will call the Default Constructors of 
	   // classes Making COMPOSITION with PLAYER 
	{

		setPlayerName("None");
		setNumberOfKills(0);
	}

	//Peramatrized Constructor 
	ROBOT(string pname, string gname, int sppb, int acap, int mip, int nom, int blv,
		string bclr, int healthp, int ep, int l, string petName)
		: _gun(gname, sppb, acap), _midikit(mip, nom), _backpack(blv, bclr), hp(healthp, ep), pet(l, petName)

		// This initializing list will call the Parametrized Constructors of 
	   // classes Making COMPOSITION with PLAYER 
	{
		cout << "/////////////////////////////  YOU ARE ON THE BATTLEFIELD \\\\\\\\\\\\\\\\\\\\\\\\\\\\ " << endl << endl;
		this_thread::sleep_for(chrono::seconds(1));
		setPlayerName(pname);
		setNumberOfKills(0);
		cout << "                      Player Name  : " << getPlayerName() << endl;
		cout << "                      Player has Health  : " << hp.gethealthpower() << endl;
		cout << "                      Player equiped Gun  : " << _gun.getGunName() << endl;
		cout << "                      Player has pet  : " << pet.getName() << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	/*friend ostream& operator<< (ostream& os, const PLAYER* obj)
	{

		os << "                      Player Name  : " << obj->playerName << endl;
		os << "                      Player has Health  : " << obj->gethealthpower() << endl;
		os << "                      Player equiped Gun  : " << obj->getGunName() << endl;
		os << "                      Player has pet  : " << obj->getName() << endl;
		return os;
	}*/

	int health = hp.gethealthpower();
	void mediKit() {
		if (health < 100) {

			if (_midikit.getnumberofmedi() >= 1)
			{
				hp.sethealthpower(hp.gethealthpower() + 50);
				if (hp.gethealthpower() > 100) {
					hp.sethealthpower(100);
				}

			}
			else
				cout << "                           XXXXXXXX........You are out of Medikits....XXXXXXXXXXX" << endl;
		}
		
		else
		{
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Can't Heal Because, Your Health Is Full." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << "|---------------------------- " << _midikit.getnumberofmedi() << " Left " << endl;
	}
	}
	void shoot(PLAYER*e, int numberOfBullets) {
		this_thread::sleep_for(chrono::seconds(1));
		int damage = numberOfBullets * _gun.getshootingPowerPerBullet();
		cout << "-----    You shooted " << numberOfBullets << " bullets on enemy   -------" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << "-----    ENEMY GOT " << damage << " OF Damage   -------" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		if ((damage) >= hp.gethealthpower()) {

			
			cout << "        xxxxx------------   ENEMY (SOLIDER ) KILLED  ------------XXXXX" << endl;
			setNumberOfKills(getNumberOfKills() + 1);
			nameBackup_0 = getPlayerName();
			delete []e;
		}
		else
		{
			hp.sethealthpower(   hp.gethealthpower() - damage );
			cout << "Enemy health is now  ------ " << hp.gethealthpower() << " hp" << endl;
		}

	}
	void throughGernade(PLAYER*e) {

		cout << "xxxxxxxxx           Robot threw a hand gernade on Solider           xxxxxxxx" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		hp.sethealthpower(0);
		cout << "        xxxxx------------   ENEMY (SOLIDER ) KILLED  ------------XXXXX" << endl;
		delete[]e;
	}
	
};

class GAMERESULT : public ROBOT, public SOLIDER {

public:
	GAMERESULT() {



	}
	//void printGameResult(PLAYER* p1, PLAYER* p2, PLAYER* p3, PLAYER* p4)
	void printGameResult(PLAYER* p1, PLAYER* p2)
	{
		cout << endl << endl;
		cout << "                            -----------------------------------" << std::endl;
		cout << "                            |            Game Results         |" << std::endl;
		cout << "                            -----------------------------------" << std::endl;
		cout << "                            | Player  | Kills |" << std::endl;
		cout << "                            |---------|-------|" << std::endl;
		cout << "                            | " << p1->nameBackup_0 << " |   " << p1->getNumberOfKills() << "   |" << std::endl;
		cout << "                            | " << p2->nameBackup_1 << " |   " << p2->getNumberOfKills() << "   |" << std::endl;
		/*cout << "                            | " << p3->nameBackup_1 << " |   " << p3->getNumberOfKills() << "   |" << std::endl;
		cout << "                            | " << p4->nameBackup_1 << " |   " << p4->getNumberOfKills() << "   |" << std::endl;*/
		cout << "                            -----------------------------------" << std::endl;

	}


};


	////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////   DRIVER   //////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

	YOU* y[1];
	y[0] = new ROBOT("SAM", "M82B", 50, 30, 50, 2, 3, "White", 100, 200, 2, "Tiger");

	ENEMY* p[1];
	p[0] = new SOLIDER("Devil", "AUG", 30, 30, 50, 2, 3, "Blue", 100, 200, 1, "Wolf");
	/*p[2] = new SOLIDER("Mark", "SMG", 30, 30, 50, 2, 3, "Blue", 100, 200, 2, "Monster");
	p[3] = new SOLIDER("Dany", "GROZA", 50, 30, 50, 2, 3, "Blue", 100, 200,2,  "Python");*/

	//for (int i = 0; i < 4; i++) {
	//	cout << p[i] << endl<<endl;
	//}

	y[0]->startGame();

	y[0]->shoot(p[0], 1);
	p[0]->mediKit();

	p[0]->shoot(y[0], 2);
	y[0]->mediKit();

	//y[0]->shoot(p[0], 2);

	y[0]->throughGernade(p[0]);


	GAMERESULT g;
	//g.printGameResult(y[0], p[0], p[2], p[3]);
	g.printGameResult(y[0], p[0]);
	return 0;
	}
