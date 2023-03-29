//***************************************************************************
//
// Sajjad Haq
// H00803115
// CSC 122 COMPUTER SCIENCE II (62339)
//
// I certify that this is my own work and where appropriate an extension of the
// starter code provided for the assignment.
//
//***************************************************************************
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int max_size = 5;
  vector<string> *str_vec = new vector<string>(max_size);
  int count = 0;

  string input;
  do {
    cout << "Please enter a string, otherwise say 'exit' to quit ";
    cin >> input;
  if (input == "exit") {
    break;
  }
    if (count < max_size) {
      (*str_vec)[count] = input;
      count++;
    } else {
      max_size *= 2;
      vector<string> *new_vec = new vector<string>(max_size);
      for (int i = 0; i < count; i++) {
        (*new_vec)[i] = (*str_vec)[i];
      }
      delete str_vec;
      str_vec = new_vec;
      (*str_vec)[count] = input;
      count++;
    }
  } while (input != "exit");

  cout << "List of strings: ";
  for (int i = 0; i < count - 1; i++) {
    cout << (*str_vec)[i] << ", ";
  }
  if (count > 1) {
    cout << (*str_vec)[count - 1];
  }

  delete str_vec;

  return 0;
}