#include <iostream>

#include "sort.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "usage: bin/sort <option> <test_file_path>\n";
    std::cout << "\t options: m (merge sort), q (quick sort)\n";
    std::exit(EXIT_SUCCESS);
  }

  std::string file_path(argv[2]);
  std::ifstream fs(file_path, std::ios::binary);

  if (!fs.is_open()) {
    std::cout << "ERROR: Failed to open file: " + file_path << std::endl;
    std::exit(EXIT_FAILURE);
  }

  int32_t num = 0;
  fs >> num;

  std::vector<int64_t> in(num, 0);
  for (auto& i : in) fs >> i;
  fs.close();

  char select = argv[1][0];
  if (select == 'm') {
    mergeSort(in);
  } else if (select == 'q') {
    quickSort(in);
  } else {
    std::cout << "\"" << select << "\" - is not a valid option\n";
    std::exit(EXIT_FAILURE);
  }


  std::ofstream ofs("output.txt", std::ios::binary);
  for (auto& i : in) ofs << (int64_t)i << "\n";

  ofs.close();

  std::exit(EXIT_SUCCESS);
}
