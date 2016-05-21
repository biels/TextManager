#include "gtest/gtest.h"
#include "../src/Logic/Actions/ActionHandler.h"
using namespace std;
ActionHandler a1;
TEST(ActionHandler, AfegirText){

	testing::internal::CaptureStdout();
	a1.afegirText(
			"L\'illa del tresor",
			"Mark Twain",
			"Good friends, good books, and a sleepy conscience: this is the ideal life. ");
	//a.textos();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(output.find("Text afegit") != std::string::npos) << "No s'ha detectat \"Text afegit\"";

	a1.triarText("{illa tresor}");

}

