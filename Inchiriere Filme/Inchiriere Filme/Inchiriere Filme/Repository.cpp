#include "Repository.h"

bool Repo::exist(const Film& f)
{
	try {
		find(f.getId());
		return true;
	}
	catch (RepoException&)
	{
		return false;}
}

void Repo::store(const Film& f)
{
	if (exist(f)) throw RepoException("Exista deja film cu id: " + to_string(f.getId()));
	filme.push_back(f);
}

void Repo::delete_r(const Film& f)
{
	if (!exist(f)) throw RepoException("Nu exista film cu id: " + to_string(f.getId()));
	auto it = find_if(filme.begin(), filme.end(), [&f](const Film& el) {return el == f;});
	int poz = 0;
	for (int i = 0; i < filme.size(); i++)
	{
		Film p = filme.get(i);
		if (p.getId() == f.getId())
			poz = i;
	}
	for (int i = poz; i < filme.size() - 1; i++)
	{
		filme[i] = filme[i + 1];
	}
	filme.dec_size();
}

Film Repo::find(const int& id) const
{
	for (int i=0;i<filme.size();i++)
	{
		Film f = filme.get(i);
		if (f.getId() == id)
			return f;
	}
	throw RepoException("Nu exista filmul cu id" + to_string(id));
}

void Repo::update(const int& id, const string& titlu)
{
	Film f = find(id);
	if (!exist(f)) throw RepoException("Nu exista film cu id: " + to_string(f.getId()));
	auto it = find_if(filme.begin(), filme.end(), [&f](const Film& el) {return el == f; });
	f.setTitlu(titlu);
	*it = f;// inlocuiesc in vector
	
}

const VectDinNewDeleteT<Film>& Repo::getAll() const noexcept {
	return filme;
}

ostream& operator<<(ostream& out, const RepoException& ex) {
	out << ex.msg;
	return out;
}