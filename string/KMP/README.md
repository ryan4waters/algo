# KMP

## Exact matching: what's the problem?

Given a string `P` called the pattern and a longer string `T` called the text, the exact  matching problem is to find all occurrences, if any, of pattern `P` in text `T`.  For example, if `P` = `aba` and `T` = `bbabaxababay` then `P` occurs in `T` starting at  locations `3`, `7`, and `9`. Note that two occurrences of `P` may overlap, as illustrated by the  occurrences of `P` at locations `7` and `9`. —— via *Algorithms on Strings, Trees,  and Sequences*

## Introduce

[wikipedia](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)

I supposed that you have read this wiki for times...

## Brute-Force in

Before learning KMP, BM, RK and other algorithms like these, let's start with the naive method - Brute-Force.
### Implement

Now that we know what the string matching problem is, the simple brute force algorithm should be ready to come out. BF algorithm is both clear and simple in thinking and logic.

* enumerate `i` = `0,1,2,3,...,len(T) - len(P)`.
* Compare whether `T[i : i + len(P)]` is equal to `P`, and if they are consistent, one match found.

```
//CPP
void bfStringMatch(string p, string t)
{
    int plen = p.size();
    int tlen = t.size();
    if (plen > tlen) {
        return;
    }
    for (int i = 0; i <= tlen - plen; ++i) {
        bool flag = true;
        for (int j = 0; j < plen; ++j) {
            if (p[j] ! = t[i + j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << " ";
        }
    }
}
```

### Complexity of Brute Force

1. Single small task of "string comparison": the worst possible situation is the following - the only difference between the two strings is the last character. In this case, the pattern string must go through the complete matching string to be able to come to a result, the complexity is $O(len)$.
2. The worst case that the brute force algorithm may encounter: assume $n = len(P)$, $m = len(T)$. Each small task pays $n$ character comparison costs, and a total of $m - n + 1$ comparisons are required, so the time complexity is $O(n*(m-n+1))$. Considering that the text string is generally much longer than the pattern string, the complexity of the brute force algorithm is $O(nm)$.

## Improvements to the Brute Force

Although the code logic is simple, it is not difficult to find that the brute force algorithm is as slow as crawling. Its worst case is shown in the figure below:

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/BF.png)

It is difficult for us to reduce the complexity of "small tasks" (because comparing two strings of equal length, you can only compare characters one by one). Therefore, we consider reducing the number of "small tasks". If the number of comparisons can be reduced enough, the overall complexity will also reduce a lot.

To optimize an algorithm, the first question to answer is **"What information do I have?"** Whether the information we have is sufficient and effective determines how far we can optimize the algorithm. **Please remember: It is the idea of the KMP algorithm to make use of the residual information as much as possible. **

In the brute force algorithm, if the comparison from `T[i]` fails, the algorithm will directly start to try to compare from `T[i+1]`. This kind of behavior is a typical **"not learning from previous mistakes"**. We should note that a failed match will provide us with valuable information - if the match of `T[i : i+len(P)]` fails at the position of `r`, then starting from `T[i]`, there must be `( r-1)` consecutive characters  exactly the same as the first `(r-1)` characters of `P`!

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/prefix.png)

The task that needs to be realized is "string matching", and every failure will give us some information in exchange - it can tell us that a certain substring of the text string is equal to a certain prefix of the pattern string. But what's the use?

### Skip impossible string comparisons

Some "small tasks" of string comparisons are likely to succeed, and some are not. We just mentioned that the goal of optimizing Brute-Force is to "minimize the number of 'small tasks'", and if we skip those "small tasks" that are never likely to succeed, we can hope that the complexity will be reduced to an acceptable range.

So, which "small tasks" are impossible to succeed? Let's look at an example. The known information is as follows:

* Pattern string `P` = `"abcabd"`.
* When matching the text string starting from `T[0]`, there is a mismatch at `P[5]`.

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/1st_time_match.png)

First, use the conclusions from the previous section. Since it is mismatched at `P[5]`, it means that `T[0:5]` is equal to `P[0:5]`, which is `"abcab"`. Now let's consider: from `T[1]`, `T[2]`, `T[3]` The initial match attempt, is there any chance of success?

