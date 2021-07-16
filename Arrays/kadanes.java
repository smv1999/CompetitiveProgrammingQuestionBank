// Java program for Kadane's Algorithm
// 
class algo{

	static void Kadanes(int a[], int size)
	{
		int max_so_far = Integer.MIN_VALUE,
		max_ending_here = 0,start = 0,
		end = 0, s = 0;

		for (int i = 0; i < size; i++)
		{
			max_ending_here += a[i];

			if (max_so_far < max_ending_here)
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
		System.out.println("Maximum contiguous sum is "
						+ max_so_far);
		System.out.println("Starting index " + start);
		System.out.println("Ending index " + end);
	}


	public static void main(String[] args)
	{
		int a[] = { 10, 16, -2, 8, 5, 9, -7, 3 };
		int n = a.length;
		Kadanes(a, n);
	}
}

