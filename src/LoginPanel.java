import java.awt.*;

public class LoginPanel extends Panel {

    private TextField userNameField = new TextField(20);
    private TextField passwordField = new TextField(20);
    private Label status = new Label(" ");

    public LoginPanel(LoginManager loginManager, Runnable onAdminLogin, Runnable onMemberLogin) {

        setLayout(new BorderLayout(10, 12));

        add(new Label("Flight Manager — Login"), BorderLayout.NORTH);

        Panel fields = new Panel(new GridLayout(2, 2, 8, 8));
        fields.add(new Label("Username"));
        fields.add(userNameField);
        fields.add(new Label("Password"));
        fields.add(passwordField);
        passwordField.setEchoChar('*');

        // Wrap in GridBagLayout so the fields keep their normal size and stay centered
        Panel fieldsWrapper = new Panel(new GridBagLayout());
        fieldsWrapper.add(fields);
        add(fieldsWrapper, BorderLayout.CENTER);

        Button loginButton = new Button("Login");

        Panel bottom = new Panel(new BorderLayout());
        bottom.add(loginButton, BorderLayout.NORTH);
        bottom.add(status, BorderLayout.SOUTH);

        add(bottom, BorderLayout.SOUTH);

        loginButton.addActionListener(event -> {
            String userName = userNameField.getText().trim();
            String passWord = passwordField.getText();

            String role = loginManager.validateLogin(userName, passWord);

            if (role == null) {
                status.setText("Invalid username or password.");
                passwordField.setText("");
                return;
            }

            passwordField.setText("");
            status.setText(" ");

            if (loginManager.isAdministrator(role)) {
                onAdminLogin.run();
            } else {
                onMemberLogin.run();
            }
        });
    }
}