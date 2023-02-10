#ifndef WORDLE_HELPER_H
#define WORDLE_HELPER_H

#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
class WordleHelper{
 
    std::vector<std::string> allowed;
    std::vector<std::string> answers;

    std::vector<std::string> green;
    std::vector<std::string> yellow;
    std::vector<std::string> gray;


    bool contains(std::string word, char c){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == c){
                return true;
            }
        }

        return false;
    }

public:
    WordleHelper(){
        std::string answersFile = "answers.txt";
        std::string allowedFile = "allowed.txt";

        std::fstream newfile;

        newfile.open(answersFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                answers.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + answersFile + ".");
        }

        newfile.open(allowedFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                allowed.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + allowedFile + ".");
        }
    }

    void addGreen(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Green feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Green feedback must contain only lowercase letters or underscores");
        }

        green.push_back(feedback);
    }

    void addYellow(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Yellow feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters or underscores");
        }

        yellow.push_back(feedback);
    }

    void addGray(std::string feedback){
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c < 'a' && c > 'z';
        })){
            throw std::logic_error("Gray feedback must contain only lowercase letters");
        }

        gray.push_back(feedback);
    }

    std::vector<std::string>possibleSolutions(){
        vector<string> result; //return vector
        bool flag; //checkpoint boolean
        for (int i = 0; i < answers.size(); i++){ //iterating through whole answers text file
            flag = true; //resetting checkpoint
            for (int j = 0; j < green.back().length(); j++){ //iterating through green
                if(green.back()[j]!='_'){ //if index of green is not '_', continue
                    if(answers[i][j]!=green.back()[j]){ //if index of answer & green aren't the same, 
                        flag = false;                   //change flag to false
                    }    
                }
            }
            if (!flag){ //if flag is false, continue (next iteration of "int i" for loop)
                continue;
            }
            flag = true; //reset flag to true 
            for(int j = 0; j < gray.back().length(); j++){ //iterating through gray
                if(contains(answers[i], gray.back()[j])){ //if index i of answer.txt contains index j of gray, set flag to false
                    flag = false;
                }
            }
            if(!flag){
                continue;
            }
            flag = true;
            for(int j = 0; j < yellow.back().length(); j++){ //iterating through yellow
                if (yellow.back()[j]!='_'){ //check to see if index of yellow is '_'
                    if(answers[i][j]==yellow.back()[j]){ //check to see that index i of answers and index j of that word is the same letter and index as yellow, set flag to false
                        flag = false;
                    }
                    else if(contains(answers[i], yellow.back()[j])==false){ //check if answers[i] does not contain the letter(s) of yellow, set flag to false
                        flag = false;
                    }                       
                }         
            }
            if(!flag){
                continue;
            }
            result.push_back(answers[i]); //push back answers[i] if it makes it this far
        }
        return result; //return results
    }

    std::vector<std::string> suggest(){
        // Optionally, your code here...
        return {"bring", "words", "close"};
    }

    ~WordleHelper(){

    }

    friend struct WordleTester;

};

#endif