#include "gtest/gtest.h"
#include "TestHeader.h"

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
