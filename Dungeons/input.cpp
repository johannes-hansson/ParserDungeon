#include "input.h"
#include <iostream>

using namespace std;

vector<string> take_command(string prompt) {
	cout << prompt;
	string input;
	getline(cin, input);
	
	vector<string> args;
	string currentArg = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ' || input[i] == '\n') {
			if (currentArg != "") {
				args.push_back(currentArg);
				currentArg = "";
			}
		} else {
			currentArg += input[i];
		}
	}

	if (currentArg != "") {
		args.push_back(currentArg);
	}

	return args;
}
