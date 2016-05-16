#include "gtest/gtest.h"
#include "../src/Logic/Actions/Context.h"
#include "../src/Logic/Data/AuthorSet.h"


TEST(Context, AuthorSet){
	Context c;
	Author sampleauthor = c.getAs().addNew();
	ASSERT_TRUE(c.getAs().exists(sampleauthor.getId())) << " Falied to create author (author does not exist)";
	//const char* sname = "Name";
	const char* slastName = "LastName";
	sampleauthor.setName("Name");
	sampleauthor.setLastName(slastName);
	Author recovered = c.getAs().get(sampleauthor.getId());
	ASSERT_TRUE(recovered.getName() == "Name") << " Data persistence error: " << sampleauthor.getName() << recovered.getName();

}
