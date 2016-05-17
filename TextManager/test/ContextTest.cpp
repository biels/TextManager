#include "gtest/gtest.h"
#include "../src/Logic/Actions/Context.h"
#include "../src/Logic/Data/AuthorSet.h"
#include "../src/Logic/Data/QuoteSet.h"
#include "../src/Logic/Data/TextSet.h"


TEST(Context, AuthorSet){
	Context c;
	Author& sampleauthor = c.getAs().addNew();
	//c.getAs().get(sampleauthor.getId()).setName("Name");

	ASSERT_TRUE(c.getAs().exists(sampleauthor.getId())) << " Falied to create author (author does not exist)";
	//const char* sname = "Name";
	const char* slastName = "LastName";
	sampleauthor.setName("Name");
	sampleauthor.setLastName(slastName);
	Author recovered = c.getAs().get(sampleauthor.getId());
	ASSERT_TRUE(recovered.getName() == "Name") << " Data persistence error: " << sampleauthor.getName() << recovered.getName();

}

TEST(Context, DISABLED_QuoteSet){ //FIX QS!
	Context c;
	//Quote& q1 = c.getQs().addNew();
	//ASSERT_TRUE(q1.getId() == 0);
	//TODO Check creation and data persistence
}

TEST(Context, DISABLED_TextSet){
	Context c;
	Text& t1 = c.getTs().addNew();
	ASSERT_TRUE(t1.getId() == 0);
	//TODO Check creation and data persistence
}
