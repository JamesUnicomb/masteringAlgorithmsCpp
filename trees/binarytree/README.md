# Balanced Binary Tree

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
level order: 3 1 5 0 2 4 6 7 
DisplayBegin:
0 1 2 3 4 5 6 7
:DisplayEnd
B:3,4,1
 L:1,2,0
  L:0,1,0
  R:2,1,0
 R:5,3,1
  L:4,1,0
  R:6,2,1
   R:7,1,0
height = 4
size = 8
B:4,3,0
 L:1,2,0
  L:0,1,0
  R:2,1,0
 R:5,2,1
  R:6,1,0
height = 3
size = 6
0-1-2-4-5-6-nullptr
found:0
found:1
found:2
did not find:3
found:4
found:5
found:6
did not find:7
did not find:8
did not find:9
did not find:10
did not find:11
iterator display start:
0 1 2 4 5 6
:iterator display finish
```

## Deleting a Tree and its Nodes

Extra compile flags have can be activated to view the deletion debugging. This is a nice example of post order traversal of a tree. We wish to visit every child first and start deletion only after reaching the leaves.

```
g++ main.cpp -std=c++11 -DDEBUG=true
```

### The new output

```
level order: 3 1 5 0 2 4 6 7 
DisplayBegin:
0 1 2 3 4 5 6 7 
:DisplayEnd
B:3,4,1
 L:1,2,0
  L:0,1,0
  R:2,1,0
 R:5,3,1
  L:4,1,0
  R:6,2,1
   R:7,1,0
height = 4
size = 8
~TreeNode<T>(7)                       # deletion when calling remove
~TreeNode<T>(4)                       # deletion when calling remove
B:4,3,0
 L:1,2,0
  L:0,1,0
  R:2,1,0
 R:5,2,1
  R:6,1,0
height = 3
size = 6
0-1-2-4-5-6-nullptr
found:0
found:1
found:2
did not find:3
found:4
found:5
found:6
did not find:7
did not find:8
did not find:9
did not find:10
did not find:11
iterator display start:
0 1 2 4 5 6
:iterator display finish
~TreeNode<T>(0)                       # deletion when Tree goes out of scope
~TreeNode<T>(1)                       # deletion when Tree goes out of scope
~TreeNode<T>(2)                       # deletion when Tree goes out of scope
~TreeNode<T>(5)                       # deletion when Tree goes out of scope
~TreeNode<T>(6)                       # deletion when Tree goes out of scope
~TreeNode<T>(4)                       # deletion when Tree goes out of scope
```