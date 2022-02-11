/**************************************************************************
*         AMEENA ABDULLAH           BSEF19M032           ABSTRACT FACTORY 
***************************************************************************/
#include<iostream>
using namespace std;
/*COMMON INTERFACE SPOONS*/
class spoons
{
public:
	virtual void  showVariety() = 0;
};
/*MARBLE SET implementation*/
class marblesetSpoons :public spoons
{
public:
	void  showVariety() {
		cout << "Marble set: SPOON" << endl;
	}
};
/*BOON CHINA SET implementation */
class boon_chinaSetSpoons :public spoons
{
public:
	void  showVariety() {
		cout << "Bone china set:SPOON" << endl;
	}
};
/*COMMON INTERFACE PLATES*/
class plates
{
public:
	virtual void  showVariety() = 0;
};
/*MARBLE SET implementation*/
class marblesetPlate :public plates
{
public:
	void  showVariety() {
	cout << "Marble set:PLATES" << endl;
	}
};
/*BOON CHINA SET implementation */
class boon_chinaSetPlates :public plates
{
public:
	void  showVariety() {
		cout << "boon china set:PLATES" << endl;
	}
};
/** * dinner set is abstract factory class.  */
class dinnerSets
{
public:
	virtual spoons* createSpoons()=0;
	virtual plates* createPlates()=0;
};
class Marble :public dinnerSets {
public:
	 spoons* createSpoons() {
		return  new marblesetSpoons();
	}
	 plates* createPlates() {
		 return new marblesetPlate();
	 }
};
class Boonchina :public dinnerSets {
public:
	spoons* createSpoons() {
		return new boon_chinaSetSpoons();
	}
	plates* createPlates() {
		return new boon_chinaSetPlates();
	}
};
class Applications {
private:
	spoons* sp;
	plates* pl;
public:
	Applications(dinnerSets* d_Set) {
	
	sp=d_Set->createSpoons();
	pl=d_Set->createPlates();
	}
	void showVariety() {
		sp->showVariety();
		pl->showVariety();
	}
};
//main function
int main() {
    dinnerSets* d;
	Applications* app=NULL;
	int choice = 0;
	cout << "Enter choice 1 for bone china" << endl;
	cout << "Enter choice 2 for marble " << endl;
	cin >> choice;

	if (choice == 1) {
		cout << "**********BONE CHINA FACTORY**********" << endl;
		d = new Boonchina();
		app = new Applications(d);
		}
	else if (choice == 2) {
		cout << "**********MARBLE FACTORY**********" << endl;
		d = new Marble();
		app = new Applications(d);
	}
	app->showVariety();
}
