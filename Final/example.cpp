#include <iostream>
#include <vector>
#include <algorithm>

// int main()
// {
//     std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4};
//     auto newEnd = std::unique(vec.begin(), vec.end());
//     vec.erase(newEnd, vec.end()); // Erase the "removed" elements

//     for (const auto& v : vec) {
//         std::cout << v << " ";
//     }
    
// }

// Recursive function to generate all permutations of a string
#include <iostream>

#include <string>

// Function to generate all permutations of a string
void generate_Permutations(std::string text, int left, int right) {
  // Base case: if left and right indices are the same, we have a complete permutation
  if (left == right) {
    std::cout << text << std::endl; // Output the generated permutation
    return;
  }

  // Recursive case: swap each character with the character at the left index,
  // and recursively generate permutations for the rest of the string
  for (int i = left; i <= right; i++) {
    std::swap(text[left], text[i]); // Swap characters
    generate_Permutations(text, left + 1, right); // Recursively generate permutations
    std::swap(text[left], text[i]); // Backtrack by swapping back the characters
  }
}

int main() {
  std::string text;
  std::cout << "Input a string: ";
  std::cin >> text;

  std::cout << "All permutations of the string: " << std::endl;
  generate_Permutations(text, 0, text.length() - 1); // Generate permutations

  return 0;
}
