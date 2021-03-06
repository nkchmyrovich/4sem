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
		return 0;
	}
	std::string word;
	std::map<std::string, int> myMap;
	while (!file.eof()) {
		file >> word;
		prepare(word);
		if (word.size() > 0) 
			myMap[word]++;
	}
	std::vector<Statistics> s;
	Statistics elem;
	for (const auto& it : myMap) {
		elem.word = it.first;
		elem.count = it.second;
		s.push_back(elem);
	}
	std::sort(s.begin(), s.end(), comparator);
	std::ofstream file_output("output.txt");
	if (!file_output.is_open()) {
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
