import java.io.*;
public class PeakElement {
     // TC : O(logn)
     // SC : O(1)
  public static void main(String args[])throws IOException
  {
      InputStreamReader read=new InputStreamReader(System.in);
      BufferedReader in=new BufferedReader(read);
      int n,i;
      System.out.println("Enter the size of the array");
      n=Integer.parseInt(in.readLine());
      int nums[]=new int[n];
      System.out.println("Enter the elements of the array");
      for(i=0;i<n;i++)
      {
          nums[i]=Integer.parseInt(in.readLine());
      }
    int low = 0;
    int high = n-1;

    while(low< high){
      int mid = low + (high-low)/2;
      if(nums[mid]<nums[mid+1]){
        low = mid + 1;
      } else {
        high = mid;
      }
}
System.out.println("The Peak Element is = "+nums[low]);
  }
}