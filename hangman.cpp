/* hangman.cpp
 * Hangman game
 * (c) 2023 Annie Worroll
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cstdlib>


const std::string WORDS_FILE = "/usr/share/dict/words";

typedef std::vector<std::string> WordVector;

/* Returns true if string s contains any non alphabetic characers, false
 * otherwise
 */
bool contains_non_alpha(std::string s){
  for(char l: s){
    if(!std::isalpha(l)){
      return true;
    }
  }
  return false;
}

/* Generates a vector of strings, including all strings from the wordlist
 * that are at least 5 characters long and do not contain any non-alphabetic
 * characters. Uses the word file named in the constant WORDS_FILE
 */
WordVector generate_word_list()
{
  std::ifstream input_words;
  input_words.open(WORDS_FILE);

  WordVector word_list;
  std::string current_word = "";
  while(!input_words.eof()){
    input_words >> current_word;
    //Skip anything below 5 letters
    if(current_word.length() < 5){
      continue;
    }
    //Skip anything with punctuation
    if(contains_non_alpha(current_word)){
      continue;
    }
    //If it gets past that, it's valid for the game. Include.
    word_list.push_back(current_word);
  }
  return word_list;
}

/* Returns the current guess updated with the guessed letter in each
 * position where it appears in the target word
 */
std::string update_guessed_word(std::string target_word, std::string current_guess, char letter)
{
  for(int i = 0; i < target_word.length(); ++i){
    if(target_word[i] == letter){
      current_guess[i] = letter;
    }
  }
  return current_guess;
}

void game_loop(WordVector words)
{
  std::string word_to_guess = "";
  char guess;
  std::string guessed_word = "";
  std::string guessed_letters = "";
  int guesses_left = 5;

  //Randomly select word to guess
  word_to_guess = words.at(std::rand() % words.size());
  //Set the current guess to all underscores with the same number of characters as the target
  guessed_word.resize(word_to_guess.length(), '_');
  while(true){
    std::cout << guessed_letters << std::endl;
    std::cout << guessed_word << std::endl;

    std::cin >> guess;
    guessed_letters.push_back(guess);
    //Check if letter is in string
    if(word_to_guess.find(guess) == std::string::npos){
      std::cout << "Wrong!" << std::endl;
      guesses_left--;
    }else{
      //Update the guessed word
      guessed_word = update_guessed_word(word_to_guess, guessed_word, guess);
      std::cout << "Got one!" << std::endl;
    }

    if(guesses_left <= 0){
      std::cout << "You lose" << std::endl;
      break;
    }
  }
}

int main(){
  
  game_loop(generate_word_list());
  return 1;
}
