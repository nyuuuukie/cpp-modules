#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	srand(time(0));

	// Dynamically allocated memory
	IMateriaSource* src = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	Character bob3;
	{
		Character bob4 = bob3;
	}

	Character *bob5 = new Character(bob3);
	delete bob5;

	// Classes should work properly with a stack allocated memory
	{
		IMateriaSource* src = new MateriaSource();
		Ice ice;
		Cure cure;
		src->learnMateria(&ice);
		src->learnMateria(&cure);

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}
