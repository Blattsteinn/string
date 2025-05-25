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
    istringstream iss(text);
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
        cout << file_content;
    } catch (const char *msg) {
        cerr << msg;
    }

    vector<string> words = splitIntoWords(file_content);

    return 0;
}