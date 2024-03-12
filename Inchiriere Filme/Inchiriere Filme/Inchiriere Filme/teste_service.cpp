#include "teste_service.h"
#include "Service.h"
#include <assert.h>
void testAdaugaCtr() {
	Repo rep;
	Validator val;
	Service ctr{ rep,val };
	ctr.store_srv( 1, "Divergent", "Actiune", 2014, "Shailene Woodley");
	assert(ctr.getAll().size() == 1);

	//adaug ceva invalid
	try {
		ctr.store_srv(-1, "", "", -2, "");assert(false);
	}
	catch (ValidateException&) {assert(true);
	}
	//incerc sa adaug ceva ce existadeja
	try {
		ctr.store_srv(1, "Divergent", "Actiune", 2014, "Shailene Woodley");assert(false);
	}
	catch (RepoException&) {assert(true);
	}
}

void testFind() {
	Repo rep;
	Validator val;
	Service ctr{ rep,val };
	ctr.store_srv(1, "Divergent", "Actiune", 2014, "Shailene Woodley");
	ctr.store_srv(2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence");
	assert(ctr.find_srv(1).getId() == 1);
}

void testUpdate_srv() {
	Repo rep;
	Validator val;
	Service ctr{ rep,val };
	ctr.store_srv(1, "Divergent", "Actiune", 2014, "Shailene Woodley");
	ctr.store_srv(2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence");
	ctr.update_srv(1, "ddd");
	assert(ctr.getAll()[0].getTitlu() == "ddd");
}


void testFiltrare() {
	Repo rep;
	Validator val;
	Service ctr{ rep,val };
	ctr.store_srv(1, "Divergent", "Actiune", 2014, "Shailene Woodley");
	ctr.store_srv(2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence");
	assert(ctr.filtrareAn(2013,2015).size() == 2);
}

void testFiltrare2() {
	Repo rep;
	Validator val;
	Service ctr{ rep,val };
	ctr.store_srv(1, "Divergent", "Actiune", 2014, "Shailene Woodley");
	ctr.store_srv(2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence");
	string titlu = "Divergent";
	assert(ctr.filtrareTitlu(titlu).size() == 1);
	ctr.delete_srv(2);
}

void testSortare() {
	Repo rep;
	Validator val;
	Service ctr{ rep,val };
	ctr.store_srv(1, "Divergent", "Actiune", 2014, "Shailene Woodley");
	ctr.store_srv(5, "Diverget", "Actiun", 2014, "Shailene Wodley");
	ctr.store_srv(2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence");

	auto firstP = ctr.sortByTitlu()[0];
	assert(firstP.getTitlu() == "Divergent");

	firstP = ctr.sortByActor()[0];
	assert(firstP.getActor() == "Shailene Woodley");

	firstP = ctr.sortByAnGen()[0];
	assert(firstP.getAn() == 2013);

}

void testCtr() {
	testAdaugaCtr();
	testFiltrare();
	testFiltrare2();
	testSortare();
	testFind();
	testUpdate_srv();
}
