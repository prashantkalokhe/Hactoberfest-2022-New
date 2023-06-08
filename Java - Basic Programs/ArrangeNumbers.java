import java.util.Scanner;

class ArrangeNumbers{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];

         boolean place=true;
         int f=0,r=n-1;
        for (int x = 0; x < n; x++)
        {
           if(place){
               a[f++]=x+1;
               
           }
           else{
               a[r--] = x+1;
           }
           place = !place;
        }
        for (int x = 0; x < n; x++)
        {
            System.out.print(a[x]+" ");
        }
    }
}
