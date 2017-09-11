#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>
#include <stdio.h>

/** 
 * mylib.h
 * Provides various utility functions.
 */

/**
 * Error checking version of malloc. Exits on failure.
 * @param size_t s The size of memory to allocate.
 * @return The pointer to the allocated memory.
 */
 extern void *emalloc(size_t s);
 
 /** 
 * Error checking version of realloc. Exits on Failure.
 * @param void *p The memory block to reallocate.
 * @param size_s s The size of memory to reallocate.
 * @return The pointer to the reallocated memory.
 */
extern void *erealloc(void *p, size_t s);

/**
 * Reads a word from a stream.
 * @param char *s Where to read the word into.
 * @param int limit Maximum number of characters we should read.
 * @param FILE *stream The stream to read from.
 * @return Returns EOF if end of stream reached or returns non-zero value.
 */
extern int getword(char *s, int limit, FILE *stream);

/**
 * Performs a binary search on an array of strings.
 * @param char **a The array to search.
 * @param char *str The string to search for.
 * @param int len The number of elements in the array.
 * @return 1 if str was found, 0 otherwise.
 */
extern int binary_search(char **a, char *str, int len);

/**
 * performs an insertion sort on an integer array, a
 * @param char **a array of strings.
 * @param int n size of the array 
*/
extern void insertion_sort(char **a, int n);

/**
 * Merges two sorted subarrays.
 * @param char **a The array that contains two sorted subarrays.
 * @param char **w The workspace for merging the subarrays.
 * @param int len The length of the array.
*/
extern void merge(char **a, char **w, int len);

/**
 * performs mergesort on an array.
 * @param char **a The array to sort.
 * @param char **w The workspace for the merge.
 * @param int n  The number of items in the array.
*/
extern void merge_sort(char **a, char **w, int n);

#endif