#include "MainForm.h"
#include "Threads.h"

using namespace Spector;

[STAThreadAttribute]
int main() {
	MainForm^ form = gcnew MainForm();
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Threads::MainThread, NULL, 0, NULL);
	form->ShowDialog();
	return 0;
}