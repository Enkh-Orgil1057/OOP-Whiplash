#include <iostream>
using namespace std;

class  employee

{
 protected:
      char *name;

      int basicpay;

      int allowance;

 public:

 	void showdata(){
        cout << name << endl;
    }

		employee() ;

		employee(char n[13], int b, int a) ;

} ;

employee::employee()

{
cout<< "\nCalling base default constructor" ;

strcpy(name, "0" ) ;

basicpay = 0 ;

allowance = 0 ;

cout << "\nExiting base default constructor";
}

employee::employee(char n[], int b, int a) 

{

cout<<"\nCalling base constructor(char n[], int, int)" ;

strcpy(name, n ) ;

basicpay = b ;

allowance = a ;

cout << "\nExiting base constructor (char n[13], int,int)" ;

}

class engineer : public employee

{

 public :

  void showdata ( )

  {

   employee :: showdata();

  }

  engineer() ;

  engineer(char n[13], int b, int a) ;

};


engineer::engineer() : employee()

{

cout << "\nCalling derived default constructor" ;


cout << "\nExiting derived default constructor" ;

}

engineer::engineer(char n[], int b, int a) : employee(n, b, a)

{

cout<<"\nCalling derived constructor (char n[],int,int)" ;

cout<<"\nExiting derived constructor (char n[],int,int)" ;

}

int main ( )
{
    engineer en ;
    en.showdata() ;
    char name[5] = "Bat";
    engineer en1(name, 100, 100) ;
    en1.showdata();
    return 0;
}  
