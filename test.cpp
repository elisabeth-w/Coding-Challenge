#include "fct.h"




bool test_check_vector(){
	vector<vector<string>> v {{"a", "b", "c"}};
	string q1 = "a";
	string q2 = "f";
	if (check_vector(v, q1) and check_vector(v, q2) == false){
		return true;
	}
	else {
		return false;
	}
}

void test_add_question(){
	cout << "Test add question: " << endl;
	vector<vector<string>> v {{"a", "b", "c"}};
	add_question(v);
	// for correct input, fct should just add another vector
	// input: q? -> expected output: "You need to add at least one answer."
	// input: a? -> expected output: "This question already exists." and the answer to the question
	// if a question or answer is too long: "The question/answer is too long. Please try again."
	for (int i = 0; i < v.size(); i++) { // see what vector looks like after correct input
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

void test_ask_question(){
	vector<vector<string>> v {{"What is Peters favorite food?", "Pizza", "Spaghetti", "Ice cream"}};
	string q = v[0][0];
	ask_question(v, q);
	ask_question(v, "What is Peters favorite drink?"); // expected output: "the answer to life, universe and everything is 42"
}

int main() {
	cout << "test check vector: " << test_check_vector() << endl;
	test_add_question();
	test_ask_question();

}