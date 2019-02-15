#include <iostream>
#include <string>
#include "calc.h"
using namespace std;
int main()
{
	int a;
	int b;
	int c;
	calc myCalc = new calc();
	
	cout << "Enter value for A \n";
	cin >> a;
	cout << "Enter value for B \n";
	cin >> b;
	cout << "Enter value for C \n";
	cin >> c;
	
	myCalc.calculate(a, b, c);

}

