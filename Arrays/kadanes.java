// Java program for Kadane's Algorithms

//### Description :-

//The  idea behind the implementation of Kadane’s algorithm is to peek for all positive contiguous segments of the array (max_ending_here is used for this).
//Keep track of  the maximum sum contiguous segment among all positive segments (max_so_far is used for this).
//Each time we get a positive-sum compare it with max_so_far and update max_so_far if it is greater than max_so_far.


class algo{

	static void Kadanes(int a[], int size)
	{
		int max_so_far = Integer.MIN_VALUE,
		max_ending_here = 0,start = 0,
		end = 0, s = 0;

		for (int i = 0; i < size; i++)
		{
		// loop to iterate and find the max_ending_here.
			max_ending_here += a[i];

			if (max_so_far < max_ending_here)
		//condition to find the start and end indexes of the sub-array
			{
				max_so_far = max_ending_here;
				start = s;
				end = i;
			}

			if (max_ending_here < 0)
			{
				max_ending_here = 0;
				s = i + 1;
			}
		}
		// PRINT THE MAXIMUM CONTIGUOUS SUM WITH THE STARTING AND ENDING INDEXES.
		System.out.println("Maximum contiguous sum is "
						+ max_so_far);
		System.out.println("Starting index " + start);
		System.out.println("Ending index " + end);
	}


	public static void main(String[] args)
	{
		int a[] = { 10, 16, -2, 8, 5, 9, -7, 3 };
		int n = a.length;
	// CALLING OUR FUNCTION TO IMPLEMENT THE ALGORITH ON THE ABOVE ARRAY a[] 
		Kadanes(a, n);
	}
}
//     A SAMPLE TEST CASE  :-

//     Here is a test cases to show the implementation of the above stated Algorithm:-

//     Lets take the below set of elements in an array as example:
//     {-2, -3, 4, -1, -2, 1, 5, -3}

//     max_so_far = max_ending_here = 0

//     for i=0,  a[0] =  -2
//     max_ending_here = max_ending_here + (-2)
//     Set max_ending_here = 0 because max_ending_here < 0

//     for i=1,  a[1] =  -3
//     max_ending_here = max_ending_here + (-3)
//     Set max_ending_here = 0 because max_ending_here < 0

//     for i=2,  a[2] =  4
//     max_ending_here = max_ending_here + (4)
//     max_ending_here = 4
//     max_so_far is updated to 4 because max_ending_here greater 
//     than max_so_far which was 0 till now

//     for i=3,  a[3] =  -1
//     max_ending_here = max_ending_here + (-1)
//     max_ending_here = 3

//     for i=4,  a[4] =  -2
//     max_ending_here = max_ending_here + (-2)
//     max_ending_here = 1

//     for i=5,  a[5] =  1
//     max_ending_here = max_ending_here + (1)
//     max_ending_here = 2

//     for i=6,  a[6] =  5
//     max_ending_here = max_ending_here + (5)
//     max_ending_here = 7
//     max_so_far is updated to 7 because max_ending_here is 
//     greater than max_so_far

//     for i=7,  a[7] =  -3
//     max_ending_here = max_ending_here + (-3)
//     max_ending_here = 4

