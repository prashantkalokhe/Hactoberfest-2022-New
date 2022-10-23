public class Main
{
	public static void main(String[] args)
	{
		EBBill myBill = new EBBill(2345, "Abdullah Sheriff", 350, 230, "domestic");
		EBBill hisBill = new EBBill(1353, "Lohith K Sarathy", 120, 490, "commercial");
		
		myBill.generateEBBill();
		hisBill.generateEBBill();
	}
}
