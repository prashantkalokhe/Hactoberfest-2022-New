class xyz2 implements Runnable{
   int id;
   public void run(){
    if(id==1){
       for(int i=1;i<=100;i++){
           if(i%2==0){
             System.out.println("Even: "+i);
        }
      }
    }
    else{
       if(id==2){
          for(int i=100;i<=200;i++){
           if(i%2!=0){
             System.out.println("\tOdd: "+i);
         }
       }
     }
    }
  }
}
class CoreJavaProgram{
    public static void main(String args[]){
       xyz t1 = new xyz();
       xyz t2 = new xyz();
       t1.id = 1;
       t2.id = 2;
      Thread p1 = new Thread(t1);
      Thread p2 = new Thread(t2);
      p1.start();
      p2.start();
  }
}
