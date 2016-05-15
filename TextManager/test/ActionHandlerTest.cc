#include "gtest/gtest.h"
#include "../src/Logic/Actions/ActionHandler.h"

TEST(AH, All){
	ActionHandler a;
	a.afegirText("La pilota", "Mr Poato", "Good friends, good books, and a sleepy conscience: this is the ideal life.");
}
