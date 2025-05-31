#pragma once

string readFileToString(const string &file_name);
vector<string> splitIntoWords(const string &text);
vector<string> splitIntoWords(const string &text);

void print(const map<string, wordDetails>& word_information, string file_name);
void extractUrls(const string &text, string file_name);