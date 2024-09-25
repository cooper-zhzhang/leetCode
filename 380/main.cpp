#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <vector>

class RandomizedSet {
public:
  std::default_random_engine e;
  RandomizedSet() {
    e.seed(time(0));

    srand(0);
  }

  bool insert(int val) {

    auto mapIt = m_posMap.find(val);
    if (mapIt != m_posMap.end()) {
      return false;
    }

    m_dataVec.push_back(val);
    m_posMap[val] = m_dataVec.size();

    return true;
  }

  bool remove(int val) {

    auto mapIt = m_posMap.find(val);
    if (mapIt == m_posMap.end()) {
      return false;
    }

    int index = mapIt->second;
    m_dataVec[index] = m_dataVec[m_dataVec.size() - 1];
    m_dataVec.pop_back();

    m_posMap.erase(mapIt);

    return true;
  }

  int getRandom() {

    int a = rand() % m_dataVec.size();

    return m_dataVec[a];
  }

private:
  std::set<int> m_data;

  std::map<int, int> m_posMap;
  std::vector<int> m_dataVec;
};

int main() {

  RandomizedSet mySet;
  std::cout << mySet.insert(1) << std::endl;
  std::cout << mySet.remove(2) << std::endl;
  std::cout << mySet.insert(2) << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.remove(1) << std::endl;
  std::cout << mySet.insert(2) << std::endl;
  std::cout << mySet.insert(10) << std::endl;
  std::cout << mySet.insert(20) << std::endl;
  std::cout << mySet.insert(30) << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;
  std::cout << mySet.getRandom() << std::endl;

  //, "insert", "remove", "insert", "getRandom", "remove", "insert",
  //"getRandom"]
  //`[1], [2], [2], [], [1], [2], []]
  return 0;
}

// 8eFE4T2ifceSxca
