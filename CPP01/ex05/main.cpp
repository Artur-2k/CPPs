#include "Harl.hpp"

int main()
{
	Harl satan;

	std::cout << "[DEBUG]" << std::endl;
	satan.complain("DEBUG");

	std::cout << "\n[INFO]" << std::endl;
	satan.complain("INFO");

	std::cout << "\n[WARNING]" << std::endl;
	satan.complain("WARNING");

	std::cout << "\n[ERROR]" << std::endl;
	satan.complain("ERROR");

	std::cout << "\n[UNKNOWN]" << std::endl;
	satan.complain("unknown");

	return 0;
}