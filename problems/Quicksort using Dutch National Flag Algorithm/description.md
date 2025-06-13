Implement Quicksort efficiently for inputs containing many repeated elements.

Quicksort exhibits poor performance for inputs that contain many repeated elements. The problem is visible when all the input elements are equal. Then at each point in recursion, the left partition is empty (no input values are less than the pivot), and the right partition has only decreased by one element (the pivot is removed). Consequently, the algorithm takes quadratic time to sort an array of equal values.

Practice this problem

We can use an alternative linear-time partition routine to solve this problem that separates the values into three groups:

The values less than the pivot,
The values equal to the pivot, and
The values greater than the pivot.
The values equal to the pivot are already sorted, so only the less-than and greater-than partitions need to be recursively sorted. This linear-time partition routine is similar to 3–way partitioning for the Dutch national flag problem.