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
	EXPECT_TRUE(output.find("Text afegit") != string::npos) << "No s'ha detectat \"Text afegit\"";
	ASSERT_NE(-1, c.getAs().findByFullName("Mark Twain"));

	a1.afegirText(
			"La humanidad en el 2050",
			"Mark Twain",
			"No se puede tener todo: una agricultura ecologica, una ganaderia extensiva, dejar los bosques como estan y comer carne como lo hacemos. Hay que elegir.");

	a1.afegirText(
			"The Picture of Dorian Gray",
			"Oscar Wilde",
			"Those who find ugly meanings in beautiful things are corrupt without being charming. This is a fault. Those who find beautiful meanings in beautiful things are the cultivated. For these there is hope. They are the elect to whom beautiful things mean only Beauty. There is no such thing as a moral or an immoral book. Books are well written, or badly written. That is all.");

	ASSERT_NE(-1, c.getAs().findByFullName("Oscar Wilde"));
	ASSERT_EQ(-1, c.getAs().findByFullName("Some Other"));
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

	ASSERT_NE(-1, c.getAs().findByFullName("Mark Twain"));

	a1.triarText("{humanidad agricultura comer elegir}");
	ASSERT_TRUE(c.existsChosenText());
	id = c.getChosenTextId();
	EXPECT_TRUE(c.getTs().exists(id));
	a1.eliminarText();
	ASSERT_FALSE(c.existsChosenText());
	ASSERT_FALSE(c.getTs().exists(id));

	ASSERT_EQ(-1, c.getAs().findByFullName("Mark Twain"));

	ASSERT_NE(-1, c.getAs().findByFullName("Oscar Wilde"));
}

TEST(ActionHandler, SubstitueixPer){
	Context& c = a1.exposeContext();
	a1.afegirText(
				"Wx Text",
				"The Replacer",
				"W1 w2 w3 w4 w5 w6 w7. W8 w9 w10 w11 w12. W13: w14, w15, w16.");
	a1.triarText("{W1 w2 w7}");
	ASSERT_TRUE(c.existsChosenText());
	a1.substitueix("w2", "aa");
	a1.triarText("{W1 w2 w7}");
	ASSERT_FALSE(c.existsChosenText());
	a1.triarText("{W1 aa w7}");
	ASSERT_TRUE(c.existsChosenText());
	a1.substitueix("w7", "bb");
	a1.substitueix("W13", "Cc");
	a1.substitueix("aa", "dd");
	a1.triarText("{W13}");
	ASSERT_FALSE(c.existsChosenText());
	a1.triarText("{dd bb Cc}");
	ASSERT_TRUE(c.existsChosenText());

}
