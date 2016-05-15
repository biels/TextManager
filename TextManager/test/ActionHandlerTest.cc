#include "gtest/gtest.h"
#include "../src/Logic/Actions/ActionHandler.h"
using namespace std;
TEST(AH, AfegirText){
	ActionHandler a;
	testing::internal::CaptureStdout();
	a.afegirText(
			"L\'illa del tresor",
			"Mark Twain",
			"Good friends, good books, and a sleepy conscience: this is the ideal life.");
	//a.textos();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(output.find("Text afegit") != std::string::npos);
}
