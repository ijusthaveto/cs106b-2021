# Materials

- The new employee can work for up to twenty hours per week.

- The structure of a **Shift** is as follows:
  1. Day of the week.
  2. Start time.
  3. End time.
  4. Value 💰

- To report an error if the number of hours (**numHours**) is less than 0, use the **error()** function. If the worker has 0 available hours, it means she is too busy.

- Don't forget to add at least one test of your own.

- Keep in mind that the best schedule may not use up all of the employee's available hours.

- Chances are, you won't need to delve into the code within **Shift.h**.

Here are some useful functions:

```c++
/* Get the duration of a shift */
int lengthOf(const Shift & shift);

/* Get the value of this shift */
int valueOf(const Shift & shift);

/* Check if two shifts overlap */
bool overlapsWith(const Shift & one, const Shift & two);
```

# Strategy

The goal is to select shifts from the provided options. There are two reasons why the employee might not be able to take a shift:

1. It overlaps with a shift she's already scheduled for.
2. It would exceed her total weekly hour limit (twenty hours).

In all other cases, the boss can assign the current shift, and there are two options to consider:

1. One of these options will be better than the other.
2. Both options have the same resulting property.