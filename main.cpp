#include "my_library.h"

string readFileToString(const string &file_name) {
    // Open the file in binary mode with the pointer at the end.
    ifstream file(file_name, ios::binary | ios::ate);
    if (!file) {
        throw "[Klaida] Failas neegzistuoja / neatsidaro.\n";
    }
    
    // Get file size and seek back to the beginning.
    std::streamsize size = file.tellg();
    file.seekg(0, ios::beg);
    
    // Pre-allocate a string of the appropriate size.
    string content;
    content.resize(size);
    
    // Read the file content directly into the string.
    if (!file.read(&content[0], size)) {
        throw "[Klaida] Skaitymo klaida!\n";
    }
    
    return content;
}

vector<string> splitIntoWords(const std::string &text) {
    string cleaned = text;

    // 2) Strip out “X.” tokens, where X is an ASCII letter
    for (size_t i = 0; i + 1 < cleaned.size(); ++i) {
        char a = cleaned[i], b = cleaned[i+1];
        // isEnglishLetter(a) && b == '.'
        if (((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
            && b == '.') {
            bool start_ok = (i == 0) || std::isspace(static_cast<unsigned char>(cleaned[i-1]));
            bool end_ok   = (i+2 >= cleaned.size()) || std::isspace(static_cast<unsigned char>(cleaned[i+2]));
            if (start_ok && end_ok) {
                cleaned[i]   = ' ';
                cleaned[i+1] = ' ';
            }
        }
    }
    
    // 3) Clean out all non-letters → space; letters → lowercase
    for (char &c : cleaned) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        } else {
            c = ' ';
        }
    }

    istringstream iss(cleaned);
    vector<std::string> words;
    string w;
    while (iss >> w) {
        words.push_back(w);
    }
    return words;
}

int main(){

    string file_content;
    try {
        file_content = readFileToString("text.txt");
        // cout << file_content;
    } catch (const char *msg) {
        cerr << msg;
    }

    vector<string> words = splitIntoWords(file_content);

    unordered_map<string,int> freq;
    for (auto const& w : words)
        ++freq[w];

    for (auto const& p : freq) {
        if (p.second > 1) {
            cout << p.first
                  << " repeats "
                  << p.second
                  << " times\n";
        }
    }
    return 0;
}