# How to write `if-else` elegantly

To give a real example, the only modification I made was to simplify the variable names:

```c
bool A = ...;
bool B = ...;
bool C = ...;
bool D = false;

if (!A) {
	D = true;
}

if ((!B) || (C == false)) {
	D = true;
}

if (D) {
	...; // code snippet 1
	return;
}

if (B && (C == true)) {
	...; // code snippet 2
}
```

Look at this kind of code will definitely make the maintainer tremble: it is not so courageous to change it, who knows what will happen if any condition is changed. But it feels wrong to not change. Intuitively speaking, the logic should not be so complicated. So when we encounter such a logical hairball, how should we understand it?

First we can combine the obvious equivalence variables and change the explicit comparisons with `true` and `false` to implicit comparisons, then it is easy to get:

```c
bool A = ...;
bool B = ...;
bool C = ...;
bool D = !A;

if ((!B) || (C == false)) {
	D = true;
}

if (D) {
	...; // code snippet 1
	return;
}

if (B && (C == true)) {
	...; // code snippet 2
}
```

We can see that `D` can do further merges:

```c
bool A = ...;
bool B = ...;
bool C = ...;
bool D = !A || (!B || !C);

if (D) {
	...; // code snippet 1
	return;
}

if (B && C) {
	...; // code snippet 2
}
```

Continue to expand `D` in the code:

```c
bool A = ...;
bool B = ...;
bool C = ...;

if (!A || (!B || !C)) {
	...; // code snippet 1
	return;
}

if (B && C) {
	...; // code snippet 2
}
```

Doesn't the logic look a lot more succinct now? But it's not over yet, the following is the key point! Here are two  formulas:

1. !(a && b) = (!a || !b)
2. !(a || b) = (!a && !b)

These two formulas are absolutely magical tools. As long as you memorize them, you can safely simplify and reconstruct the messy conditions without worrying about the logical result being wrong. We transform the second `if` condition `(B && C)` with Equation 1:

```c
(B && C) = !(!(B && C)) = !(!B || !C)
```

It gets interesting:

```c
bool A = ...;
bool B = ...;
bool C = ...;

if (!A || (!B || !C)) {
	...; // code snippet 1
	return;
}

if (!(!B || !C)) {
	...; // code snippet 2
}
```

Now it is obvious that if the condition of the first `if` is false, then `(!B || !C)` must be `false`, and the second `if` becomes :

```c
if (!false) {
	...; // code snippet 2
}
```

Obviously, the condition of the second `if` is redundant. So:

```c
bool A = ...;
bool B = ...;
bool C = ...;

if (!A || (!B || !C)) {
	...; // code snippet 1
	return;
}

...; // code snippet 2
```

Then, according to the associative law of logical algebra, the brackets in the first `if` can be removed, and the condition can be expanded:

```c
bool A = ...;
bool B = ...;
bool C = ...;

if (!A || !B || !C) {
	...; // code snippet 1
	return;
}

...; // code snippet 2
```

At this point, you will suddenly realize: そうか, it turns out that such a large pile of logic is actually the guard statement and main flow of the three conditions of `A`, `B`, and `C` . Isn’t it enough to write it like this from the beginning...? If you have forgotten what this code looks like before, I post it here for comparison:

```c
bool A = ...;
bool B = ...;
bool C = ...;
bool D = false;

if (!A) {
	D = true;
}

if ((!B) || (C == false)) {
	D = true;
}

if (D) {
	...; // code snippet 1
	return;
}

if (B && (C == true)) {
	...; // code snippet 2
}
```

The logic of these two pieces of code is actually equivalent, so even if you write `if-else`, it can be written very elegantly if you write it carefully.

The more professional name of the above two magical formulas is actually **De Morgan's Law** , and the popular name is the **Law of Duality** of logical algebra. If you haven't heard of it before, I recommend that you learn about these laws of logical operations. This will make your `if-else` more professional:

| NAME                                   | FORMULA                                                      |
| -------------------------------------- | ------------------------------------------------------------ |
| Associative Law                        | a && (b && c) = (a && b) && c<br />a \|\| (b \|\| c) = (a \|\| b) \|\| c |
| Distributive law                       | a \|\| (b && c) = (a \|\| b) && (a \|\| c)<br />a && (b \|\| c) = (a && b) \|\| (a && c) |
| Duality Principle(De Morgan's Theorem) | !(a && b) = !a \|\| !b<br />!(a \|\| b) = !a && !b           |
| Absorption Law                         | a \|\| (a && b) = a<br />a && (a \|\| b) = a                 |

