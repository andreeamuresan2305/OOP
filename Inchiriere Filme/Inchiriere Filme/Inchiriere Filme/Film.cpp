#include "Film.h"
#include <assert.h>

bool compareId(const Film& f1, const Film& f2)
{
	return f1.getId() == f2.getId();
}

bool cmpTitlu(const Film& f1, const Film& f2)
{
	return f1.getTitlu() < f2.getTitlu();
}

bool cmpActor(const Film& f1, const Film& f2)
{
	return f1.getActor() > f2.getActor();
}

void testFilm()
{
	Film f1 = { 1, "Divergent", "Actiune", 2014, "Shailene Woodley" };
	Film f2 = { 2, "The Hunger Games", "Actiune", 2013, "Jennifer Lawrence" };
	assert(f1.getId() == 1);
	assert(f1.getTitlu() == "Divergent");
	assert(f1.getGen() == "Actiune");
	assert(f1.getAn() == 2014);
	assert(f1.getActor() == "Shailene Woodley");
	assert(compareId(f1, f2) == false);
	assert(f1.setAn(2015) == 2015);
}