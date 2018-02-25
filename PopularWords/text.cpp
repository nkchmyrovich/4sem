#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#define NUMBER_OF_POPULAR_WORDS 100

struct Statistics {
	int count;
	std::string word;
};

void prepare (std::string& word) {
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
}

bool comparator (const Statistics& s1, const Statistics& s2) {
	return s1.count > s2.count;
}

int main(int argc, char const *argv[]) {
	std::ifstream file("_file.txt");
	if (!file.is_open()) {
		std::cout << "ERROR: input file cannot be opened\n";
		// кажется, что можно не делать close, если не получилось открыть файл
		//Ok
		return 0;
	}
	std::string word;
	std::map<std::string, int> myMap;
	while (!file.eof()) {
		file >> word; // только эта строка бросает исключения
		/// судя по http://www.cplusplus.com/reference/istream/istream/operator%3E%3E/ вы ловите не единственный вариант
		/// мне кажется, что для 1го упражнения в семестре можно не заморачиваться с исключениями здесь и убрать try/catch
		//Ок

		//Просто мне очень часто компилятор кидал это исключение std::length_error
		//Так что я на всякий случай сделал try/catch

		std::cout << word << "\n";
		prepare(word);
		if (word.size() == 0) continue;
		myMap[word]++;

		// зачем делать clear?
		//Ок, убрал
	}
	std::vector<Statistics> s;
	Statistics elem;
	// лучше const auto& it, чтобы подчеркнуть, что мы не намерены изменять myMap
	//Ок
	for (const auto& it : myMap) {
		elem.word = it.first;
		elem.count = it.second;
		s.push_back(elem);
	}
	std::sort(s.begin(), s.end(), comparator);
	std::ofstream file_output("output.txt");
	if (!file_output.is_open()) {
		// ? вроде не нужно
		//Ок
		std::cout << "ERROR: output file cannot be opened\n";
		return 0;
	}
	for (size_t i = 0; i < NUMBER_OF_POPULAR_WORDS; i++) {
		file_output << s[i].word << '\n';
	}
	file.close();
	file_output.close();
	return 0;
}
