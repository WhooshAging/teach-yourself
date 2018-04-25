#include "Animal.h"


void myShow(int const, char []);
void myShow2(int const, char *); // Actually same as above. Throws invalid redef error
void myShow(char (&)[50]); // CAREFUL &[] -> error, array of refs. (&)[] -> error, array of unknown bound!


int main() {

	{
		Animal cat("Bob");
		cat.speak();
	}
	// we killed Bob by putting the object inside braces
	// so Bob is now out-of-scope and ceases to exist :(

	Animal *ppig = new Animal("Babe");
	Animal *pdog = new Animal("Alice");

	pdog->speak(); // special syntax for a pointer. Replaces (*pdog).speak();
	delete pdog;
	pdog = NULL; // good practice to do the del and reassign together to prevent bugs

	delete pdog; // this should be fine after setting it to NULL

	ppig->speak();
	delete ppig; // Every new must have a matching delete or you get mem leaks!
	ppig = NULL;

	// creating arrays of ojects

	Animal::count = 0; // reset the count, since we've killed all old ojects and about to create more, new objetcs.
	int target = 26;
	char current_char = 'a';

	Animal *pAnimals = new Animal[target]; // create a bunch of Animal objects, as a pointer to start of the array
	for (int i = 0; i < target; i++, current_char++) { // chars are really ints, so we can incremenet to get next letter
		//loop over the array and set their name
		// need to convert char to str
		string animal_name(1, current_char);
		pAnimals[i].setName(animal_name);
	}

	for (int i = 0; i < target; i++) {
		pAnimals[i].speak();
	}

	delete[] pAnimals; // definitley don't forget [] when you want to delete a whole array of allcocated mem!
	pAnimals = NULL;

	cout << endl;
	cout << "Enough animals for now." << endl;
	cout << endl;

	char story[] = "Once upon a time there was a big, fat ganga tree.";
	int const N = sizeof(story);

	cout << "First myShow." << endl;
	myShow(N, story); // pointer to the array in disguise
	cout << endl;
	cout << "Second myShow." << endl;
	char *p_story = story; // Explicitly create the pointer to the array. Same as above.
	myShow2(N, p_story);
	cout << endl;
	cout << "Third myShow." << endl;
	myShow(story);

	return 0;
}




void myShow(int const NELEMENTS, char an_array[]) {
	// need to pass the size information as sizeof would give size of pointer
	// ie we are working with a pointer, not tthe object or a reference

	for (int i=0; i<NELEMENTS; i++) {
		cout << an_array[i] << flush;
	}
	cout << endl;
	return;
}
void myShow2(int const NELEMENTS, char *p_an_array) { // Actually same as above. Will throw invalid redef error.
	for (int i=0; i<NELEMENTS; i++, p_an_array++) {
		cout << *p_an_array << flush;
	}
	cout << endl;
	return;
}
void myShow(char (&an_array)[50]) { // CAREFUL &[] -> error, array of refs. (&)[] -> error, array of unknown bound!
	// haveing a reference is just like having the actual object
	// so sizeof returns as expected, and not the size of a pointer!
	for (int i=0; i<(int)sizeof(an_array);i++) {
		cout << an_array[i] << flush;
	}
	cout << endl;
	return;
}
