#include "my_library.h"
#include "my_functions.h"

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

vector<string> splitIntoWords(const string &text) {
    string cleaned = text;

    // Remove  one_letter + dot
    for (size_t i = 0; i + 1 < cleaned.size(); ++i) {
        char a = cleaned[i], b = cleaned[i+1];
        // if is english letter(a) && b == '.'
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
    
    // Clean out all non-letters
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


void print(const unordered_map<string, wordDetails>& word_information, string file_name){
    std::ofstream file_out("list_of_words.txt");
    if (!file_out) std::cerr << "[Error] Cannot open list_of_words.txt for writing\n";


    else {
        file_out << std::left
        << std::setw(20) << "Word"
        << std::setw(8)  << "Count"
        << "Lines\n";
        file_out << string(20 + 8 + 6, '-') << "\n";

        for (auto const& p : word_information) {
            if( p.second.count > 1){
                file_out << std::left
                        << std::setw(20) << p.first
                        << std::setw(8)  << p.second.count;

                for (int i = 0; i < p.second.lines.size(); ++i) {
                    if (i) file_out << ", ";
                    file_out << p.second.lines[i];
                }
                file_out << endl;
            }
        }
    }
    cout << "Word count saved to " << file_name << endl;
}

void extractUrls(const std::string &text, string file_name) {
    // A basic HTTP(S) URL regex
    static const std::regex url_regex(
        R"(\b(https?://)?(www\.)?[A-Za-z0-9-]+\.[A-Za-z]{2,}(/[^\s]*)?\b)",
        std::regex::icase
    );

    vector<string> urls;
    auto begin = std::sregex_iterator(text.begin(), text.end(), url_regex);
    auto end   = std::sregex_iterator();
    for (auto it = begin; it != end; ++it) {
        urls.push_back(it->str());
    }

    if (!urls.empty()) {
        std::ofstream url_out(file_name);
        if (!url_out) {
            std::cerr << "[Error] Cannot open urls.txt for writing\n";
        } else {
            for (auto &u : urls) {
                url_out << u << "\n";
            }
            std::cout << "Found " << urls.size()
                      << " URL(s) and saved to " << file_name << endl;
        }
    }
}