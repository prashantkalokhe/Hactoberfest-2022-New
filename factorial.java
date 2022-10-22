import java.util.Scanner;

class factorial{
    static int factorial(int num){
        int fact=1;
        while(num!=1){
            fact*=num;
            num-=1;
        }
        return fact;
    }

    public static void main(String[] args) {
      System.out.println("                  FACTORIAL CALCULATOR"+'\n'+"------------------------------------------------------ "+'\n');
      Scanner factnum=new Scanner(System.in);
      System.out.print("Number-> ");
      int num=factnum.nextInt();
      factnum.close();
      int fact=factorial(num);
      System.out.println(num+" factorial= "+fact); 
    }
}