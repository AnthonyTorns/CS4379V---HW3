#include <stack>
#include <queue>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <iostream>
#include<limits>


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
  throw std::logic_error("not implemented");  
}

/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 *
 */
std::vector<double> mergeSortedLists(const std::vector<std::vector<double>>& sortedVecs) {
  throw std::logic_error("not implemented");
}