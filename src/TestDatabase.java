public class TestDatabase {
    public static void main(String[] args) {
        try {
            DatabaseManager database = DatabaseManager.getInstance();

            database.initializeConnection();

            System.out.println(database.selectFlightInfo());
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}