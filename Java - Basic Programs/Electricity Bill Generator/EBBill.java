import java.util.Scanner;

public class EBBill
{
	long consumerNumber;
	String consumerName;
	float previousMonthReading;
	float currentMonthReading;
	String connectionType;
	
	public EBBill(int consumerNumber, String consumerName, float previousMonthReading, float currentMonthReading, String connectionType)
	{
		this.consumerNumber = consumerNumber; 
		this.consumerName = consumerName;
		this.previousMonthReading = previousMonthReading;
		this.currentMonthReading = currentMonthReading;
		this.connectionType = connectionType;
	}

	public EBBill() {} 

	float calculateDomesticEBBill()
	{
		float billAmount;
		float unitsConsumed = this.previousMonthReading - this.currentMonthReading;

		if (unitsConsumed <= 100)
		{
			billAmount = (float) (1 * unitsConsumed);
		}
		else if (unitsConsumed <= 200)
		{
			billAmount = (float) ((1 * 100) + ((unitsConsumed - 100) * 2.5));	
		}
		else if (unitsConsumed <= 500)
		{
			billAmount = (float) ((1 * 100) + (2.5 * 100) + ((unitsConsumed - 200) * 4));
		}
		else
		{
			billAmount = (float) ((1 * 100) + (2.5 * 100) + (4 * 300) + ((unitsConsumed - 500) * 6));
		}

		return billAmount;
	}

	float calculateCommercialEBBill()
	{
		float billAmount;
		float unitsConsumed = this.currentMonthReading - this.previousMonthReading;

		if (unitsConsumed <= 100)
		{
			billAmount = (float) (2 * unitsConsumed);
		}
		else if (unitsConsumed <= 200)
		{
			billAmount = (float) ((2 * 100) + ((unitsConsumed - 100) * 4.5));	
		}
		else if (unitsConsumed <= 500)
		{
			billAmount = (float) ((2 * 100) + (4.5 * 100) + ((unitsConsumed - 200) * 6));
		}
		else
		{
			billAmount = (float) ((2 * 100) + (4.5 * 100) + (6 * 300) + ((unitsConsumed - 500) * 7));
		}

		return billAmount;
	}

	void generateEBBill()
	{	
		double billAmount;

		if (this.connectionType == "domestic")
		{
			billAmount = this.calculateDomesticEBBill();
		}
		else
		{
			// this.connectionType == "commercial"
			billAmount = this.calculateCommercialEBBill();
		}

		System.out.println("*** Electricity Board Bill ***");
		System.out.println("Consumer Number        : " + this.consumerNumber);
		System.out.println("Consumer Name          : " + this.consumerName);
		System.out.println("Previous Month Reading : " + this.previousMonthReading);
		System.out.println("Current Month Reading  : " + this.currentMonthReading);
		System.out.println("Connection Type        : " + this.connectionType);
		System.out.println("Units Consumed         : " + (this.currentMonthReading - this.previousMonthReading));
		System.out.println("Amount Payable         : Rs. " + billAmount + '\n');
	} 

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		// Create object / instance 'myBill' of class 'EBBill'
		EBBill myBill = new EBBill();

		// Input
		System.out.print("\nEnter the Type of Connection     : ");
		myBill.connectionType = sc.nextLine();

		System.out.print("Enter the Consumer Number        : ");
		myBill.consumerNumber = sc.nextLong();
		sc.nextLine();

		System.out.print("Enter the Consumer Name          : ");
		myBill.consumerName = sc.nextLine();

		System.out.print("Enter the Previous Month Reading : ");
		myBill.previousMonthReading = sc.nextFloat();
		sc.nextLine();
		
		System.out.print("Enter the Current Month Reading  : ");
		myBill.currentMonthReading = sc.nextFloat();
		sc.nextLine();

		System.out.println();

		// Output
		myBill.generateEBBill();
	}
}