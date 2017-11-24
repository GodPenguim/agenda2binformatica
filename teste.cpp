#include <fstream>
#include <iostream>

usgin namespace std;

int main(void)
{
	ofstream ARQTXT;
	ARQTXT.open("ARQTXT.TXT", ios_base::trunc);
	ARQTXT.close();
	return 0;
}