Starting from `T[1]` will definitely not succeed, because `T[1]` = `P[1]` = '`b'`, which is not equal to `P[0]`. Starting from `T[2]` is also useless, because `T[2]` = `P[2]` = `'c'`, which is not equal to `P[0]`. But starting from `T[3]` is possible - at least according to the established known information, we can not deduce the contradiction.

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/move2try.png)

With the idea of **"skip impossible attempts"**, we introduce the next array.

## next array

The next array is for the pattern string. The next array of `P` is defined as: `next[i]` represents a substring of `P[0]` ~ `P[i]`, that **the first k characters** are exactly equal to the largest `k` of the **last k characters**. In particular, `k` cannot take `i+1` (because this substring has only `i+1` characters in total, and it must be equal to itself, so it is meaningless).

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/next_intro.png)

The figure above gives an example. When `P`=`"abcabd"`, `next[4]`=`2`, because the substring `P[0]` ~ `P[4]` is `"abcab"`, the first two characters are equal to the last two characters, so `next[4]` take 2. And `next[5]`=`0`, because `"abcabd"` can't find the same prefix and suffix, so it can only take `0`.

If the pattern string is regarded as a **ruler** and moves on the text string, then Brute-Force only shifts `1` to the right after each mismatch; the improved algorithm is to move many indexes after each mismatch, skipping those that are not possible locations for a successful match. But how do you determine how many indexes to shift?

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/how2movebynext.png)

After `S[0]` tries to match, and the mismatch is `S[3]` <=> `P[3]`, we directly shift the pattern string to the right by `2`, so that `S[3]` is aligned with `P[1]`. Then continue matching, the mismatch is `S[8]` <=> `P[6]`, then we shift `P` to the right by `3`, and align `S[8]` with `P[3]`. Then continue to match until it succeeds.

How should we move this ruler? Obviously, as shown by the arrow in the figure, the old suffix must be consistent with the new prefix (if not, it will definitely not match)!j

Recall the property of the next array: in the substring from `P[0]` to `P[i]`, the first `next[i]` characters are exactly the same as the last `next[i]` characters. That being the case, if the mismatch is in `P[r]`, then in the section `P[0]`~`P[r-1]`, the first `next[r-1]` characters are exactly equal to the last `next[r-1]` characters - That is to say, we can use the prefix whose length is `next[r-1]` to replace the position of the current suffix and let the matching continue!

You can verify the above matching example: after `P[3]` is mismatched, align `P[next[3-1]]`(`P[1]`), with the index that the text string just mismatched; After `P[6]` is mismatched, align `P[next[6-1]]`(`P[3]`), with the index that the text string just mismatched.

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/ruler_move.png)

### The create and use of next array

After understanding the principle of using the next array to speed up string matching, let's implement it in the next code. I divided it into two parts:

1. Create next array
2. Use the next array for matching

The first is to create the next array. Let's use the simplest method first, and come back to optimize it later:

```
//CPP
void GetKMPNextArrInit(const string& p) {
    next.resize(p.size(), 0);
    for (int pr = p.size() - 1; pr > 0; --pr) {
        for (int pl = pr; pl > 0; --pl) {
            int i = 0;
            for (int pos = pl; pos <= pr; ++pos, ++i) {
                if (p[i] != p[pos]) {
                    break;
                }
            }
            if (i == pr - pl + 1) {
                next[pr] = max(next[pr], i);
            }
        }
    }
}
```

You might be furious because of triple-for loop used. "Damn, the reason why I learn KMP is to not use such many fors". However, python can be more concise：

```
#python
def getNext(x):
    for i in range(x, 0, -1):
        if p[0:i] == p[x-i+1:x+1]:
            return i
    return 0

