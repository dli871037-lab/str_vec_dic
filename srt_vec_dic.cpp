/*************************************
* Автор: Даниил Ли                   *
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
  string phrase, result;

  cout << "Entry the phrase: ";

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

  if (result.empty()) {
    cout << "\nEMPTY";
  }
  else {
    cout << result;
  }


  vector<int> numbers;
  int countOfNumbers;
  int number;

  cout << "\nCount of numbers: ";
  cin >> countOfNumbers;

  if (countOfNumbers >= maxCount) {
    cout << "INVALID\n";
    return 2;
  }

  for (int indexOfNumbers = 0; indexOfNumbers < countOfNumbers; ++indexOfNumbers) {
    if (!(cin >> number) || number > maxNumberMod || number < -maxNumberMod) {
      cout << "INVALID\n";
      return 2;
    }
    else {
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
  cout << "Without max element: ";

  for (int& num : numbers) {
    cout << num << " ";
  }

  map<string, int> dictionary;
  int countOfPairs;
  int value = 0;
  string key;

  cout << "\nEntry count of pairs: ";
  cin >> countOfPairs;
  cout << "First - key" << endl
    << "Second - value\n";

  for (int indexOfPair = 0; indexOfPair < countOfPairs; ++indexOfPair) {

    if (!(cin >> key >> value)) {
      cout << "INVALID\n";
      return 3;
    }
    dictionary[key] = value;
  }

  if (dictionary.empty()) {
    cout << "NONE\n";
  }
  else {
    auto bestPair = dictionary.begin();
    for (auto iterations = dictionary.begin(); iterations != dictionary.end(); ++iterations) {
      if (iterations->second > bestPair->second) {
        bestPair = iterations;
      }
    }
    cout << "Max value pair: " << bestPair->first << " " << bestPair->second;
  }
  return 0;
}
