#pragma once
#include <string>
using std::string;

class Film {
private:
	int id;
	string titlu;
	string gen;
	int an;
	string actor;
public:
	Film() = default;
	Film(const int id, const string t, const string g, const int a, const string ap) :id{ id }, titlu{ t }, gen{ g }, an{ a }, actor{ ap } {};

	int getId() const {
		return id;
	}
	string getTitlu() const {
		return titlu;
	}
	string getGen() const {
		return gen;
	}
	int getAn() const {
		return an;
	}
	string getActor() const {
		return actor;
	}
	string setTitlu(string t) {
		this->titlu = t;
		return this->titlu;
	}
	string setGen(string g) {
		this->gen = g;
		return this->gen;
	}
	int setAn(int a) {
		this->an = a;
		return this->an;
	}
};

bool compareId(const Film& f1, const Film& f2);

bool cmpActor(const Film& f1, const Film& f2);

//bool cmpGen(const Film& f1, const Film& f2);

//bool cmpAn(const Film& f1, const Film& f2);

bool cmpTitlu(const Film& f1, const Film& f2);

inline bool operator==(const Film& lhs, const Film& rhs) { return compareId(lhs, rhs); }

void testFilm();