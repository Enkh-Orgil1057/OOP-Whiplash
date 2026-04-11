#include <iostream>
using namespace std;

class  employee​
{​
 protected:​
      char name [13];​
      int basicpay;​
      int allowance;​

 public:​
 	void showdata ();​
		employee() ;​
		employee(char n[13], int b, int a) ;​

} ;​

employee::employee() ​

{​

cout << “\nCalling base default constructor” ;​

strcpy(name, “0” ) ;​

basicpay = 0 ;​

allowance = 0 ;​

cout << “\nExiting base default constructor” ;​

}

employee::employee(char n[], int b, int a) ​

{​

cout<<“\nCalling base constructor(char n[], int, int)” ;​

strcpy(name, n ) ;​

basicpay = b ;​

allowance = a ;​

cout << “\nExiting base constructor (char n[13], int,int)” ;​

}

class engineer : public employee​

{​

 public :​

  void showdata ( )​

  {​

   employee :: showdata ();​

  }​

  engineer() ;​

  engineer(char n[13], int b, int a) ;​

};

engineer::engineer() ​

{​

cout << “\nCalling derived default constructor” ;​

strcpy(name, “1” ) ;​

basicpay = 1 ;​

allowance = 1 ;​

cout << “\nExiting derived default constructor” ;​

}

engineer::engineer(char n[], int b, int a) ​

{​

cout<<“\nCalling derived constructor (char n[],int,int)” ;​

strcpy(name, n ) ;​

basicpay = b ;​

allowance = a ;​

cout<<“\nExiting derived constructor (char n[],int,int)” ;​

}

void main ( )​

{​

engineer en ;​

heading () ;​

en.showdata () ;​

engineer en1(“George Bush”, 100, 100) ;​

en1.showdata () ;​

getch () ;
}
