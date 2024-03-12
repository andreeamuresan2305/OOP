#include "consola.h"
#include <iostream>
#include <string>

using namespace std;

void ConsolUI::tipareste(const VectDinNewDeleteT<Film>& filme) {
	cout << "Filme:\n";
	for (int i = 0;i<srv.getAll().size();i++) {
		Film f = srv.getAll().get(i);
		cout << ' ' << f.getId() << ' ' << f.getTitlu() << ' ' << f.getGen() << ' '<< f.getAn()<<' '<<f.getActor()<<'\n';
	}
	cout << "Sfarsit lista filme\n";
}

void ConsolUI::adaugaUI() {
	string titlu, gen, actor;
	int id, an;
	cout << "Dati id:";
	cin >> id;
	cout << "Dati tip:";
	cin >> titlu;
	cout << "Dati gen:";
	cin >> gen;
	cout << "Dati an:"; 
	cin >> an;
	cout << "Dati:";
	cin >> actor;
	srv.store_srv(id, titlu, gen, an, actor);
	cout << "Adaugat cu succes\n";
}

void ConsolUI::start() {
	while (true) {
		cout << "Meniu:\n";
		cout << "1 adauga\n2 tipareste\n3 delete\n4 update\n5 sort titlu\n6 sort actor\n7 sort an/gen\n0 Iesire\nDati comanda:";
		int cmd,id,an_min,an_max;
		string titlu;
		cin >> cmd;
		try
		{
			switch (cmd) {
			case 1:
				adaugaUI();
				break;
			case 2:
				tipareste(srv.getAll());
				break;
			case 3:
				cin >> id;
				srv.delete_srv(id);
				tipareste(srv.getAll());
				break;
			case 4:
				cin >> id;
				cin >> titlu;
				srv.update_srv(id, titlu);
				tipareste(srv.getAll());
				break;
			case 5:
				cout << "Filme sortate dupa titlu:";
				tipareste(srv.sortByTitlu());
				break;
			case 6:
				cout << "Filme sortate dupa actor:";
				tipareste(srv.sortByActor());
				break;
			case 7:
				cout << "Filme sortate dupa an si gen:";
				tipareste(srv.sortByAnGen());
				break;
			case 8:
				cout << "Dati titlu:";
				cin >> titlu;
				tipareste(srv.filtrareTitlu(titlu));
				break;
			case 9:
				cout << "Dati an minim:";
				cin >> an_min;
				cout << "Dati an maxim:";
				cin >> an_max;
				tipareste(srv.filtrareAn(an_min, an_max));
				break;
			case 0:
				return;
			default:
				cout << "Comanda invalida\n";
			}
		}
			catch (RepoException& ex) {
				cout << ex << '\n';
			}
			catch (ValidateException& ex) {
				cout << ex << '\n';
			}
		}
	}