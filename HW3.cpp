#include <stack>
#include <queue>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <iostream>
#include<limits>
#include<algorithm>


/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
I approached this problem by using a map to set each location for both the recipe and ingredient locations.
Once I had each character map I began to compare if the ingredient(bucket) map contained the enough of each char needed to fulfill the recipe. I then use division to determine how many copies of the recipe i can create.
 * Why does your code work?
 My code works because it efficeiently maps the characters in order to quickly determine if a valid amount of characters is availaible. 


 *
 */
int countLegoHouses(std::string recipe, std::string bucket) {
  int count =0;
  if(recipe.empty()){
    throw std::invalid_argument("ERROR: Empty String");
  }

std::unordered_map<char, int> recipe_map;
for (auto v: recipe) {
  if (recipe_map.count(v)) {
    recipe_map[v]++;
    } else {
      recipe_map[v] = 1;
      }
  }

std::unordered_map<char, int> ingredient_map;
for (auto z: bucket) {
  if (ingredient_map.count(z)) {
    ingredient_map[z]++;
    } else {
      ingredient_map[z] = 1;
  }
 
}

int min = std::numeric_limits<int>::max();
int temp =0;

for(auto lego: recipe_map){
  if(ingredient_map[lego.first] / recipe_map[lego.first] == 0) {
    return 0;
  }

  if( min > ingredient_map[lego.first] / recipe_map[lego.first]) {
    min = ingredient_map[lego.first] / recipe_map[lego.first];
  }
}

return min;
}

/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 In this problem I decided to sort each word and then use the sorted word as a key. This allowed me to map all words with the same letters to a specific index. I placed all matching strings into a mapped vector. Once I completed this, I searched for the vector with the most words and rerturned it.
 * Why does your code work?
 My code works because I effieciently map all words in order to find the largest group of anagrams.
 *
 */
std::vector<std::string> findLargestAnagroup(const std::vector<std::string>& words) {
  //throw std::logic_error("not implemented");  
  std::unordered_map <std::string, std::vector<std::string> > wordMap;
  for(auto word : words) {
    std::string sortedWord = word;
    std::sort(sortedWord.begin(), sortedWord.end());
    wordMap[sortedWord].push_back(word);
  }

  int max = 0;
  std::vector<std::string> mostAMG;

  for (auto x : wordMap) {
    if(wordMap[x.first].size() > max) {
      max = x.second.size();
      mostAMG = x.second;
    }
  }

  return mostAMG;
}

/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 In this problem I decided to use pairing in order to keep track of the specific number I was coparing and the rest of the digits in a given vector. I also created a min heap. I used the digit within each pair to sort the heap. Once I return a pair from the heap. I place it in the new sorted vector and then proceded to push the next eleemnt in the sub vector or not depending if the vector is empty or not.
 
 * Why does your code work?

 My code works because it uses a heap to quickly find the complete minimum when comparing the minimum value of each sub vector. 
 *
 */
std::vector<double> mergeSortedLists(const std::vector<std::vector<double>>& sortedVecs) {
  typedef std::pair<double, std::vector<double>> pa;
  std::priority_queue<pa, std::vector<pa>, std::greater<pa>> heap;
  std::vector<double> sortedValues; 


  for(auto vec : sortedVecs) {
    if(!vec.empty()) {
      heap.push(std::make_pair(vec.front(), vec));
    }
  }
  
  while(!heap.empty()) {
    sortedValues.push_back(heap.top().first); //insert minimum to vector
    pa removed = heap.top(); // temp to store the head pair of the heap
    if(removed.second.size() > 1) { // remove first element of removed vector if there is at least 2 elements else just pop 
      removed.second.erase(removed.second.begin());
      heap.pop();
      heap.push(std::make_pair(removed.second.front(), removed.second));
    }
    else {
      heap.pop();
    }
  
  }
  return sortedValues;

}