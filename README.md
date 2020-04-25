# Programming Assignment 5: Hash-Based Data Structures
In this Programming Assignment, you will be assessing your understanding of hash-based data structures.

## Part 1: Probability of Collisions (25 points)
For each of the following questions, assume we are using a hash function that will distribute elements uniformly across the backing array.

### Task 1a: Create ``1a.txt`` (5 points)
Imagine we have a hash table with the following backing array, where X denotes that a given cell contains an element (regardless of what that element actually is):

|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|     |     |  X  |  X  |     |     |  X  |     |  X  |     |

What is the probability that the **next insertion will not cause a collision**? Create a file called ``1a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single decimal number) rounded to 3 decimal places.

### Task 1b: Create ``1b.txt`` (5 points)
Imagine we have a hash table with the following backing array, where X denotes that a given cell contains an element (regardless of what that element actually is):

|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  X  |     |  X  |     |     |     |     |     |  X  |     |

What is the probability that the **next 3 insertions will not cause any collisions**? Create a file called ``1b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single decimal number) rounded to 3 decimal places.

### Task 1c: Create ``1c.txt`` (5 points)
Imagine we have a hash table with the following backing array, where X denotes that a given cell contains an element (regardless of what that element actually is):

|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  X  |     |  X  |     |  X  |     |     |     |  X  |     |

### Task 1d: Create ``1d.txt`` (5 points)
Imagine we have a hash table with the following backing array, where X denotes that a given cell contains an element (regardless of what that element actually is):

|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  X  |     |  X  |     |  X  |     |     |     |  X  |     |

Assuming we use **linear probing** to resolve collisions, what is the probability that we will have **exactly 1 collision in the next 2 insertions**? Create a file called ``1d.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single decimal number) rounded to 3 decimal places.

### Task 1e: Create ``1e.txt`` (5 points)
Imagine we have a hash table with the following backing array, where X denotes that a given cell contains an element (regardless of what that element actually is):

|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  X  |     |  X  |     |  X  |     |     |     |  X  |     |

Assuming we use **separate chaining** to resolve collisions, what is the probability that we will have **exactly 1 collision in the next 2 insertions**? Create a file called ``1e.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single decimal number) rounded to 3 decimal places.

## Part 2: Bloom Filters (40 points)
In an ideal world, we would like to use a Hash Table to store a set of elements because of its O(1) average-case time complexity for find, insert, and remove operations. In practice, however, we may face datasets that are too large to fit into memory at once. In these cases, we can use the [Bloom filter](https://en.wikipedia.org/wiki/Bloom_filter), which is a probabilistic data structure that never has false negatives (i.e., if it tells us *x* doesn't exist, *x* definitely doesn't exist), but that may have false positives (i.e., if it tells us that *x* exists, *x* might not actually exist).

### Task: Edit [``BloomFilter.cpp``](BloomFilter.cpp)
In this repository, there is a file called [``BloomFilter.cpp``](BloomFilter.cpp) that contains initial steps towards implementing a Bloom filter. Function headers (with usage details) are included in [``BloomFilter.h``](BloomFilter.h), and you need to fill in the ``insert()`` and ``find()`` functions of the ``BloomFilter`` class. We will not be checking for memory leaks, as you should not be dynamically allocating any memory.

We have provided a tester program, [``BloomFilterTest``](BloomFilterTest.cpp), that will help test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -g -O0 -std=c++11 -o BloomFilterTest BloomFilterTest.cpp BloomFilter.cpp HashFunctions.cpp
```

Here's an example of how it should look like when it's compiled and run from the command line:

```bash
$ g++ -Wall -pedantic -g -O0 -std=c++11 -o BloomFilterTest BloomFilterTest.cpp BloomFilter.cpp HashFunctions.cpp
$ ./BloomFilterTest

1.04075
```

The number that gets printed is the empirical False Positive probability we encountered in your Bloom filter divided by the theoretical False Positive probability. Given an unmodified [``BloomFilterTest.cpp``](BloomFilterTest.cpp), we expect this number to be between 1 and 10. If yours exceeds 10, you will receive 0 points.

## Part 3: Count-Min Sketches (35 points)
In an ideal world, we would like to use a Hash Map to store the counts of elements because of its O(1) average-case time complexity for find, insert, and remove operations. In practice, however, we may face datasets that are too large to fit into memory at once. In these cases, we can use the [Count-Min Sketch](https://en.wikipedia.org/wiki/Count%E2%80%93min_sketch), which is a probabilistic data structure that may overestimate our count, but that will never underestimate our count.

### Task: Edit [``CountMinSketch.cpp``](CountMinSketch.cpp)
In this repository, there is a file called [``CountMinSketch.cpp``](CountMinSketch.cpp) that contains initial steps towards implementing a Count-Min Sketch. Function headers (with usage details) are included in [``CountMinSketch.h``](CountMinSketch.h), and you need to fill in the ``increment()`` and ``find()`` functions of the ``CountMinSketch`` class. We will not be checking for memory leaks, as you should not be dynamically allocating any memory.

We have provided a tester program, [``CountMinSketchTest``](CountMinSketchTest.cpp), that will help test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -g -O0 -std=c++11 -o CountMinSketchTest CountMinSketchTest.cpp CountMinSketch.cpp HashFunctions.cpp
```

Here's an example of how it should look like when it's compiled and run from the command line:

```bash
g++ -Wall -pedantic -g -O0 -std=c++11 -o CountMinSketchTest CountMinSketchTest.cpp CountMinSketch.cpp HashFunctions.cpp
$ ./CountMinSketchTest

0.864665
```

The number that gets printed is the true probability of being in the upper-bound range of the true count we encountered in your Count-Min Sketch divided by the theoretical probability of being in the range. Given an unmodified [``CountMinSketchTest.cpp``](CountMinSketchTest.cpp), we expect this number to be close to 1. If yours exceeds 5, you will receive 0 points.

## Academic Integrity
This Programming Assignment (PA) must be completed 100% independently! You may only discuss the PA with the Tutors, TAs, and Instructors. You are free to use resources from the internet, but you are not allowed to blatantly copy-and-paste code. If you ever find yourself highlighting a code snippet, copying, and pasting into your PA, you are likely violating the Academic Integrity Policy. If you have any concerns or doubts regarding what you are about to do, *please* be sure to post on Piazza first to ask us if it is okay.

## Grading (100 points total)
* **Part 1: Probability of Collisions**
    * 5 points for a correct ``1a.txt`` (0 points for incorrect)
    * 5 points for a correct ``1b.txt`` (0 points for incorrect)
    * 5 points for a correct ``1c.txt`` (0 points for incorrect)
    * 5 points for a correct ``1d.txt`` (0 points for incorrect)
    * 5 points for a correct ``1e.txt`` (0 points for incorrect)
* **Part 2: Bloom Filters**
    * 40 points for a completely correct solution
    * 0 points for incorrect solution
* **Part 3: Count-Min Sketches**
    * 35 points for a completely correct solution
    * 0 points for incorrect solution
