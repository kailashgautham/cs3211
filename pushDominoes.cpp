#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  string pushDominoes(string dominoes) {
    stack<int> lQueue;
    queue<int> rQueue;
    string l = "";
    string r = "";
    for (int i = 0; i < dominoes.size(); i++) {
      if (dominoes[i] == 'L')
        lQueue.push(i);
      if (dominoes[i] == 'R')
        rQueue.push(i);
    }
    int invalidIdx = dominoes.size() - 1;
    for (int i = dominoes.size() - 1; i > -1; i--) {
      if (dominoes[i] == 'L')
        l = l + 'L' + ('.');
      else if (dominoes[i] == 'R') {
        invalidIdx = i;
        l = l + ('R') + ('.');
      } else if (lQueue.size() == 0 || lQueue.top() < i ||
                 invalidIdx < lQueue.top()) {
        l = l + ('-') + ('.');
        if (lQueue.size() > 0)
          lQueue.pop();
      } else
        l = l + (char)('0' + (lQueue.top() - i)) + ('.');
      if (lQueue.size() > 0 && lQueue.top() > invalidIdx)
        lQueue.pop();
    }
    reverse(l.begin(), l.end());
    l.erase(l.begin());
    return l;
  }
};

int main() {
  Solution s;
  string dominoes = ".L.R...LR..L..";
  string result = s.pushDominoes(dominoes);
  return 0;
}

// .L.R...LR..L..

// L changes: 1L-R321LR21L--
// R changes: -L-R012LR01L--

// LL.RR.LLRRLL..
// -L-R---LR21L--
