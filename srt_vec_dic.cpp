/*************************************
* Автор: ДанИИл Ли                   *
* Задание: Строки, векторы и словари *
* Вариант: 13                        *
*************************************/
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

  if (size(result) == 0) {
    cout << "EMPTY";
  } else {
    cout << result;
  }


  vector<int> numbers;
  int countOfNumbers;
  int number;

  cout << "Count of numbers: ";
  cin >> countOfNumbers;

  if (countOfNumbers > 99) {
    cout << "INVALID\n";
    return 2;
  }

  for (int indexOfNumbers = 0; indexOfNumbers < countOfNumbers; ++indexOfNumbers) {
    if (!(cin >> number) || number > 1000 || number < -1000) {
      cout << "INVALID\n";
      return 2;
    }
  }

  vector<int> sortedNumbers = numbers;

  sort(sortedNumbers.begin(), sortedNumbers.end());

  return 0;
}