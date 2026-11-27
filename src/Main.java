import java.awt.*;
import java.awt.event.*;
import java.sql.SQLException;

public class Main {

    public static void main(String[] args) {

        // Initialize DB connection (Singleton)
        DatabaseManager db = DatabaseManager.getInstance();
        try {
            db.initializeConnection();
        } catch (SQLException e) {
            System.err.println("Could not connect to MySQL: " + e.getMessage());
            System.err.println("Make sure MySQL is running and database/FlightManager.sql has been run as root.");
            System.exit(1);
        }

        LoginManager loginManager = new LoginManager();
        CustomerManager customerManager = new CustomerManager();

        Frame frame = new Frame("Flight Manager");
        frame.setSize(500, 400);
        frame.setLayout(new BorderLayout());

        // Show login panel first
        LoginPanel loginPanel = new LoginPanel(
            loginManager,
            () -> {
                // Admin logged in — swap to admin view
                frame.removeAll();
                frame.add(new Label("Welcome, Administrator!"), BorderLayout.CENTER);
                frame.revalidate();
                frame.repaint();
            },
            () -> {
                // Member logged in — swap to customer view
                frame.removeAll();
                frame.add(new Label("Welcome, Member!"), BorderLayout.CENTER);
                frame.revalidate();
                frame.repaint();
            }
        );

        frame.add(loginPanel, BorderLayout.CENTER);
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                frame.dispose();
                System.exit(0);
            }
        });
    }
}