#include <iostream>
#include <vector>
#include <string>
#include <any>
#include <cstdlib>
#include <cstdio>
/*
4-14-26 10:18PM

TODO:

work on type conversion for a new "printmathexpr |" function
actually start lexing
*/
std::vector<std::string> printreg = {};
std::vector<int> exitcode = {};
std::vector<std::string> errmessage = {};
std::vector<char> list(std::string text) {
	std::vector<char> list = {};
	for(char i : text) {
		list.push_back(i);
	}
	return list;
}
void utils() {
	for(std::string item : printreg) {
		std::cout << item << "\n";
	}
}
std::vector<std::string> split(std::string text, char delim) {
	text += '\0';
	std::vector<std::string> main = {};
	std::string temp = "";
	if(text.find(delim) == std::string::npos) {
		main.push_back(text);
	}
	else {
		for(char i : text) {
			if(i == '\0') {
				main.push_back(temp);
			}
			else if(i == delim) {
				main.push_back(temp);
				temp = "";
			}
			else if( (! (i == delim) ) ) {
				temp += i;
			}
		}
	}
	return main;
}
enum TokenType {
	exitstatement,
	printstatement,
	errormessage,
};
struct Line {
	std::string command;
	std::string value;
};
std::string to_str(TokenType token) {
	switch(token) {
		case TokenType::printstatement:
			return "printstatement";
		case TokenType::exitstatement:
			return "exitstatement";
		case TokenType::errormessage:
			return "errmessage";
	}
}
void debug(std::string command, std::string value) {
	Line ln;
	ln.command = command;
	ln.value = value;
	std::cout << "<?debug> {" << "\n";
	std::cout << "\t<?struct Line> {" << "\n";
	std::cout << "\t\t<?command>:\t" << ln.command << "\n";
	std::cout << "\t\t<?value>:\t" << ln.value << "\n";
	std::cout << "\t}\n";
	std::cout << "\t<?enum TokenType> {" << "\n";
	std::cout << "\t\t(printstatement)\n\t\t(exitstatement)\n\t\t(semicolon)\n";
	std::cout << "\t}\n}";
}
int main() {
	std::string line = "print | 'Hello World!'\nerror | 'i am tired'\nexit | 0";
	return 0;
}
