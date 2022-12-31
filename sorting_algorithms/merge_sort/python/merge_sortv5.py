def merge_sort(lst):
    # Base case: a list of length 1 is already sorted
    if len(lst) == 1:
        return lst

    # Divide the list into two halves
    mid = len(lst) // 2 # Floor division
    left = lst[:mid]
    right = lst[mid:]

    # Recursively sort the two halves
    sorted_left = merge_sort(lst[:mid])
    sorted_right = merge_sort(lst[mid:])

    # Merge the sorted halves back together
    return merge(sorted_left, sorted_right)

def merge(left, right):
    # Initialize an empty result list
    result = []

    # Merge the two lists until one of them is empty
    while left and right:
        # Pop the smallest element from the front of the list
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    # Append any remaining elements from the non-empty list
    result.extend(left)
    result.extend(right)

    return result

a = [0, 5, 2, 4, 6, 1, 3]
print(merge_sort(a))