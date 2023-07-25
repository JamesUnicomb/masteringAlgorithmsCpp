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
```