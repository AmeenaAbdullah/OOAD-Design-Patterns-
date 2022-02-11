/**************************************************************
*         AMEENA ABDULLAH           BSEF19M032
****************************************************************/
#include<iostream>
using namespace std;
/*COMMON INTERFACE APPS*/
class apps
{
public:
	 virtual void  login()=0;
};
/*webApp implementation*/
class webapps:public apps 
{
public:
	void  login() {
		cout << "WEB APP Succesfully login" << endl;
	}
};
/*MobileApp implementation*/
class mobileapps:public apps 
{
public:
	void  login() {
		cout << "MOBILE APP Succesfully login" << endl;
	}
};


/** * Base factory class. Note that "factory" is merely a role 
for the class. It * should have some core business logic which needs 
different products to be * created. */
class softwareHouse
{
public:
   void appview() {
	   apps* app= createApp();
	   app->login();
	}
   virtual apps* createApp()=0;
};
/** * Subclasses will override this method in order
	to create specific apps * objects. */
class mobile:public softwareHouse {
public:
	apps* createApp() {
		return new mobileapps();
	}
};

/** * Subclasses will override this method in order
    to create specific apps * objects. */
class web :public softwareHouse {
public:
	apps* createApp() {
		return  new webapps();
	}
};
//main function
int main() {

	softwareHouse* sh=NULL;
	int choice=0;
	cout << "Enter 1 to login WebApp OR Enter 2 to login mobile app:";
	cin >> choice;
	if (choice == 1) {
		web w;
		sh = &w;
	}
	else if (choice == 2) {
		mobile m;
		sh = &m;
	}
	if (choice == 1 || choice == 2)
	sh->appview();
	cout << " :(    Invalid choice";
	return 0;
}
