# Set

## Compile 

```
g++ main.cpp -std=c++11
```

## Run

### Windows

```
.\a.exe
```

### Linux

```
./a.out
```

## Output

```
a = {1,2,3,4,5}
b = {4,5,6}
c = {1,2,3}
setInsersection(a,b) = {4,5}
setUnion(a,b) = {1,2,3,4,5,6}
isSubset(a,b) = 0
isSubset(c,a) = 1
```

## Deleting a Set

Extra compile flags have can be activated to view the deletion debugging. This is a very interesting example because we are using a linked list representation to traverse the tree nodes in order.

```
g++ main.cpp -std=c++11 -DDEBUG=true
```

### The new output

```
a = {1,2,3,4,5}
b = {4,5,6}
c = {1,2,3}
setInsersection(a,b) = {4,5}
~TreeNode<T>(5)                    # start of delete intersection(a,b) created by the function call
~TreeNode<T>(4)
setUnion(a,b) = {1,2,3,4,5,6}
~TreeNode<T>(1)                    # start of delete union(a,b) created by the function call
~TreeNode<T>(2)
~TreeNode<T>(3)
~TreeNode<T>(5)
~TreeNode<T>(6)
~TreeNode<T>(4)                    
isSubset(a,b) = 0
isSubset(c,a) = 1
~TreeNode<T>(1)                    # start of delete c={1,2,3} set as it goes out of scope
~TreeNode<T>(3)
~TreeNode<T>(2)
~TreeNode<T>(4)                    # start of delete b={4,5,6} set as it goes out of scope
~TreeNode<T>(6)
~TreeNode<T>(5)
~TreeNode<T>(1)                    # start of delete a={1,2,3,4,5} set as it goes out of scope
~TreeNode<T>(3)
~TreeNode<T>(4)
~TreeNode<T>(5)
~TreeNode<T>(2)
```