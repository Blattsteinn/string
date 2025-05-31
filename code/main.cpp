#include "my_library.h"
#include "my_functions.h"

// struct wordDetails {
//   int count = 0;
//    vector<int> lines;
//};

int main(){

    string file_content;
    try {
        file_content = readFileToString("text.txt");
    } catch (const char *msg) {
        cerr << msg;
    }
    
    istringstream iss(file_content);

    unordered_map<string, wordDetails> word_information;
    
    string line;
    int line_count = 0;
    while (std::getline(iss, line)){
        ++line_count;
        auto words = splitIntoWords(line);
        for(auto const &w : words){
            auto &info = word_information[w];
            ++info.count;

            if (info.lines.empty() || info.lines.back() != line_count) {
                info.lines.push_back(line_count);
            }
        }
    }

    print(word_information, "words_out.txt");
    extractUrls(file_content, "urls_out.txt");

    cout << endl;
    cout << "Press Enter to exit..."; string temp;
    getline(cin, temp);

    return 0;
}