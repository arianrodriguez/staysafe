#include "MenuPrincipal.h"
using namespace ProjectFinal;

int main() {
	srand(time(0));
	Application::EnableVisualStyles();
	Application::Run(gcnew ProjectFinal::MenuPrincipal());
	return 0;
}
