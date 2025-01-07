#include "Harl.hpp"

int main()
{
	Harl satan;

	satan.complain("DEBUG");
	satan.complain("INFO");
	satan.complain("WARNING");
	satan.complain("ERROR");
	satan.complain("unknown");
	return 0;
}