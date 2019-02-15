/**
*	@file Main.h
* 	@author Levi Clark
*	@date 2015.20.15
*
*/


#include <iostream>
#include "StackInterface.h"
#include "Stack.h"
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"
#include "Node.h"
#include "AnimalPen.h"
#include <stdexcept>
#include <string>
#include "PreconditionViolationException.h"
using namespace std;

int main()
{
	AnimalPen* myPen = new AnimalPen();
	
	char repeat = 'n';
	int input;
	double gallons;
	double totalGal = 0;
	int eggs;
	int totalEggs = 0;
	void printMenu();
	void goodbyeMessage(const FarmAnimal& animal);
	
	//keeps adding animals until the user says 'n'
	while(repeat != 'y')
	{
		printMenu();
		cin >> input;
		
		if(input == 1)
		{
		Cow* cow = new Cow;
		cout<< "How many gallons of milk did this cow produce?: \n";
		cin>> gallons;
		cow->setMilkProduced(gallons);
		totalGal = gallons + totalGal;
		myPen->addAnimal(cow);
		
		
		}
		else if(input ==  2)
		{
			Chicken* chicken = new Chicken;
			
			myPen->addAnimal(chicken);
			cout<< "Add an eggless chicken to the pen? OK. You're the boss. \n";
		
		}
		
		else if(input == 3)
		{
			CyberChicken* cyberChicken = new CyberChicken;
			cout<< "How many eggs did this CyberChicken produce?: \n";
			cin>> eggs;
		
			cyberChicken->setCyberEggs(eggs);
			totalEggs =eggs + totalEggs;
			myPen->addAnimal(cyberChicken);
		
		
		}
		else if(input <1 || input >3)
		{
			cout << "Sorry, please enter a value between 1-3: \n";
		}
		
		cout << "Done adding animals? (y/n): \n";
		cin >> repeat;
		
		
	}
	
	
	//while the pen has something in it, it will print the animal at the top of the stack, what it produced, and its sound. it will then pop()/delete that animal and move to the next one.
	
	while(!myPen->isPenEmpty())
	{
		cout<< "Releasing all Animals!! \n";
		cout << "---------------------------------------------------------- \n";
		FarmAnimal* farm = myPen->peekAtNextAnimal();
		
		//it it's a cow, it displays the cow's sound and gallons of milk produced.
		if(farm->getName() == "Cow")
		{
			cout << "This cow produced " << static_cast<Cow*>(farm)->getMilkProduced()<< " gallons of milk \n";
			goodbyeMessage(*farm);
			cout << "Cow destructor called\n";
			cout << endl;
		}
		
		//if its a chicken, it displays the chicken's sound.
		else if(farm->getName() == "Chicken")
		{
			cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help? \n";
			goodbyeMessage(*farm);
			cout << "Chicken destructor called \n";
			cout << endl;
		}
		
		//if its a cyberchicken, then it displays that cyberchicken's sound and eggs produced.
		else if(farm->getName() == "CyberChicken")
		{
			cout <<"This Cyber Chicken laid "<< static_cast<CyberChicken*>(farm)->getCyberEggs()<<" cyber eggs. Humanity is in trouble \n";
			goodbyeMessage(*farm);
			cout << "CyberChicken destructor called \n";
			
			cout << "Chicken destructor called \n";
			cout << endl;
			
		}
		//pops the top of the stack to move onto the next animal in the stack
		myPen->releaseAnimal();
		delete farm;
		
		
	}
	//displays final eggs and gallons of milk produced.
	cout << "Your farm produced " << totalGal << " gallons of milk and " << totalEggs << " eggs.";
	delete myPen;
	
}







void goodbyeMessage(const FarmAnimal& animal)
{
	std::cout << "Upon release the "<< animal.getName()<<" said " << animal.getSound()<<". \n";
}




void printMenu()
{

std::cout 	<<"\n\nSelect an animal to add to the pen: \n"
		<<"1.) Cow (produces milk) \n"
		<<"2.) Chicken (cannot lay eggs) \n"
		<<"3.) Cyber Chicken (seems dangerous, but lays eggs)\n"
		<<"--------------------------------------------------\n"
		<< "Enter choice: ";

}

