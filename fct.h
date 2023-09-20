#ifndef FCT_H
#define FCT_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool check_vector(vector<vector<string>> v, string question);
void ask_question(vector<vector<string>> v, string asked_q);
void add_question(vector<vector<string>>& v);

#endif
