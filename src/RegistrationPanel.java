import java.awt.*;

public class RegistrationPanel extends Panel {

    // need to implements this to save the account.
    public interface AccountCreator {
        void createAccount(String name, String email,
                String phone, String password) throws Exception;
    }

    private TextField nameField = new TextField();
    private TextField emailField = new TextField();
    private TextField phoneField = new TextField();
    private TextField passwordField = new TextField();
    private TextField confirmField = new TextField();

    private Label status = new Label(" ");

    public RegistrationPanel(CustomerManager manager,
            AccountCreator accountCreator,
            Runnable backToLogin) {

        setLayout(new BorderLayout(10, 12));

        add(new Label("Create Account"), BorderLayout.NORTH);

        passwordField.setEchoChar('*');
        confirmField.setEchoChar('*');

        Panel fields = new Panel(new GridLayout(5, 2, 8, 8));

        fields.add(new Label("Full name"));
        fields.add(nameField);

        fields.add(new Label("Email"));
        fields.add(emailField);

        fields.add(new Label("Phone (optional)"));
        fields.add(phoneField);

        fields.add(new Label("Password"));
        fields.add(passwordField);

        fields.add(new Label("Confirm password"));
        fields.add(confirmField);

        Panel center = new Panel(new BorderLayout());
        center.add(fields, BorderLayout.NORTH);

        add(center, BorderLayout.CENTER);

        Button register = new Button("Register");
        Button back = new Button("Back to Login");

        Panel buttons = new Panel(new FlowLayout(FlowLayout.LEFT));
        buttons.add(register);
        buttons.add(back);

        Panel bottom = new Panel(new BorderLayout());
        bottom.add(buttons, BorderLayout.NORTH);
        bottom.add(status, BorderLayout.SOUTH);

        add(bottom, BorderLayout.SOUTH);

        register.addActionListener(event -> {
            String name = nameField.getText().trim();
            String email = emailField.getText().trim();
            String phone = phoneField.getText().trim();
            String password = passwordField.getText();
            String confirmation = confirmField.getText();

            if (!manager.validateCustomerDetails(name, email, phone)) {
                status.setText("Please enter your name and a valid email.");
                return;
            }

            if (password.trim().isEmpty()) {
                status.setText("Please enter a password.");
                return;
            }

            if (!password.equals(confirmation)) {
                status.setText("Your passwords do not match.");
                return;
            }

            if (manager.emailExists(email)) {
                status.setText("This email is already registered.");
                return;
            }

            try {
                // Save the profile and login details together.
                accountCreator.createAccount(
                        name, email, phone, password);
            } catch (IllegalArgumentException exception) {
                status.setText(exception.getMessage());
                return;
            } catch (Exception exception) {
                status.setText(
                        "We couldn't create your account. Please try again.");
                return;
            }

            nameField.setText("");
            emailField.setText("");
            phoneField.setText("");
            passwordField.setText("");
            confirmField.setText("");

            status.setText(" ");

            backToLogin.run();
        });

        back.addActionListener(event -> {
            passwordField.setText("");
            confirmField.setText("");
            status.setText(" ");

            backToLogin.run();
        });
    }
}