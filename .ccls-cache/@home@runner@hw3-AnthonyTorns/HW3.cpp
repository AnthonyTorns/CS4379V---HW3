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
 * Why does your code work?
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
 * Why does your code work?
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
 
 * Why does your code work?
 *
 */

 //std::priority_queue<double, std::vector<double>, std::greater<double>> heap;
  
  //int size = sortedVecs.size();
  //std::cout<<size<<std::endl;
// while(size > 0) {
//   for(auto vec : sortedVecs) {
//     //std::cout<<"here"<<std::endl;
//     if(!vec.empty()) {
//       heap.push(vec.front());
//       vec.erase(vec.begin());
      
//       if(heap.size() == sortedVecs.size()) {
//         sortedValues.push_back(heap.top());
//         heap.pop();
//       }
      
//       if(vec.empty()) {
//         size--;
//       }
//     }
    
//   }
// }
std::vector<double> mergeSortedLists(const std::vector<std::vector<double>>& sortedVecs) {
  //throw std::logic_error("not implemented");
  //std::cout<<"here";
  typedef std::pair<double, std::vector<double>> pa;
  std::priority_queue<pa, std::vector<pa>, std::greater<pa>> heap;
  std::vector<double> sortedValues; 


  for(auto vec : sortedVecs) {
    //std::cout<<vec.front()<<" ";
    heap.push(std::make_pair(vec.front(), vec));
    //vec.erase(vec.begin());
    //std::cout<<vec.front()<<std::endl;
  }
  
  while(!heap.empty()) {

  //std::vector<double> removed = heap.top().second;
  sortedValues.push_back(heap.top().first); //insert minimum to vector
  pa removed = heap.top(); // temp to store the head pair of heap
  if(removed.second.size() > 1) {
    removed.second.erase(removed.second.begin());
    heap.pop();
    heap.push(std::make_pair(removed.second.front(), removed.second));
  }
  else {
    heap.pop();
  }
  //heap.push(std::make_pair(removed.front(), removed));
  }

  

  std::vector<double> l;
  return sortedValues;

}