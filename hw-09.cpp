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

//структура element (составляющая словаря)
struct element {
	string word = "";
	unsigned frequency = 0;

	//функция печати на консоль
	void print() {
		cout << word << " [" << frequency << "]" << endl;
	}

	//перегрузка функции печати (для записи словаря в файл)
	void print(ofstream& file) {
		file << word << " [" << frequency << "]" << endl;
	}
};

//функция приведения заглавных букв в строчные:
//чтобы при добавлении нового слова, одно и то же слово не было разделено на несколько видов по написанию ("The", "the", "thE")
string get_lower_string(const string& str) {
	string result = "";

	for (int i = 0; i < str.size(); ++i)//запускаем цикл, который проходится по строке, пока она не закончится 
		//tolower берет отдельную букву и возвращает её строчную версию (в нижнем регистре) и помещает её в новую строку с помощью метода push_back:
		result.push_back(std::tolower(str[i]));

	return result;
}

//функция добавления в словарь нового слова
void add(vector<element>& dictionary, const string& new_word) {
	string lower_word = get_lower_string(new_word); //создаем слово со строчными буквами с помощью функции

	for (int i = 0; i < dictionary.size(); ++i) //проходимся по словарю
		if (dictionary[i].word == lower_word) { //смотрим, было уже слово записано 
			dictionary[i].frequency++;			//(если да, то увеличиваем частоту)
			return;								//выходим из функции!
		}

	//если мы не вышли раньше, то искомого слова обнаружено не было =>
	//добавление искомого слова с частотой = 1 (потому что встретили первый раз при записывании в вектор)
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
	vector<element> dictionary; //создаем словарь dictionary на базе вектора, который будет хранить структуры типа element

	ifstream in("input.txt"); //открываем поток для работы с файлом, для чтения
	if (!in.is_open()) { //проверяем, открылся ли файл 
		//если файл не открылся, то печатаем информацию в специальный поток cerr (для ошибок)
		cerr << "File \"input.txt\" is not open." << endl;
		return 1;
	}

	while (!in.eof()) { //проверяем, не пуст ли файл (не достигнут ли конец файла)

		string new_word;

		//дополнительно проверяем, удалось ли считывание слова:
		//например, если конец файла ещё не достигнут, но считывание уже не удастся
		if (!read_by_delimiter(in, new_word, "!?.,';: -+/*’\n"))
			break;

		//if (!(in >> new_word)) //two's
		//	break;

		add(dictionary, new_word); //вызываем функцию добавления в словарь, в которую отправляем вектор dictionary и новое слово
	}

	ofstream out("output.txt"); //открываем поток для работы с файлом, для записи

	//size_t - псевдоним unsigned int: тип, способный представлять размер любого объекта в байтах,
	//гарантирует, что в него поместится максимальная длина массива

	for (int i = 0; i < dictionary.size(); ++i) //перебираем элементы вектора (a.k.a. элементы словаря)
		if (dictionary[i].frequency > 1) //если "частота встречаемости" текущего слова > 1
			dictionary[i].print(out); //печатаем элемент в файл

	return 0;
}

*/