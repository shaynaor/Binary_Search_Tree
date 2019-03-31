/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  ariel::Tree tree;//our test
  ariel::Tree tree2;

 
  int dataArr[] = {21,30,5,7,14,4,25,26,13,10};

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

  /* Our first tests */
  
  .CHECK_EQUAL (tree.size(), 0)
  .CHECK_OK    (tree.insert(7))
  .CHECK_OK    (tree.insert(3))
  .CHECK_EQUAL (tree.size(), 2)
  .CHECK_EQUAL (tree.root(), 7)
  .CHECK_EQUAL (tree.left(7), 3)
  .CHECK_THROWS (tree.right(7))
  .CHECK_OK    (tree.insert(8))
  .CHECK_EQUAL (tree.right(7), 8)
  .CHECK_EQUAL (tree.contains(8), true)
  .CHECK_EQUAL (tree.contains(7), true)
  .CHECK_EQUAL (tree.contains(3), true)
  .CHECK_EQUAL (tree.contains(0), false)
  .CHECK_EQUAL (tree.size(), 3) 
  .CHECK_EQUAL (tree.parent(8), 7)
  .CHECK_EQUAL (tree.parent(3), 7)
  .CHECK_OK    (tree.remove(7))
  .CHECK_OK    (tree.remove(3))  
  .CHECK_OK    (tree.remove(8))
  .CHECK_EQUAL (tree.size(), 0)
 
/* Our second test */
/* Inserting 10 elements to the tree and checks size,and contain */
  
 .CHECK_EQUAL (tree2.size(), 0)
 .CHECK_OK    (tree2.insert(dataArr[0]))
 .CHECK_EQUAL (tree2.contains(dataArr[0]), true)


 .CHECK_EQUAL (tree2.size(), 1)
 .CHECK_OK    (tree2.insert(dataArr[1]))
 .CHECK_EQUAL (tree2.contains(dataArr[1]), true)


 .CHECK_EQUAL (tree2.size(), 2)
 .CHECK_OK    (tree2.insert(dataArr[2]))
 .CHECK_EQUAL (tree2.contains(dataArr[2]), true)

 .CHECK_EQUAL (tree2.size(), 3)
 .CHECK_OK    (tree2.insert(dataArr[3]))
 .CHECK_EQUAL (tree2.contains(dataArr[3]), true)

 .CHECK_EQUAL (tree2.size(), 4)
 .CHECK_OK    (tree2.insert(dataArr[4]))
 .CHECK_EQUAL (tree2.contains(dataArr[4]), true)

 .CHECK_EQUAL (tree2.size(), 5)
 .CHECK_OK    (tree2.insert(dataArr[5]))
 .CHECK_EQUAL (tree2.contains(dataArr[5]), true)

 .CHECK_EQUAL (tree2.size(), 6)
 .CHECK_OK    (tree2.insert(dataArr[6]))
 .CHECK_EQUAL (tree2.contains(dataArr[6]), true)

 .CHECK_EQUAL (tree2.size(), 7)
 .CHECK_OK    (tree2.insert(dataArr[7]))
 .CHECK_EQUAL (tree2.contains(dataArr[7]), true)

 .CHECK_EQUAL (tree2.size(), 8)
 .CHECK_OK    (tree2.insert(dataArr[8]))
 .CHECK_EQUAL (tree2.contains(dataArr[8]), true)

 .CHECK_EQUAL (tree2.size(), 9)
 .CHECK_OK    (tree2.insert(dataArr[9]))
 .CHECK_EQUAL (tree2.contains(dataArr[9]), true)


/* Checking perents and left right children */

 .CHECK_EQUAL (tree2.parent(30), 21)
 .CHECK_EQUAL (tree2.parent(5), 21)
 .CHECK_EQUAL (tree2.parent(4), 5)
 .CHECK_EQUAL (tree2.parent(7), 5)
 .CHECK_EQUAL (tree2.parent(14), 7)
 .CHECK_EQUAL (tree2.parent(13), 14)
 .CHECK_EQUAL (tree2.parent(10), 13)
.CHECK_EQUAL (tree2.parent(26), 25)
 .CHECK_EQUAL (tree2.parent(25), 30)

 .CHECK_EQUAL (tree2.right(21), 30)
 .CHECK_EQUAL (tree2.right(5), 7)
 .CHECK_EQUAL (tree2.right(7), 14)
 .CHECK_EQUAL (tree2.right(25), 26)
 
 .CHECK_EQUAL (tree2.left(21), 5)
 .CHECK_EQUAL (tree2.left(5), 4)
 .CHECK_EQUAL (tree2.left(30), 25)
 .CHECK_EQUAL (tree2.left(14), 13)
 .CHECK_EQUAL (tree2.left(13), 10)
 

 /* Checking removing from the tree, conteins, size , root, parent, left and right*/

