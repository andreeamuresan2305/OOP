#include "teste_repo.h"
#include "Repository.h"
#include <sstream>
#include <assert.h>
#include <string.h>
void testAdauga() {
	Repo rep;
	rep.store(Film{ 1, "Divergent", "Actiune", 2014, "Shailene Woodley" });
	assert(rep.getAll().size() == 1);
	assert(rep.find(1).getId() == 1);

	rep.store(Film{ 2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	assert(rep.getAll().size() == 2);

	//nu pot adauga 2 cu acelasi tip si specie
	try {
		rep.store(Film{ 1, "Divergent", "Actiune", 2014, "Shailene Woodley" }); assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

	rep.store(Film{ 12, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 3, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 4, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 5, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 6, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 7, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 8, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 9, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 10, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
}

void testCauta() {
	Repo rep;
	rep.store(Film{ 2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 1, "Divergent", "Actiune", 2014, "Shailene Woodley" });

	auto p = rep.find(1);
	assert(p.getId() == 1);

	//arunca exceptie daca nu gaseste
	try {
		rep.find(3);assert(false);
	}
	catch (RepoException& e) {
		stringstream os;
		os << e;
		assert(os.str().find("exista") >=0);

	}
}

void testDelete() {
	Repo rep;
	rep.store(Film{ 2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 1, "Divergent", "Actiune", 2014, "Shailene Woodley" });

	rep.delete_r(Film{ 2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });

	//arunca exceptie daca nu gaseste
	try {
		rep.find(2);assert(false);
	}
	catch (RepoException&) {assert(true);
	}
}

void testUpdate() {
	Repo rep;
	rep.store(Film{ 2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" });
	rep.store(Film{ 1, "Divergent", "Actiune", 2014, "Shailene Woodley" });

	rep.update(1, "Divergen");

	//arunca exceptie daca nu gaseste
	try {
		rep.find(4);assert(false);
	}
	catch (RepoException&) {assert(true);
	}
}


void testeRepo() {
	testAdauga();
	testCauta();
	testDelete();
	testUpdate();
}