next = [getNext(x) for x in range(len(p))]
```

As shown in the code above, the next array is created directly according to the definition of the next array. It is not difficult to find that its complexity is $O(n^2)$.

Next, realize the use of the next array to speed up string matching. code show as below:

```
vector<int> GetMasterStringStartIdx(const string& t, const string& p) {
    GetKMPNextArr(p);
    int tidx = 0, pidx = 0;
    vector<int>ret;
    while (tidx < t.size()) {
        if (t[tidx] == p[pidx]) {
            ++tidx;
            ++pidx;
        } else if (pidx != 0) {
            pidx = next[pidx - 1];
        } else {
            ++tidx;
        }
        if (pidx == p.size()) {
            ret.emplace_back(tidx - pidx);
            pidx = next[pidx - 1];
        }
    }
    return ret;
}
```

How to analyze the complexity of this string matching? At first glance, the value of  `pidx` may keep changing to `next[pidx-1]`, and the cost will be very high; but we use the amortized analysis, it is clear that the value of `pidx` will increase at most $len(S)$ times, so the value of `pidx` will decrease The number of times will not be higher than $len(T)$ times. Therefore, the complexity is acceptable, and it is not difficult to analyze the time complexity of the entire matching algorithm: $O(m+n)$.

### Quickly build the next array

Finally we come to our last question - how to quickly build the next array.

First: Quickly constructing the next array is the essence of the KMP algorithm. The core idea is **"P matches itself with itself"**.

Why do I say this way? Review the complete definition of the next array:

* Define "k-prefix" as the first number of `k` characters of a string; "k-suffix" as the last number of `k` characters of a string. `k` must be less than the string length.

* `next[x]` is defined as: a string of `P[0]`~`P[x]`, to make the largest `k` by **k-prefix equal to k-suffix**.

In this definition, one match is implicitly included—prefix and suffix are equal. Next, we consider recursively finding the next array. If `next[0]`, `next[1]`,..., `next[x-1]` are all known, how to find `next[x]`?

Let's discuss the situation. First of all, we already know `next[x-1]` (hereinafter referred to as `now`), if `P[x]` is the same as `P[now]`, then the length of the longest equal prefix and suffix can be extended by one, obviously `next[x]` = `now` + `1`. The diagram is as follows.

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/quick_solve_next.png)

Just solved the case where P[x] = P[now] . What if P[x] is different with P[now]?

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/x!%3Dnow.png)

As shown in the picture. The substring `A` and `B` of length `now` are the longest common prefix and suffix in `P[0]`~`P[x-1]`. Unfortunately, the character on the right of `A` is not equal to the character on the right of `B`, so `next[x]` cannot be changed to `now+1`. Therefore, we should **shorten this `now`**, change it to a smaller value, and try whether `P[x]` is equal to `P[now]`.

How much should `now` be reduced to? Obviously, we don't want to shrink the `now` too much. Therefore, we decided to make this new `now` as large as possible while maintaining "the now-prefix of `P[0]` ~ `P[x-1]` is still equal to the now-suffix". For the public prefix and suffix of `P[0]` ~ `P[x-1]`, the prefix must fall in string `A`, and the suffix must fall in string `B`. In other words: the next `now` should be changed to: make the largest `k` by **A's k-prefix** equal to **B's k-suffix**.

You should have noticed a very strong property - **string A and string B are the same!** `B`'s suffix is equal to` A`'s suffix! Therefore, the largest `k` that makes the k-prefix of `A` equal to the k-suffix of `B` is actually the length of the longest common prefix and suffix of string `A` - `next[now-1]`!

![image](https://github.com/ryan4waters/algo/blob/main/KMP/figures/quick_final.png)

Look at the example above. When `P[now]` is not equal to `P[x]`, we need to shrink now - turn `now` into `next[now-1]` until `P[now]`=`P[x]`. When `P[now]`=`P[x]`, you can directly expand to the right.

The CPP code is  as follows:

```
void GetKMPNextArrQuick(const string& p) {
	this->next.resize(p.size(), 0);
	int now = 0, x = 1;
	while (x < p.size()) {
		if (p[x] == p[now]) {
			++now;
			next[x] = now;
			++x;
		} else if (now != 0) {
			now = next[now -1];
		} else {
			next[x] = 0;
			++x;
		}
	}
}
```

It is not difficult to prove that the time complexity of constructing the next array is $O(m)$. So far, with the time complexity of $O(m+n)$, we have realized building the next array and using the next array for string matching.
