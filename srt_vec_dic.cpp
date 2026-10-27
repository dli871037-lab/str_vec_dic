/*************************************
* Автор: Ли Даниил                   *
* Задание: Строки, векторы и словари *
* Вариант: 13                        *
*************************************/
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  constexpr int maxSize = 200;
  unsigned char currentLetter;
  string phrase;
  string result;

  if (!(getline(cin, phrase)) || size(phrase) > maxSize || size(phrase) < 1) {
    cout << "INVALID\n";
    return 1;
  }

  for (int indexInPhrase = 0; indexInPhrase < size(phrase); ++indexInPhrase) {
    currentLetter = phrase[indexInPhrase];

    if (isalpha(currentLetter)) {
      result += currentLetter;
    }
  }

  cout << result;
  return 0;
}