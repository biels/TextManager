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
	a1.triarText("{W13}");
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

TEST(ActionHandler, DISABLED_FrasesXY){
	Context& c = a1.exposeContext();
	a1.triarText("{ugly meanings}");
	ASSERT_TRUE(c.existsChosenText());

	testing::internal::CaptureStdout();
	a1.frases(2, 3);
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("fault") != string::npos);
	EXPECT_TRUE(output.find("cultivated") != string::npos);
	EXPECT_FALSE(output.find("all") != string::npos);
	EXPECT_TRUE(output.find("2") != string::npos);
	EXPECT_TRUE(output.find("3") != string::npos);
	EXPECT_FALSE(output.find("4") != string::npos);
	EXPECT_FALSE(output.find("1") != string::npos);
	EXPECT_FALSE(output.find("Books") != string::npos);

	testing::internal::CaptureStdout();
	a1.frases(8, 8);
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("8") != string::npos);
}

TEST(ActionHandler, FrasesExpr_Soft){
	Context& c = a1.exposeContext();
	a1.afegirText("T", "Biel Simon",  "Sentence0 word0 word1. Sentence1 word0 word1 word2. Sentence2 word0.");
	a1.triarText("{T}");
	ASSERT_TRUE(c.existsChosenText());

	a1.frasesExpressio("({Sentence1} & {Sentence0})"); // S1


	a1.frasesExpressio("({Sentence1} | {Sentence0})"); // S1
	a1.frasesExpressio("({Sentence1} & {Sentence1})"); // S1

	a1.frasesExpressio("(({word2} | {word1}) & {word0})"); //S0 & S1
}

TEST(ActionHandler, DISABLED_FrasesExpr){
	Context& c = a1.exposeContext();
	a1.afegirText("Where the wild things are", "Maurice Sendak", "The night Max wore his wolf suit and made mischief of one kind and another. That very night in his room a forest grew and grew. An ocean tumbled by with a private boat for Max and he sailed off. When he came to the place where the wild things are they roared their terrible roars and rolled their eyes. Max tamed them with the magic trick of staring into their yellow eyes without blinking once. They made him king of all wild things.");
	a1.triarText("{eyes another roars}");
	ASSERT_TRUE(c.existsChosenText());

	a1.frasesExpressio("(({night wolf} | {When}) & {And})");

	testing::internal::CaptureStdout();
	a1.frasesExpressio("(({night wolf} | {When}) & {And})");
	output = testing::internal::GetCapturedStdout();
	EXPECT_FALSE(output.find("1") != string::npos)<< output;
	EXPECT_FALSE(output.find("4") != string::npos);

	testing::internal::CaptureStdout();
	a1.frasesExpressio("(({night wolf} | {When}) & {and})");
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("1") != string::npos)<< output;
	EXPECT_TRUE(output.find("4") != string::npos);
	EXPECT_FALSE(output.find("2") != string::npos);

	testing::internal::CaptureStdout();
	a1.frasesExpressio("({king} | {roars eyes})");
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("4") != string::npos)<< output;
	EXPECT_TRUE(output.find("6") != string::npos);
	EXPECT_FALSE(output.find("3") != string::npos);

	testing::internal::CaptureStdout();
	a1.frasesExpressio("(({tamed} | {mischief}) | {king wild})");
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("1") != string::npos) << output;
	EXPECT_TRUE(output.find("5") != string::npos);
	EXPECT_TRUE(output.find("6") != string::npos);
	EXPECT_FALSE(output.find("2") != string::npos);
}
TEST(ActionHandler, FrequencyTable){

}



