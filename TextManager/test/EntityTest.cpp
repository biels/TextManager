#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "TestHeader.h"

using namespace std;

Context c2;
TEST(Entities, Author){
	Author& a1 = c2.getAs().addNew();
	a1.setName("Oscar");
	a1.setLastName("Wilde");
	ASSERT_TRUE(a1.getName() == "Oscar");
	ASSERT_TRUE(a1.getLastName() == "Wilde");
	std::string initials = a1.getInitials();
	EXPECT_TRUE(initials == "OW")<< " Returned: " << initials;

	Author& a2 = c2.getAs().addNew();
	a2.setFullName("Oscar Wilde");
	ASSERT_TRUE(a2.getName() == "Oscar");
	ASSERT_TRUE(a2.getLastName() == "Wilde");
	EXPECT_TRUE(a2.getInitials() == "OW");
	//Now authors 1 and 2 exist
	ASSERT_TRUE(c2.getAs().exists(1));
	ASSERT_TRUE(c2.getAs().exists(2));
}

TEST(Entities, Text){


	Text& t1 = c2.getTs().addNew();
	const char* s_title = "Sample text title";
	t1.setTitle(s_title);
	const char* s_content =
			"Are there any tools out there which analyse my code and point out bottle-necks for the compiler? Or can one somehow profile the compiler running on my code? This would be really nice, because sometimes I have the impression, that I spent too much time staring at the compiler console.";
	t1.setContent(s_content);
	t1.setAuthor(c2.getAs().get(1));
	//testing::internal::CaptureStdout();
	//t1.printContent();
	//EXPECT_EQ(s_content, testing::internal::GetCapturedStdout()) << "Content was not printed as expected";

	EXPECT_FALSE(t1.matchesWordListAnywhere("{Some text words there}", c2));
	EXPECT_TRUE(t1.matchesWordListAnywhere("{Are which}", c2));
	EXPECT_FALSE(t1.matchesWordListAnywhere("{rodona quadrat triangle}", c2));
	EXPECT_FALSE(t1.matchesWordListAnywhere("{Sample strangeword}", c2));
	EXPECT_TRUE(t1.matchesWordListAnywhere("{Sample text}", c2));
	EXPECT_TRUE(t1.matchesWordListAnywhere("{title}", c2));
	EXPECT_TRUE(t1.matchesWordListAnywhere("{code}", c2));
	EXPECT_TRUE(t1.matchesWordListAnywhere("{profile}", c2));
	EXPECT_FALSE(t1.matchesWordListAnywhere("{Oscar somebody}", c2));
	EXPECT_TRUE(t1.matchesWordListAnywhere("{Wilde}", c2));


}
//void getSentenceListMatchingExpression(string expr, vector<int>& match) const;
//
//void getSentenceListMatchingExpressionEf(string expr, vector<int>& match, vector<string>& cond, bool& c_op, bool root) const;
//
//void getSentenceListMatchingWordListInContext(vector<int>& match, const vector<string>& cond, bool c_op, bool m_op) const;
//
//void checkSentenceForCondition(int i, const vector<string>& cond, bool c_op,
//		vector<string>& remaining) const;
TEST(Text, AlgebraicExpression){
	Text& t1 = c2.getTs().addNew();
	t1.setTitle("T");
	t1.setAuthorByFullName("Biel Simon", c2);
	t1.setContent("Sentence0 word0. Sentence1 word0 word1. Sentence2 word0 word1 word2. Sentence3.");
	c2.setChosenTextId(t1.getId());

}
TEST(Text, getSentenceListMatchingExpression){
	Text& t1 = c2.getChosenText();
	vector<int> match;

	t1.getSentenceListMatchingExpression("({Sentence2} & {Sentence0 word0})", match);
	EXPECT_EQ(0, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({Sentence2} & ({Sentence3} | {Sentence0}))", match);
	EXPECT_EQ(0, match.size());match.clear();

	t1.getSentenceListMatchingExpression("(({Sentence3} | {Sentence0}) & {Sentence2})", match);
	EXPECT_EQ(0, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({Sentence2} & ({Sentence1} | {Sentence0}))", match);
	EXPECT_EQ(0, match.size());match.clear();

	t1.getSentenceListMatchingExpression("(({Sentence3} | {Sentence3}) | ({Sentence3} | {Sentence0 word0}))", match);
	EXPECT_EQ(2, match.size());match.clear();

	t1.getSentenceListMatchingExpression("(({Sentence3} | {Sentence3}) | ({Sentence3} | {Sentence3}))", match);
	EXPECT_EQ(1, match.size());match.clear();

	t1.getSentenceListMatchingExpression("(({Sentence3} & {Sentence3}) | ({Sentence3} & {Sentence3}))", match);
	EXPECT_EQ(1, match.size());match.clear();

	t1.getSentenceListMatchingExpression("((({word0} & {word2}) | {Sentence3 word1}) | ({word2} | {none}))", match);
	EXPECT_EQ(1, match.size());match.clear();

	t1.getSentenceListMatchingExpression("(({word0} & ({word0} & ({word0} & ({word0} & {word1})))) | ((({word0} & {word1}) & ({word0} & {word1})) & (({word0} & {word1}) & {word1}))", match);
	EXPECT_EQ(2, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({nothing} & {word1 word0})", match);
	EXPECT_EQ(0, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word0} | {word0 word1})", match);
	EXPECT_EQ(3, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word2} & {word1 word0})", match);
	EXPECT_EQ(1, match.size());match.clear();

	t1.getSentenceListMatchingExpression("((({word0} | {word1}) | {Sentence2}) & {word2})", match);
	EXPECT_EQ(1, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word0 word1 word2} & {Sentence2})", match);
	EXPECT_EQ(1, match.size());match.clear();


	t1.getSentenceListMatchingExpression("(({word0} & {word1}) | ({word0} & {word1}))", match);
	EXPECT_EQ(2, match.size());match.clear(); // 0 1 2

	t1.getSentenceListMatchingExpression("(({word0} | {word1}) | {Sentence2})", match);
	EXPECT_EQ(3, match.size());match.clear(); // 0 1 2

	t1.getSentenceListMatchingExpression("(({word0} & {word1}) | {Sentence2})", match);
	EXPECT_EQ(2, match.size());match.clear(); // 0 1 2

	t1.getSentenceListMatchingExpression("(({word0} & {word1}) | {Sentence2})", match);
	EXPECT_EQ(2, match.size());match.clear(); // 1 2

	t1.getSentenceListMatchingExpression("({word1} | {word2})", match);
	EXPECT_EQ(2, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word1} & {word2})", match); //X
	EXPECT_EQ(1, match.size());match.clear();

	t1.getSentenceListMatchingExpression("{Sentence2 word0 word1}", match);
	EXPECT_EQ(1, match.size()); match.clear();

	t1.getSentenceListMatchingExpression("{Sentence2 Sentence3}", match);
	EXPECT_EQ(0, match.size()); match.clear();

	t1.getSentenceListMatchingExpression("{Sentence3}", match);
	EXPECT_EQ(1, match.size()); match.clear();

	t1.getSentenceListMatchingExpression("{word1 word2}", match);
	EXPECT_EQ(1, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word1} | {word2})", match);
	EXPECT_EQ(2, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word2} | {word1 word0})", match);
	EXPECT_EQ(2, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word0} | {Sentence3})", match);
	EXPECT_EQ(4, match.size());match.clear();

	t1.getSentenceListMatchingExpression("({word0 word1 word2 other} & {Sentence2})", match);
	EXPECT_EQ(0, match.size());match.clear();

}

