#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void updateFormat();
void updateReadme();

int main( void ) {
	updateFormat();
	updateReadme();
}

void updateFormat() {
	system( "basename `pwd` | fgrep -w uva 1>/dev/null && ./updateFormat.sh && echo 'updated format'" );
}

void updateReadme() {
	std::ofstream fout;
	std::ifstream fin;
	std::string line = "";
	fout.open( "new_README.md" );
	fin.open( "README.md" );
	while ( line != "## 狀態" ) {
		getline( fin, line );
		fout << line << std::endl;
	}

	system( "rm README.md; mv new_README.md README.md" );
}