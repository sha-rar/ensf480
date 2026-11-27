public class LoginManager {
    private DatabaseManager db;
    public LoginManager() {this.db = DatabaseManager.getInstance();}

    // Returns the role if credentials are valid, null if not
    public String validateLogin(String userName, String passWord) {
        if (userName == null || userName.trim().isEmpty()) {return null;}
        if (passWord == null || passWord.trim().isEmpty()) {return null;}
        return db.validateLogin(userName.trim(), passWord);
    }

    public boolean isAdministrator(String role) {return "Administrator".equalsIgnoreCase(role);}
    public boolean isMember(String role) {return "Member".equalsIgnoreCase(role);}
}