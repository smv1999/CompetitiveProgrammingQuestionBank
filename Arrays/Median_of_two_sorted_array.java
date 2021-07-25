class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        //Creating a ArrayList containing all the elements of both array
        List<Integer> merged = new ArrayList<Integer>();
        for (int i= 0 ; i < nums1.length; i++){
            merged.add(nums1[i]);
        }
        for (int i = 0 ; i < nums2.length;i++){
            merged.add(nums2[i]);
        }
        Collections.sort(merged);
        //Sorting the finally Merged Linked List
        int idx = merged.size()/2;
        //Finding the middle index to get the Median
        if (merged.size()%2 != 0){
            //If Size of arraylist is odd then the middle element will be the median of the ArrayList.
            return merged.get(idx);
        }
        
        return (merged.get(idx-1)+merged.get(idx))/2.0;

    }
}

// Example Test case
//
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
//
//
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
