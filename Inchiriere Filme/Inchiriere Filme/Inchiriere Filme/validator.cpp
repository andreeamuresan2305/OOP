#include "validator.h"
#include <sstream>
#include <assert.h>

void Validator::validate(const Film& f) {
	VectDinNewDeleteT<string> msgs;
	if (f.getId() < 0) msgs.push_back("Id negativ!");
	if (f.getTitlu().size() == 0) msgs.push_back("Titlu vid!");
	if (f.getGen().size() == 0) msgs.push_back("Gen vid!");
	if (f.getAn() < 0) msgs.push_back("An negativ!");
	if (f.getActor().size() == 0) msgs.push_back("Actor valid");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}

ostream& operator<<(ostream& out, const ValidateException& ex) 
{
	for (int i = 0;i<ex.msgs.size();i++)
	{
		string msg = ex.msgs[i];
		out << msg << " ";
	}
	return out;
}

void testValidator()
{
	Validator v;
	Film f{ -1, "", "", -1, ""};
	try
	{
		v.validate(f);
	}
	catch (const ValidateException& ex)
	{
		std::stringstream sout;
		sout << ex;
		const auto mesaj = sout.str();
		assert(mesaj.find("negativ") >= 0);
		assert(mesaj.find("vid") >= 0);
	}
}