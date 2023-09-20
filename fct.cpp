#include "fct.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void ask_question(vector<vector<string>> v, string asked_q){
		int found_answer = 0;
		for (int i = 0; i < v.size(); i++){
			if(v[i][0] == asked_q){
				found_answer = 1;
				cout << "The answer to your question is:" << endl;
				for (int j = 1; j < v[i].size(); j++){ // start j at index 1 because index 0 is the question
					cout <<"-" << v[i][j] << endl;
				}
			}
		}
		if (found_answer == 0){
			cout << "the answer to life, universe and everything is 42" << endl;
		}
}

void add_question(vector<vector<string>>& v){
		string s;
		cout << "Please enter the question you would like to add in the format:" << endl;
		cout << "Question? \"Answer_1\" \"Answer_2\" ... \"Answer_n\"" << endl;
		getline(cin, s);
		vector<string> new_entry;
    int pos = 0;
    if (new_entry.size() == 0){
        pos = s.find("?");
        string q = s.substr(0, pos);
        while (q.size() >= 255){
			cout << "The question is too long. Please try again." << endl;
			getline(cin, q);
			int pos_new = q.find("?");
			q = q.substr(0, pos_new); 
		}
		if (check_vector(v, q)){
			cout << "This question already exists." << endl; 
			ask_question(v, q);
			return;
		}
        new_entry.push_back(q);
        s.erase(0, pos+3); // 1 is the length of the delimiter, "?", but after the demlimiter for the question comes a whitespace and """ from  the answer so skip that too
    	pos = 0;
    }

    while(pos < s.size()){
        pos = s.find('"');
        string a = s.substr(0, pos);
        while (a.size() >= 255){
			cout << "The answer is too long. Please try again." << endl;
			getline(cin, a);
		}
        new_entry.push_back(a);
        s.erase(0, pos+3); // 1 is the length of the delimiter, """ also skip whitespace and next "
    }
    
    if (new_entry.size() == 1){
        cout << "You need to add at least one answer." << endl;
        string answers;
        getline(cin, answers);
        int i = 0;
        answers.erase(0, i + 1); // handle the first answer separetly, just delete the first "
        // now search for delimiter and split like before
        while(i < answers.size()){
            i = answers.find('"');
            new_entry.push_back(answers.substr(0, i));
            answers.erase(0, i+3); // 1 is the length of the delimiter, """ also skip whitespace and next "
        }
    }
			v.push_back(new_entry); //new_entry
		}


bool check_vector(vector<vector<string>> v, string question){
	// returns true if question exists and false otherwise
	for (int i = 0; i < v.size(); i++){
			if(v[i][0] == question){
				return true;
			}
		}
	return false;
}

