class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        return sorted(set(arr1).intersection(set(arr2), set(arr3))) // sorted is crucial because set will give us a unsorted list
        
