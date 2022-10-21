package com.java2novice.jdbc;
 
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
 
public class JdbcConnection {
 
    public static void main(String a[]){
         
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
            Connection con = DriverManager.
                getConnection("jdbc:oracle:thin:@<hostname>:<port num>:<DB name>"
                    ,"user","password");
            Statement stmt = con.createStatement();
            System.out.println("Created DB Connection....");
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
