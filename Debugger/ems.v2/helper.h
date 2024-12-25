#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::shared_ptr;

#include "course.h"

namespace Faculty {

struct Helper {
  static double Probability();
  /*
   * Read an integer from the stream and do necessary validations.
   *
   * @param low the minimum expected value
   * @param high the maximum expected value
   *
   * @return: integer read from cin stream validated again low and high ranges
   */
  static int ReadInt(int low, int high);

  /*
   * Convert integer to string and append zeros to have the given length
   */
  static string ToString(int val, int length);

  static int RunMenu(vector<string> &menu);

  // Let's declare/implement template methods here

  /*
   * Given a vector of some type, return a random subset of it.
   */
  template<typename Type>
  static vector<Type> GetRandomSubset(const vector<Type> &vec_data) {
    vector<Type> retrunVec;

    for (auto element : vec_data) {
      if (1.0 * rand() / RAND_MAX > 0.7)
        retrunVec.push_back(element);
    }
    return retrunVec;
  }

  /*
   * Given a vector of some type, return a random subset of it of given minimum length.
   */
  template<typename Type>
  static vector<Type> GetRandomSubset(const vector<Type> &vec_data, int min_length) {
    assert((int )vec_data.size() >= min_length);

    vector<int> indices;

    for (size_t i = 0; i < vec_data.size(); ++i)
      indices.push_back(i);

    // now indices = 0 1 2 ... n-1

    std::random_shuffle(indices.begin(), indices.end());

    // now indices is some random permutation

    vector<Type> retrunVec;

    for (int i = 0; i < min_length; ++i)
      retrunVec.push_back(vec_data[indices[i]]);

    return retrunVec;
  }

  template<typename Type>
  static void RemoveElement(vector<shared_ptr<Type>> &vec_data, shared_ptr<Type> element) {
    for (int i = 0; i < (int) vec_data.size(); ++i) {
      if (vec_data[i] == element) {
        vec_data.erase(vec_data.begin() + i);
        --i;
      }
    }
  }

};

}


#endif // HELPER_H_INCLUDED
