#pragma once
#include "template.h"
#include <string>
#include "Film.h"
#include<iostream>
using namespace std;

class Repo {
private:
	VectDinNewDeleteT <Film> filme;
	bool exist(const Film& f);
public:
	Repo() = default;
	Repo(const Repo& r) = delete;

	void store(const Film& f);

	void delete_r(const Film& f);

	void update(const int& id, const string& titlu);

	Film find(const int& id) const;

	const VectDinNewDeleteT<Film>& getAll() const noexcept;

	~Repo() = default;
};

class RepoException {
	string msg;
public:
	RepoException(string m) :msg{m}{}
	friend ostream& operator<<(ostream& out, const RepoException& ex);
	string getMsg() {
		return msg;
	}
};

ostream& operator<<(ostream& out, const RepoException& ex);
