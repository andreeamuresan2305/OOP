#pragma once

#include "Film.h"
#include "Repository.h"
#include <string>
#include <vector>

#include <functional>
#include "validator.h"

using namespace std;

typedef bool(*MaiMicF)(const Film&, const Film&);

class Service {
	Repo& r;
	Validator& v;
	/*
	 Functie de sortare generala
	 maiMicF - functie care compara 2 Pet, verifica daca are loc relatia mai mare
			  - poate fi orice functe (in afara clasei) care respecta signatura (returneaza bool are 2 parametrii Pet)
			  - poate fi functie lambda (care nu capteaza nimic in capture list)
	 returneaza o lista sortata dupa criteriu dat ca paramatru
	*/
	VectDinNewDeleteT<Film> generalSort(bool(*maiMic)(const Film&, const Film&));
	/*
	Functie generala de filtrare
	fct - poate fi o functie
	fct - poate fi lambda, am folosit function<> pentru a permite si functii lambda care au ceva in capture list
	returneaza doar animalele care trec de filtru (fct(pet)==true)
	*/
    VectDinNewDeleteT<Film> filtreaza(function<bool(const Film&)> fct)const;

public:
	Service( Repo& r, Validator& v) noexcept:r{r},v{v}{}
	Service(const Service& s) = delete;
	const VectDinNewDeleteT<Film>& getAll() const noexcept;

	void store_srv(const int id, const string t, const string g, const int a, const string ap);
	void delete_srv(const int& id);
	void update_srv(const int& id, const string& titlu);
	Film find_srv(const int& id) const;
	VectDinNewDeleteT<Film> sortByTitlu();
	VectDinNewDeleteT<Film> sortByActor();
	VectDinNewDeleteT<Film> sortByAnGen();
	VectDinNewDeleteT<Film> filtrareTitlu(string& titlu_cautat) const;
	VectDinNewDeleteT<Film> filtrareAn(int an_min, int an_max) const;
};