.CHECK_EQUAL (tree2.size(), 10)
.CHECK_EQUAL (tree2.root(), 21)
.CHECK_OK    (tree2.remove(21))
.CHECK_EQUAL (tree2.root(), 14)
.CHECK_EQUAL (tree2.size(), 9)
.CHECK_EQUAL (tree2.left(14), 5)
.CHECK_EQUAL (tree2.right(14), 30)
.CHECK_EQUAL (tree2.contains(21), false)

.CHECK_OK    (tree2.remove(14))
.CHECK_EQUAL (tree2.contains(14), false)
.CHECK_EQUAL (tree2.root(), 13)
.CHECK_EQUAL (tree2.size(), 8)
.CHECK_EQUAL (tree2.left(13), 5)
.CHECK_EQUAL (tree2.right(13), 30)

.CHECK_OK    (tree2.remove(13))
.CHECK_EQUAL (tree2.contains(13), false)
.CHECK_EQUAL (tree2.root(), 10)
.CHECK_EQUAL (tree2.size(), 7)
.CHECK_EQUAL (tree2.left(10), 5)
.CHECK_EQUAL (tree2.right(10), 30)

.CHECK_OK    (tree2.remove(5))
.CHECK_EQUAL (tree2.contains(5), false)
.CHECK_EQUAL (tree2.root(), 10)
.CHECK_EQUAL (tree2.size(), 6)
.CHECK_EQUAL (tree2.left(10), 4)
.CHECK_EQUAL (tree2.right(4), 7)

.CHECK_OK    (tree2.remove(10))
.CHECK_EQUAL (tree2.contains(10), false)
.CHECK_EQUAL (tree2.root(), 7)
.CHECK_EQUAL (tree2.size(), 5)
.CHECK_EQUAL (tree2.left(7), 4)
.CHECK_EQUAL (tree2.right(7), 30)

.CHECK_OK    (tree2.remove(7))
.CHECK_EQUAL (tree2.contains(7), false)
.CHECK_EQUAL (tree2.root(), 4)
.CHECK_EQUAL (tree2.size(), 4)
.CHECK_EQUAL (tree2.right(4), 30)

.CHECK_OK    (tree2.remove(26))
.CHECK_EQUAL (tree2.contains(26), false)
.CHECK_EQUAL (tree2.root(), 4)
.CHECK_EQUAL (tree2.size(), 3)
.CHECK_EQUAL (tree2.right(4), 30)

.CHECK_EQUAL (tree2.parent(30), 4)

.CHECK_OK    (tree2.remove(30))
.CHECK_EQUAL (tree2.contains(30), false)
.CHECK_EQUAL (tree2.root(), 4)
.CHECK_EQUAL (tree2.size(), 2)
.CHECK_EQUAL (tree2.right(4), 25)

.CHECK_EQUAL (tree2.parent(25), 4)

.CHECK_OK    (tree2.remove(4))
.CHECK_EQUAL (tree2.contains(4), false)
.CHECK_EQUAL (tree2.root(), 25)
.CHECK_EQUAL (tree2.size(), 1)

.CHECK_OK    (tree2.remove(25))
.CHECK_EQUAL (tree2.contains(25), false)
.CHECK_EQUAL (tree2.size(), 0)

/* Insert to the tree after removing all the nodes. */

.CHECK_EQUAL (tree2.size(), 0)
.CHECK_OK    (tree2.insert(dataArr[0]))
.CHECK_EQUAL (tree2.contains(dataArr[0]), true)


.CHECK_EQUAL (tree2.size(), 1)
.CHECK_OK    (tree2.insert(dataArr[1]))
.CHECK_EQUAL (tree2.contains(dataArr[1]), true)


.CHECK_EQUAL (tree2.size(), 2)
.CHECK_OK    (tree2.insert(dataArr[2]))
.CHECK_EQUAL (tree2.contains(dataArr[2]), true)

.CHECK_EQUAL (tree2.size(), 3)
.CHECK_OK    (tree2.insert(dataArr[3]))
.CHECK_EQUAL (tree2.contains(dataArr[3]), true)






.print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
