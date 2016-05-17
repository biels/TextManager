#include "gtest/gtest.h"
#include "../src/Logic/Entities/Author.h"
#include "../src/Logic/Entities/Quote.h"
#include "../src/Logic/Entities/Text.h"

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

