// Baconian.cpp
/*
*
* Encryption
* =============PROJECT============
* Copyright (c) vali ahmad rahmani
* Date Jun,3,2021
* name Baconian
*
*/
#include <iostream>
#include <conio.h>
using namespace std;

void Code(char ch, int(&code)[5]) {
	int word;
	if (ch == ' ') {
		code[0] = code[1] = code[2] = code[3] = code[4] = 1;
	}
	else if (ch == '.') { code[0] = code[1] = code[2] = code[3] = 1; code[4] = 0; }
	else if (ch >= 'a' && ch <= 'z') {
		word = (int)ch - 97;
		for (int i = 4; i >= 0; i--) {
			code[i] = word % 2;
			if (!code[i])word /= 2;
			else { word -= 1; word /= 2; }
		}
	}
	else;
}
int UPlowCase(char ch) {
	if (ch >= 'A' && ch <= 'Z')return 0;
	else if (ch >= 'a' && ch <= 'z')return 1;
	else;
}
char Decode(int code[5]) {
	int word_int = 0;
	for (int i = 0; i < 5; i++)
		word_int = word_int * 2 + code[i];
	if (word_int >= 0 && word_int <= 25)return (char)(word_int + 97);
	else if (word_int == 30)return '.';
	else if (word_int == 31)return ' ';
	else;
}
string Baconian(string mask) {
	string msg;
	int code[5], j = 0;

	for (int i = 0; i < mask.size(); i++) {
		if (j == 5) {
			msg.push_back(Decode(code));
			j = 0;
		}
		if (mask[i] >= 'A' && mask[i] <= 'Z' || mask[i] >= 'a' && mask[i] <= 'z') {
			code[j] = UPlowCase(mask[i]);
			j++;
		}
	}
	return msg;
}
string Baconian(string mask, string msg) {
	int code[5], j = 0;
	for (int i = 0; i < msg.size(); i++) {
		Code(msg[i], code);
		for (int k = 0; k < 5; k++) {
			if (!code[k]) {
				while (!(mask[j] >= 'a' && mask[j] <= 'z'))
					j++;
				mask[j] = (char)toupper(mask[j]);
				j++;
			}
			else {
				while (!(mask[j] >= 'a' && mask[j] <= 'z'))
					j++;
				mask[j] = (char)tolower(mask[j]);
				j++;
			}
		}
	}
	return mask;
}

int main(int argc, char* argv[])
{
	string msg;
	string txt;
	cout << "\n#1 cryption  #2incryption : ";
	if (_getche() == 49) {
		cout << "\nEnter The Massage : ";
		msg.push_back(getche());
		cout << "\nEnter The Mask : ";
		cin >> txt;
		cout<<Baconian(txt, msg);
	}
	else {
		cout << "\nEnter The Mask : ";
		cin >> txt;
		cout << Baconian(txt);
	}

	return 0;
}