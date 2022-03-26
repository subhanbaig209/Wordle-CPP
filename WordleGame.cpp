#include "WordleGame.h"
#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<algorithm>


using namespace std;


WordleGame::WordleGame(const std::string& filename) {
    ifstream file(filename);
    string words;

    while (getline(file, words)) {
		dictionary.insert(words);
	}

    done = false;

}

void WordleGame::select_key(int index) {

    int answer_index = index % dictionary.size();

    set<string>::iterator iter = dictionary.begin();

    for (int i = 1; i < answer_index; i++) {
        iter++;
    }

    key = *iter;

}


string WordleGame::score(const std::string& input){

    set<string>::iterator iter;

    for (iter = dictionary.begin(); iter != dictionary.end(); iter++) {
        if (*iter == input) {
            break;
        }
    }

    if (input.size() != 5) {
        return  "not in dictionary";
    }

    else if (iter == dictionary.end()) {
        return "not in dictionary";
    }

    




  std::string out = "xxxxx";
  string no_match = "";
  
    for (unsigned int i = 0; i < input.length(); i++) {
        

            
            if (input[i] == key[i]) {

                out[i] = '*';
                
            }
            else {
                out[i] = '-';
                std::string str1(1, key[i]);
                no_match.append(str1);
            }
    }

    for (unsigned int i = 0; i < input.length(); i++) {

        std::string str(1, input[i]);
        size_t found = key.find(str);
        if (out[i] != '*') {

         
            if (found!=std::string::npos && no_match.find(input[i]) != std::string::npos) {
                out[i] = '+';
                std::replace(no_match.begin(), no_match.end(), input[i], '+');
            }
        
            /*else {
                out[i] = '-';
            }*/
        }
    }
        
    
    if (out == "*****") {
        done = true;
    }

    
    
   return out;


}


bool WordleGame::over(void) const  {
    return done;

}  




