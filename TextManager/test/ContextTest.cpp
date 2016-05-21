#include "gtest/gtest.h"
#include "TestHeader.h"

Context c1;

TEST(Context, BasicConsistency){
	EXPECT_FALSE(c1.existsChosenText());
	EXPECT_NO_THROW(c1.getAs());
	EXPECT_NO_THROW(c1.getTs());
	EXPECT_NO_THROW(c1.getQs());
}

TEST(Context, IsolatedAuthorCreation){

	Author& a1 = c1.getAs().addNew();
	//c.getAs().get(sampleauthor.getId()).setName("Name");

	ASSERT_TRUE(c1.getAs().exists(a1.getId())) << " Falied to create author (author does not exist)";
	//const char* sname = "Name";
	const char* slastName = "LastName";
	a1.setName("Name");
	a1.setLastName(slastName);
	Author recovered = c1.getAs().get(a1.getId());
	ASSERT_TRUE(recovered.getName() == "Name") << " Data persistence error: " << a1.getName() << recovered.getName();

}

TEST(Context, TextCreation){
	Context c1;
	//Check creation and data persistence
	Text& t1 = c1.getTs().addNew();
	EXPECT_TRUE(t1.getId() == 1);

	t1.setTitle("Sample title");
	t1.setContent("W1 w2 w3 w4. W5 w6 w7.");

	t1.setAuthorByFullName("Sample Name", c1);

	Text& t1_r = c1.getTs().get(t1.getId());
	EXPECT_TRUE(t1_r.getTitle() == t1.getTitle() && t1_r.getId() == t1.getId())  << " Data persistence error";
	EXPECT_EQ(1, t1.getAuthor(c1).getId()) << "Author in text persitence error";
	EXPECT_EQ(&t1, &t1_r);

	//Select text
	c1.setChosenTextId(t1.getId());

	//Check id autoincrement
	Text& t2 = c1.getTs().addNew();
	EXPECT_TRUE(t2.getId() == t1.getId() + 1);
}


TEST(Context, QuoteCreation){ //FIX QS! //Add function Quote& q = text.extractQuote
	Quote& q1 = c1.getQs().addNew();
	q1.setTextId(c1.getChosenTextId(), c1);
	ASSERT_EQ(1, q1.getId());
	//TODO Check creation and data persistence
}

