# Selection Sort Program

def selection_sort(arr):
    n = len(arr)
    
    for i in range(n):
        # Assume the minimum element is at position i
        min_index = i
        
        # Find the smallest element in remaining array
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        
        # Swap the found minimum element with first element
        arr[i], arr[min_index] = arr[min_index], arr[i]
    
    return arr


# Taking input
numbers = [64, 25, 12, 22, 11]

print("Original List:", numbers)
selection_sort(numbers)
print("Sorted List:", numbers)