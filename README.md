<h1 align="center">
	📖 Push_swap
</h1>
<p align="center">
	<b><i>Because Swap_push isn’t as natural</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/linhtng/push_swap?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/linhtng/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/linhtng/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/linhtng/push_swap?color=green" />
</p>

---

## 💡 About the project
This project will make you sort data on a stack, with a limited set of moves, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

For more detailed information, look at the [push_swap.subject.pdf](https://github.com/linhtng/push_swap/files/10668338/push_swap.subject.pdf)

## Challenge
You start with two empty stacks: **a** and **b**. You are given a random list of integers via command line arguments.
<br />
<br />
Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.
<br />

At the end, **stack b** must empty empty and all integers must be in **stack a**, sorted in ascending order. <br />
<br />

## Sorting algorithms used
### Quick sort
The quicksort algorithm is a sorting algorithm that sorts a collection by choosing a pivot point, and partitioning the collection around the pivot, so that elements smaller than the pivot are before it, and elements larger than the pivot are after it. It recursively choose a pivot point and break down the collection until single-element lists, before combing them back together to form one sorted list.
### Insertion sort
Suppose we split the input into two “sections”, sorted and unsorted. The sorted section is initially empty. For each element in the unsorted section, we insert it into the sorted section, in its proper, sorted, position.

For example, you have the following array: `var items = [5, 2, 6, 1, 3, 9];`
To start, the 5 is placed into the sorted section. The 2 then becomes the value to place. Since 5 is greater than 2, the 5 shifts over to the right one spot, overwriting the 2. This frees up a new spot at the beginning of the sorted section into which the 2 can be placed. See the figure below for a visualization of this process (boxes in yellow are part of the sorted section, boxes in white are unsorted).

![insertionSortDemo](https://humanwhocodes.com/images/posts/2012/09/insertionsort.png)

<a name="installation"></a>
## Installation

* Clone this repository:

```shell
https://github.com/linhtng/push_swap.git
```

* Go to the project folder:

```shell
cd push_swap
```

* To compile:

```shell
make
```
* After compilation just run ``push_swap`` with your parameters.
* Example of executing ``push_swap`` :

```shell
./push_swap 8 13 20 17 19
```

* Example of executing ``checker`` with instructions received from ``push_swap`` :

```shell
ARG="8 13 20 17 19"; ./push_swap $ARG | ./checker_Mac $ARG
```
---

<a name="testing"></a>
## Testing
This project was tested using [push_swap_tester](https://github.com/SimonCROS/push_swap_tester).

## Visualizer
![](push_swap_visual.gif)

My push_swap algorithm in action visualized by [O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer).

## References
* [Sorting Out The Basics Behind Sorting Algorithms](https://medium.com/basecs/sorting-out-the-basics-behind-sorting-algorithms-b0a032873add)
* [Computer science in JavaScript: Insertion sort](https://humanwhocodes.com/blog/2012/09/17/computer-science-in-javascript-insertion-sort/)
* [Recursion and sorting algorithms](https://staffwww.fullcoll.edu/aclifton/cs133/lecture-9-recursion-sorting.html)
