
/* Example usage */


#include "bst.hpp" /* In same directory */

int main(void)
{
  using namespace ads;
  BinarySearchTree<int> tree(100); 

  tree.insertValue(20);
  tree.insertValue(50);
  tree.insertValue(60);
  std::cout << "In Order Traversal" << std::endl;
  tree.traverseInOrder();

  tree.insertValue(90);
  tree.insertValue(200);
  std::cout << "Pre Order Traversal" << std::endl;
  tree.traversePreOrder();

  tree.insertValues({99, 120, 300, 60, 34});
  std::cout << "Post Order Traversal" << std::endl;
  tree.traversePostOrder();


  std::cout << "Find Key 61: " << tree.keySearch(61) << std::endl;
  std::cout << "Height: " << tree.depth() << std::endl;

   std::cout << "In Order Regular Tree: " << std::endl;
  tree.traverseInOrder([](int a) { std::cout << "Custom Lambda Printed Key: " << a << std::endl; });
  tree.invertTree();
  std::cout << "In Order Inverted Tree: " << std::endl;
  tree.traverseInOrder();

}

