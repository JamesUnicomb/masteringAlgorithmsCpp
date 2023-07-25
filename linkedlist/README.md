# Linked List

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
linked list example
1-2-3-4-5-nullptr
size = 5
head = 1
tail = 5
5-4-3-2-1-nullptr
size = 5
head = 5
tail = 1
4-3-2-1-nullptr
size = 4
head = 4
tail = 1
6-4-3-2-1-nullptr
size = 5
head = 6
tail = 0
0-nullptr
size = 1
head = 0
tail = 0
nullptr
size = 0
head = nullptr
```

## Deleting a Linked List and its Nodes

Extra compile flags have can be activated to view the deletion debugging. 

```
g++ main.cpp -std=c++11 -DDEBUG=true
```

### The new output

```
linked list example
1-2-3-4-5-nullptr
size = 5
head = 1
tail = 5
5-4-3-2-1-nullptr
size = 5
head = 5
tail = 1
~LListElmt<T>(5)
4-3-2-1-nullptr
size = 4
head = 4
tail = 1
6-4-3-2-1-nullptr
size = 5
head = 6
tail = 1
6-4-3-2-1-0-nullptr
size = 6
head = 6
tail = 0
~LListElmt<T>(6)                       # deletion when calling remove
~LListElmt<T>(4)                       # deletion when calling remove
~LListElmt<T>(3)                       # deletion when calling remove
~LListElmt<T>(2)                       # deletion when calling remove
~LListElmt<T>(1)                       # deletion when calling remove
0-nullptr
size = 1
head = 0
tail = 0
~LListElmt<T>(0)                       # deletion when calling remove
nullptr
size = 0
head = nullptr
tail = nullptr
~LListElmt<T>(11)                       # deletion when LList goes out of scope
~LListElmt<T>(10)                       # deletion when LList goes out of scope
~LListElmt<T>(12)                       # deletion when LList goes out of scope
```