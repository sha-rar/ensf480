import java.sql.*;
import java.util.ArrayList;
import java.util.List;

// Singleton
// Only one instance of DatabaseManager per FlightManager instance

public final class DatabaseManager {
  public final String DBURL;
  public final String USERNAME;
  public final String PASSWORD;

  private Connection dbConnect;
  private ResultSet results; // don't need to keep redeclaring for results.

  private static DatabaseManager onlyInstance;

  private DatabaseManager() {

    this.DBURL = "jdbc:mysql://localhost:3306/FLIGHTMANAGER";
    this.USERNAME = "root";
    this.PASSWORD = "password";
  }

  public static DatabaseManager getInstance() {
    if (onlyInstance == null) {
      onlyInstance = new DatabaseManager();
    }
    return onlyInstance;
  }

  public void initializeConnection() throws SQLException {
    dbConnect = DriverManager.getConnection(DBURL, USERNAME, PASSWORD);
    System.out.println("Connection established successfully.");
  }

  String getDburl() {
    return this.DBURL;
  }

  String getUsername() {
    return this.USERNAME;
  }

  // STATEMENT METHODS, POSSIBLE FACADE TO "DATABASE" SUBSYSTEM
  // MAY MOVE initializeConnection() to subsystem.
  // Alternatively, facade that has DatabaseManager as a subsystem
  // simplified controls in parent controller for certain actions

  public ArrayList<String> selectPublicUserInfo() {
    ArrayList<String> info = new ArrayList<>();

    try {
      Statement myStmt = dbConnect.createStatement();
      results = myStmt.executeQuery("SELECT * FROM USER_INFO");

      while (results.next()) {
        String userName = results.getString("UserName");
        String userRole = results.getString("Role");
        info.add(userName);
        info.add(userRole);
      }

      myStmt.close();
    } catch (SQLException ex) {
      ex.printStackTrace();
    }

    return info;
  }

  public ArrayList<String> selectPrivateUserInfo() {
    ArrayList<String> info = new ArrayList<>();

    try {
      Statement myStmt = dbConnect.createStatement();
      results = myStmt.executeQuery("SELECT * FROM USER_INFO");

      while (results.next()) {
        String passWord = results.getString("PassWord");
        String realName = results.getString("Name");
        String phoneNumber = results.getString("Phone");
        String address = results.getString("Address");

        info.add(passWord);
        info.add(realName);
        info.add(phoneNumber);
        info.add(address);
      }

      myStmt.close();
    } catch (SQLException ex) {
      ex.printStackTrace();
    }
    return info;
  }

  public ArrayList<String> selectFlightInfo() {
    ArrayList<String> info = new ArrayList<>();

    try {
      Statement myStmt = dbConnect.createStatement();
      results = myStmt.executeQuery("SELECT * FROM FLIGHT_LISTINGS");

      while (results.next()) {
        String flightID = results.getString("FlightID");
        String flightDestination = results.getString("Destination");
        String flightDepartureDate = results.getString("DepartureDate");
        String flightDepartureTime = results.getString("DepartureTime");
        String flightDuration = results.getString("Duration");
        String arrivalTime = results.getString("ArrivalTime");
        String airline = results.getString("Airline");
        String flightPrice = results.getString("Price");

        info.add(flightID);
        info.add(flightDestination);
        info.add(flightDepartureDate);
        info.add(flightDepartureTime);
        info.add(flightDuration);
        info.add(arrivalTime);
        info.add(airline);
        info.add(flightPrice);
      }

      myStmt.close();
    } catch (SQLException ex) {
      ex.printStackTrace();
    }
    return info;
  }

  public void insertNewUser(
      String userName, String passWord, String userRole,
      String realName, String phoneNumber, String address) {

    try {
      // INFO VALIDATION CALL ON THIS LINE

      String query = "INSERT INTO USER_INFO (UserName, PassWord, Role, Name, Phone, Address) VALUES (?, ?, ?, ?, ?, ?)";
      PreparedStatement myStmt = dbConnect.prepareStatement(query);

      myStmt.setString(1, userName);
      myStmt.setString(2, passWord);
      myStmt.setString(3, userRole);
      myStmt.setString(4, realName);
      myStmt.setString(5, phoneNumber);
      myStmt.setString(6, address);
      myStmt.execute();
      myStmt.close();
    } catch (SQLException ex) {
      ex.printStackTrace();
    }
  }

  public void insertNewFlight(
      String flightID, String flightDestination, String flightDepartureDate,
      String flightDepartureTime, String flightDuration, String arrivalTime,
      String airline, String flightPrice) {

    try {
      // INFO VALIDATION CALL ON THIS LINE

      String query = "INSERT INTO FLIGHT_LISTINGS (FlightID, Destination, DepartureDate, DepartureTime, Duration, ArrivalTime, Airline, Price) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
      PreparedStatement myStmt = dbConnect.prepareStatement(query);

      myStmt.setString(1, flightID);
      myStmt.setString(2, flightDestination);
      myStmt.setString(3, flightDepartureDate);
      myStmt.setString(4, flightDepartureTime);
      myStmt.setString(5, flightDuration);
      myStmt.setString(6, arrivalTime);
      myStmt.setString(7, airline);
      myStmt.setString(8, flightPrice);

      myStmt.executeUpdate();
      myStmt.close();
    } catch (SQLException ex) {
      ex.printStackTrace();
    }
  }

}
