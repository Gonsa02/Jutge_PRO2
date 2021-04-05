#include "BinTree.hh"
using namespace std;

pair<BinTree<int>, int> lengthDifference(const BinTree<int>& tree) {
  if (tree.empty()) {
      BinTree<int> empty;
    return { empty, 0 };
  }
  int leftLength = 0;
  int rightLength = 0;
  BinTree<int> left;
  BinTree<int> right;

  if (not tree.left().empty()) {
    pair<BinTree<int>, int> res = lengthDifference(tree.left());
    left = res.first;
    leftLength = res.second;
  }
  if (not tree.right().empty()) {
    pair<BinTree<int>, int> res = lengthDifference(tree.right());
    right = res.first;
    rightLength = res.second;
  }

  int length = max(leftLength, rightLength);

  int node = leftLength - rightLength;
  BinTree<int> final_tree (node, left, right);

  return { final_tree, 1 + length };

}

void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    agd = lengthDifference(a).first;
}
