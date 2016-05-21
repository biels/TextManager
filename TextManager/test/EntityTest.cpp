#include "gtest/gtest.h"
#include "TestHeader.h"

TEST(Entities, Author){
	Author a1(0);
	a1.setName("Oscar");
	a1.setLastName("Wilde");
	ASSERT_TRUE(a1.getName() == "Oscar");
	ASSERT_TRUE(a1.getLastName() == "Wilde");
	std::string initials = a1.getInitials();
	ASSERT_TRUE(initials == "OW")<< " Returned: " << initials;

	Author a2(1);
	a2.setFullName("Oscar Wilde");
	ASSERT_TRUE(a2.getName() == "Oscar");
	ASSERT_TRUE(a2.getLastName() == "Wilde");
	ASSERT_TRUE(a2.getInitials() == "OW");
}

TEST(Entities, Text){
	Context c;

	Text t1(0);
	const char* s_title = "Sample text title";
	t1.setTitle(s_title);
	const char* s_content =
			"Are there any tools out there which analyse my code and point out bottle-necks for the compiler? Or can one somehow profile the compiler running on my code? This would be really nice, because sometimes I have the impression, that I spent too much time staring at the compiler console.";
	t1.setContent(s_content);

	testing::internal::CaptureStdout();
	t1.printContent();
	EXPECT_EQ(s_content, testing::internal::GetCapturedStdout()) << "Content was not printed as expected";
}
