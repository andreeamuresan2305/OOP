#include "consola.h"
#include "Service.h"
#include "Repository.h"
#include "validator.h"
#include "template.h"
#include "teste_repo.h"
#include "teste_service.h"
#include "Film.h"

/*void TestAll() {
	testeRepo();
	testFilm();
	testCtr();
	testValidator();
}*/

int main() {
	Repo r;
	Validator v;
	Service srv{ r,v };
	ConsolUI ui{ srv };
	ui.start();
	//TestAll();

}
