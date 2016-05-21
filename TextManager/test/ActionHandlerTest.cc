#include "gtest/gtest.h"
#include "../src/Logic/Actions/ActionHandler.h"
using namespace std;
ActionHandler a1;
string output;
TEST(ActionHandler, AfegirText){
	Context& c = a1.exposeContext();

	testing::internal::CaptureStdout();
	a1.afegirText(
			"L\'illa del tresor",
			"Mark Twain",
			"Good friends, good books, and a sleepy conscience: this is the ideal life. ");
	//a.textos();
	output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(output.find("Text afegit") != string::npos) << "No s'ha detectat \"Text afegit\"";


}

TEST(ActionHandler, TriarText){
	testing::internal::CaptureStdout();
	a1.triarText("{del tresor}");
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Text triat") != string::npos);

	testing::internal::CaptureStdout();
	a1.triarText("{this will fail}");
	output = testing::internal::GetCapturedStdout();
	EXPECT_FALSE(output.find("Text triat") != string::npos);

	testing::internal::CaptureStdout();
	a1.triarText("{sleepy ideal Twain tresor}");
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Text triat") != string::npos);
}

TEST(ActionHandler, EliminarText){
	Context& c = a1.exposeContext();
	ASSERT_TRUE(c.existsChosenText());
	int id = c.getChosenTextId();
	EXPECT_TRUE(c.getTs().exists(id));
	a1.eliminarText();
	ASSERT_FALSE(c.existsChosenText());
	ASSERT_FALSE(c.getTs().exists(id));
}

TEST(ActionHandler, SubstitueixPer){

}
