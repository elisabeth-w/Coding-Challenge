#include "fct.h"

int main() {

	string decision;
	vector<vector<string>> q_a; // q&a vektor: [[q1, a11,.., a1n], [q2, a21,.., a2n], ...]

	cout << "Welcome" << endl;

	while(1){
		cout << "Would you like to ask a question or would you like to add one?" << endl;
		cout << "Type 1 to ask a question and 2 to add one." << endl;
		cout << "Type 3 to exit." << endl;
    
		getline(cin, decision);
		
		if (decision == "1"){
			cout << "Please enter your question." << endl; 
			string asked_q;
			getline(cin, asked_q);
			ask_question(q_a, asked_q);
		}
		else if (decision == "2"){
			add_question(q_a);
			}
		else if (decision == "3"){
			break;
		}
		else{
			cout << "Wrong input. Please make sure to chose between option 1, 2 and 3." << endl;
		}
	}
	
	return 0;
}