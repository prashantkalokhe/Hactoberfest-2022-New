import java.io.IOException;
import java.util.Scanner;
import java.io.*;
import java.awt.*;
import java.awt.event.*;


//
import com.fazecast.jSerialComm.*;

class MyFrame extends Frame implements ActionListener   {
	
	Button b  , b1 , b2;
	byte l = 1;

	/*getCommPorts return an array , 
        make sure to check your comm port is at which index 	      
        *\
	SerialPort comPort = SerialPort.getCommPorts()[1];

	
	public MyFrame() {
		super("Pratik's LED");
		b = new Button("Happy");
		b1=  new Button("Sad");
		b2 = new Button("Neutral");
		b.setPreferredSize(new Dimension(150 , 150));
		b1.setPreferredSize(new Dimension(150 , 150));
		b2.setPreferredSize(new Dimension(150 , 150));
		
	
		add(b);
		add(b1);
		add(b2);
		b.addActionListener(this);
		b1.addActionListener(this);
		b2.addActionListener(this);
		setLayout(new FlowLayout());
		
		comPort.openPort();
		comPort.setComPortTimeouts(SerialPort.TIMEOUT_READ_SEMI_BLOCKING, 0, 0);

		
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		if(e.getSource() == b) {
			
			this.start(1);
		}
		
	else if(e.getSource() == b1) {
		this.start(2);

		
	}
	else if(e.getSource() == b2) {
		this.start(3);

	}
				
		
		
		
	}
	
	void start(int n) {
		
		OutputStream op = comPort.getOutputStream();
		
		
		try {
			op.write(n);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	
	void begin() {
		
		
	}
	
	
}

public class Main  {
	
	public static void main(String [] args) {
		
	
		MyFrame fm = new MyFrame();
		fm.setSize(500 , 500);
		fm.setVisible(true);

		}
		
		
		
	}
	
	
