# The library design

This document contains some decisions I made for my code with a short explanation why.


## Why functions follow the stdlc++ naming?

You may have noticed that the functions that you use to interract with DSs look just like your C++ code.

```c++
// bdslib
deque_push_back(deque_t*, void*);


// C++ (stdlib)
std::deque<T>.push_back(&T);
```

This is intentional. The reasoning is to make the library more convenient for some. And it's not that bad anyway.


## If so, why there are some stdlc++ methods lacking?

Because the goal is not to replicate the entire C++ standard library in C. This repo is more about the DSs themselves rather than any standards.


## Data structures are at the core of CS and you licenced them with LGPLv3! How dare you!

This implementation of data structures is licensed under LGPLv3, not the data structures themselves. You could try implementing them yourself and would you be surprised to see your code 90% the same. But that's ok!
