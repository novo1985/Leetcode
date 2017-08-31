/* Given a string, sort it in decreasing order based on the frequency of characters.*/
class Solution {
public:
    typedef pair<int, int> PAIR;

    bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
      return lhs.second > rhs.second;
    }

    string frequencySort(string s) {
      if(s.empty()) { return s; }
      unordered_map<char, int> map;
      for(const auto& it : s){
        map[it]++;
      }//o(n) record each char's frequency

      //sort map(tree structure) by value, put all element into vector(linear structure)
      vector<PAIR> vec(map.begin(), map.end());
      sort(vec.begin(), vec.end(), cmp_by_value);//

      //
      sting res;
      for(int i = 0; i < vec.size(); i++){
        res += to_string(vec[i].first);
      }

      return res;
    }
};