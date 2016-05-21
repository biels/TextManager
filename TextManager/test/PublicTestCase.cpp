#include "gtest/gtest.h"
#include "../src/Logic/Actions/ActionHandler.h"
using namespace std;

TEST(FullTestCases, DISABLED_Public1){
	ActionHandler a;
	a.afegirText("The Picture of Dorian Gray", "Oscar Wilde", "Those who find ugly meanings in beautiful things are corrupt without being charming. This is a fault. Those who find beautiful meanings in beautiful things are the cultivated. For these there is hope. They are the elect to whom beautiful things mean only Beauty. There is no such thing as a moral or an immoral book. Books are well written, or badly written. That is all. ");
	a.afegirText("La ciencia. Su metodo y su filosofia", "Mario Bunge", "Por medio de la investigacion cientifica, el hombre ha alcanzado una reconstruccion conceptual del mundo que es cada vez mas amplia, profunda y exacta.");

	testing::internal::CaptureStdout();
	a.textos(); //
	string output = testing::internal::GetCapturedStdout();
	string e_1 = "Mario Bunge \"La ciencia. Su metodo y su filosofia\"\n"
			"Oscar Wilde \"The Picture of Dorian Gray\"\n";
	EXPECT_EQ(e_1, output);
}
