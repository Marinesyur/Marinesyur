/*

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

//��������� element (������������ �������)
struct element {
	string word = "";
	unsigned frequency = 0;

	//������� ������ �� �������
	void print() {
		cout << word << " [" << frequency << "]" << endl;
	}

	//���������� ������� ������ (��� ������ ������� � ����)
	void print(ofstream& file) {
		file << word << " [" << frequency << "]" << endl;
	}
};

//������� ���������� ��������� ���� � ��������:
//����� ��� ���������� ������ �����, ���� � �� �� ����� �� ���� ��������� �� ��������� ����� �� ��������� ("The", "the", "thE")
string get_lower_string(const string& str) {
	string result = "";

	for (int i = 0; i < str.size(); ++i)//��������� ����, ������� ���������� �� ������, ���� ��� �� ���������� 
		//tolower ����� ��������� ����� � ���������� � �������� ������ (� ������ ��������) � �������� � � ����� ������ � ������� ������ push_back:
		result.push_back(std::tolower(str[i]));

	return result;
}

//������� ���������� � ������� ������ �����
void add(vector<element>& dictionary, const string& new_word) {
	string lower_word = get_lower_string(new_word); //������� ����� �� ��������� ������� � ������� �������

	for (int i = 0; i < dictionary.size(); ++i) //���������� �� �������
		if (dictionary[i].word == lower_word) { //�������, ���� ��� ����� �������� 
			dictionary[i].frequency++;			//(���� ��, �� ����������� �������)
			return;								//������� �� �������!
		}

	//���� �� �� ����� ������, �� �������� ����� ���������� �� ���� =>
	//���������� �������� ����� � �������� = 1 (������ ��� ��������� ������ ��� ��� ����������� � ������)
	dictionary.push_back(element{ lower_word, 1 });
}

bool read_by_delimiter(ifstream& file, string& word, const string& delimiters) {
	word = "";

	bool isWordConstructed = false;
	while (!file.eof() && !isWordConstructed) {
		char symbol = file.get();

		if (symbol == EOF)
			break;

		if (delimiters.find(symbol) == string::npos)
			word += symbol;
		else
			if (!word.empty())
				isWordConstructed = true;
	}

	if (file.eof() && word.empty())
		return false;

	return true;
}

int main() {
	vector<element> dictionary; //������� ������� dictionary �� ���� �������, ������� ����� ������� ��������� ���� element

	ifstream in("input.txt"); //��������� ����� ��� ������ � ������, ��� ������
	if (!in.is_open()) { //���������, �������� �� ���� 
		//���� ���� �� ��������, �� �������� ���������� � ����������� ����� cerr (��� ������)
		cerr << "File \"input.txt\" is not open." << endl;
		return 1;
	}

	while (!in.eof()) { //���������, �� ���� �� ���� (�� ��������� �� ����� �����)

		string new_word;

		//������������� ���������, ������� �� ���������� �����:
		//��������, ���� ����� ����� ��� �� ���������, �� ���������� ��� �� �������
		if (!read_by_delimiter(in, new_word, "!?.,';: -+/*�\n"))
			break;

		//if (!(in >> new_word)) //two's
		//	break;

		add(dictionary, new_word); //�������� ������� ���������� � �������, � ������� ���������� ������ dictionary � ����� �����
	}

	ofstream out("output.txt"); //��������� ����� ��� ������ � ������, ��� ������

	//size_t - ��������� unsigned int: ���, ��������� ������������ ������ ������ ������� � ������,
	//�����������, ��� � ���� ���������� ������������ ����� �������

	for (int i = 0; i < dictionary.size(); ++i) //���������� �������� ������� (a.k.a. �������� �������)
		if (dictionary[i].frequency > 1) //���� "������� �������������" �������� ����� > 1
			dictionary[i].print(out); //�������� ������� � ����

	return 0;
}

*/