#include <iostream>
#include <vector>
using namespace std;
/**  if num = 5, the output is:
 *      [
 *            [1],        --------------1  res[0]
 *           [1,1],       --------------2  res[1]
 *          [1,2,1],      --------------3  res[2]
 *         [1,3,3,1],     --------------4  res[3]
 *        [1,4,6,4,1]     --------------5  res[4]
 *      ]
 *
 *
 */
class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    vector<vector<int> >res;
    if(numRows == 0)return res;
    vector<int> row;
    row.push_back(1);
    res.push_back(row);
    if(numRows == 1){return res;} // if numRows == 1, only {1} res[0]
    row.push_back(1); // update row, prepare for numRows == 2 {1,1} res[1]
    res.push_back(row);
    if(numRows == 2){return res;}

    for(int i = 2; i < numRows; i++) { // i is the index of res
      vector<int> temp(i + 1, 1); // each layer has i+1 element, initial all element is "1"
      for (int j = 1; j < i; j++) {  //last one (i+1)th does not need update
        temp[j] = res[i - 1][j] + res[i - 1][j - 1]; //
      }
      res.push_back(temp);
    }
    return res;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}