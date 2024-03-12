#include "Service.h"
#include <functional>
#include <algorithm>
using namespace std;

VectDinNewDeleteT<Film>Service::generalSort(bool(*maiMic)(const Film&, const Film&))
	{
		//Bubble sort
		VectDinNewDeleteT<Film> v{ r.getAll()};//facem o copie
		bool ok = false;
		while (ok == false)
		{
			ok = true;
			for (size_t i = 0; i < v.size() - 1; i++)
			{
				if (maiMic(v[i + 1], v[i]))
				{
					Film aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
					ok = false;
				}
			}
		}
		return v;
	}

VectDinNewDeleteT<Film> Service::filtreaza(function<bool(const Film&)> fct)const
{
	VectDinNewDeleteT<Film> rez;
	for (int i = 0;i<r.getAll().size();i++) {
		Film f = r.getAll().get(i);
		if (fct(f)) 
		{
			rez.push_back(f);
		}
	}
	return rez;
}

void Service::store_srv(const int id, const string t, const string g, const int a, const string ap)
{
	Film f{ id,t,g,a,ap };
	v.validate(f);
	r.store(f);
}

void Service::delete_srv(const int& id)
{
	Film film = r.find(id);
	r.delete_r(film);
}

void Service::update_srv(const int& id, const string& titlu)
{	
	r.update(id, titlu);
}

const VectDinNewDeleteT<Film>& Service::getAll() const noexcept
{
	return r.getAll();
}

Film Service::find_srv(const int& id) const 
{
	return r.find(id);
}

VectDinNewDeleteT<Film> Service::sortByTitlu()
{
	return generalSort(cmpTitlu);
}

VectDinNewDeleteT<Film> Service::sortByActor()
{
	return generalSort(cmpActor);
}

VectDinNewDeleteT<Film> Service::sortByAnGen()
{
	return generalSort([](const Film& f1, const Film& f2)
		{
			if (f1.getAn() == f2.getAn()) {
				return f1.getGen() < f2.getGen();
			}
	return f1.getAn() < f2.getAn();
		});
}

VectDinNewDeleteT<Film> Service::filtrareTitlu(string& titlu_cautat) const {
	return filtreaza([titlu_cautat](const Film& f)noexcept {
		return strcmp(f.getTitlu().c_str(), titlu_cautat.c_str()) == 0;
		});
}

VectDinNewDeleteT<Film> Service::filtrareAn(int an_min, int an_max) const {

	return filtreaza([=](const Film& f) noexcept {
		return f.getAn() >= an_min && f.getAn() <= an_max;
		});
}