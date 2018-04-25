// Inheritance, encapsulation, initiliser inheritance

#include <iostream>
#include "Animal.h"
#include "Dog.h"

using namespace std;

int main() {

	Animal *pa_bob = new Animal();
	pa_bob->setName("Bob");
	string my_name = pa_bob->getName();
	int my_id = pa_bob->getID();
	cout << "Name: " << my_name << " | ID #: " << my_id << endl;

	Dog *pa_dog = new Dog();
	pa_dog->setName("Alice");
	cout << "Name: " << pa_dog->getName() << " | ID #: " << pa_dog->getID()
			<< endl;
	pa_dog->fetch();
	cout << "I have " << pa_dog->getLegs() << " legs" << endl;

	Puppy *pa_puppy = new Puppy();
	pa_puppy->setName("Eve");
	pa_puppy->lookCute();
	cout << "My name is " << pa_puppy->getName()
			<< ", I am a puppy. Like dogs, I also have " << pa_puppy->getLegs()
			<< " legs." << endl;

	delete pa_bob;
	pa_bob = NULL;
	delete pa_dog;
	pa_dog = NULL;
	delete pa_puppy;
	pa_puppy = NULL;

	return 0;
}
