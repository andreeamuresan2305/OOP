#pragma once
#include "Service.h"

class ConsolUI {
	Service& srv;
	/*
	Citeste datele de la tastatura si adauga Film
	arunca exceptie daca: nu se poate salva, nu e valid
	*/
	void adaugaUI();
	/*
	Tipareste o lista de filme la consola
	*/
	void tipareste(const VectDinNewDeleteT<Film>& film);
public:
	ConsolUI(Service& srv) noexcept :srv{ srv } {
	}
	//nu permitem copierea obiectelor
	ConsolUI(const ConsolUI& ot) = delete;

	void start();
};