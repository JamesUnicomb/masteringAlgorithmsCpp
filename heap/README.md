# Heap

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
0 
1 0 
2 0 1 
3 2 1 0 
4 3 1 0 2 
5 3 4 0 2 1 
6 3 5 0 2 1 4 
7 6 5 3 2 1 4 0 
8 7 5 6 2 1 4 0 3 
9 8 5 6 7 1 4 0 3 2 
size = 10
9 8 5 6 7 1 4 0 3 2 
8 7 5 6 2 1 4 0 3 
extracted : 9
size = 9
```