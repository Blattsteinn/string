#include "my_library.h"
#include "my_functions.h"

int main(){

    string file_content;
    try {
        file_content = readFileToString("text.txt");
    } catch (const char *msg) {
        cerr << msg;
    } istringstream iss(file_content);


    unordered_map<string, wordDetails> word_information;
    
    string line;
    int line_count = 0;
    while (std::getline(iss, line)){
        ++line_count;
        auto words = splitIntoWords(line);
        for(auto const &w : words){
            auto &info = word_information[w];
            ++info.count;
            // If a word repeats twice in one line don't update it
            if (info.lines.empty() || info.lines.back() != line_count) {
                info.lines.push_back(line_count);
            }
        }
    }

    print(word_information);

    return 0;
}