import java.util.*;

public class CountSort {
    public static int getMax(int array[]) {  
     int max = array[0];  
     for(int i = 1; i<array.length; i++) {  
        if(array[i] > max)  
           max = array[i];  
     }  
     return max;  
  }
  
  public static void countSort(int array[], int sizeOfArray){
    int result[]=new int[sizeOfArray+1];  
    int max = getMax(array);  
    int count[]=new int[max+1];  
    
    Arrays.fill(count,0);
      
    for (int i=0; i<sizeOfArray; i++)
      count[array[i]]++;  
    
    for(int i = 1; i<=max; i++)   
      count[i] += count[i-1];
      
    for (int i=sizeOfArray-1; i >= 0; i--) {  
      result[count[array[i]] - 1] = array[i];  
      count[array[i]]--; 
    }  
    
    for(int i = 0; i<sizeOfArray; i++) {  
      array[i] = result[i];
    }  
  }
  
    public static void main(String[] args) {
      Scanner sc=new Scanner(System.in);
      
      int sizeOfArray;
      int input[];
      
      sizeOfArray=sc.nextInt();
      input=new int[sizeOfArray];
      
      for(int i=0; i<sizeOfArray; i++){
        input[i]=sc.nextInt();
      }
      
      System.out.print("Array elements before sorting: ");
      for(int x:input)
        System.out.print(x+" ");
      
      countSort(input, sizeOfArray);
      
      System.out.print("\nArray elements after sorting: ");
      for(int x:input)
        System.out.print(x+" ");
  }
}