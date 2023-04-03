<h1 align="center">
	📖 Push_swap
</h1>
<p align="center">
	<b><i>Because Swap_push isn’t as natural</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/linhtng/push_swap?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/linhtng/push_swap?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/linhtng/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/linhtng/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/linhtng/push_swap?color=green" />
</p>
<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
</h3>

---

## 💡 About the project
This project will make you sort data on a stack, with a limited set of moves, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

For more detailed information, look at the [push_swap.subject.pdf](https://github.com/linhtng/push_swap/files/10668338/push_swap.subject.pdf) and [push_swap_eval_form.pdf](https://github.com/linhtng/push_swap/files/11137815/push_swap_eval_form.pdf)

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

* To compile mandatory part:

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
ARG="8 13 20 17 19"; ./push_swap $ARG | ./checker $ARG
```
---

<a name="testing"></a>
## Testing

* [push_swap_tester](https://github.com/SimonCROS/push_swap_tester)

## Visualizer
![](push_swap_visual.gif)

My push_swap algorithm in action visualized by [O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer).