TEST(Text, DISABLED_getSentenceListMatchingWordListInContext){
	Text& t1 = c2.getChosenText();
	vector<int> match;
	vector<string> cond;

	cond.push_back("word0");
	cond.push_back("word2");
	t1.getSentenceListMatchingWordListInContext(match, cond, false, false); //fails for c_op = false
	EXPECT_EQ(3, match.size());match.clear();cond.clear();

	cond.push_back("word1");
	t1.getSentenceListMatchingWordListInContext(match, cond, true, false); // last is reduce or expand
	EXPECT_EQ(2, match.size());match.clear();cond.clear();

	cond.push_back("word1");
	cond.push_back("word2");
	t1.getSentenceListMatchingWordListInContext(match, cond, true, false);
	EXPECT_EQ(1, match.size());match.clear();cond.clear();



	cond.push_back("word0");
	cond.push_back("Sentence3");
	t1.getSentenceListMatchingWordListInContext(match, cond, false, false);
	EXPECT_EQ(4, match.size());match.clear();cond.clear();

	cond.push_back("word0");
	cond.push_back("word2");
	t1.getSentenceListMatchingWordListInContext(match, cond, false, false);
	EXPECT_EQ(3, match.size());match.clear();cond.clear();
}

TEST(Text, checkSentenceForCondition){
	Text& t1 = c2.getChosenText();
	vector<string> cond;
	cond.push_back("word0");
	cond.push_back("word2");
	vector<string> remaining(cond);
	t1.checkSentenceForCondition(2, cond, false, remaining);
	EXPECT_LT(remaining.size(), 2);


	remaining = cond;
	t1.checkSentenceForCondition(0, cond, true, remaining);
	EXPECT_EQ(1, remaining.size());

}
