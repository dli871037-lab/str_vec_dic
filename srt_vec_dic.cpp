/*************************************
* Автор: ДанИИл Ли                   *
* Задание: Строки, векторы и словари *
* Вариант: 13                        *
*************************************/
 
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  constexpr int maxNumberMod = 1000;
  constexpr int maxCount = 100;
  constexpr int maxLenghth = 200;

  unsigned char currentLetter;
  string phrase;
  string result;


  if (!(getline(cin, phrase)) || size(phrase) > maxLenghth || size(phrase) < 1) {
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

  cout << "\nCount of numbers: ";
  cin >> countOfNumbers;

  if (countOfNumbers > 99) {
    cout << "INVALID\n";
    return 2;
  }

  for (int indexOfNumbers = 0; indexOfNumbers < countOfNumbers; ++indexOfNumbers) {
    if (!(cin >> number) || number > maxNumberMod || number < -maxNumberMod) {
      cout << "INVALID\n";
      return 2;
    } else {
      numbers.push_back(number);
    }
  }

  vector<int> sortedNumbers = numbers;
  int maxNumberIndex = sortedNumbers.size() - 1;

  sort(sortedNumbers.begin(), sortedNumbers.end());

  for (int indexInNumbers = 0; indexInNumbers < countOfNumbers; ++indexInNumbers) {
    if (sortedNumbers[maxNumberIndex] == numbers[indexInNumbers]) {
      numbers.erase(numbers.begin() + indexInNumbers);
      break;
    }
  }

  for (int number : numbers) {
    cout << number << " ";
  }

  // ===== Часть C — Ключ максимального значения =====
  map<string, int> dictionary;
  int countOfPairs;
  cin >> countOfPairs; 

  for (int indexOfPair = 0; indexOfPair < countOfPairs; ++indexOfPair) {
    string key;
    int value = 0;

    if (!(cin >> key >> value)) {
      cout << "INVALID\n";
      return 3;
    }
    dictionary[key] = value;
  }

  cout << "\n";

  if (dictionary.empty()) {
    cout << "NONE\n";
  } else {
    auto bestPair = dictionary.begin();
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
      if (it->second > bestPair->second) {
        bestPair = it;
      }
    }
    cout << bestPair->first << " " << bestPair->second << "\n";
  }
  return 0;
}