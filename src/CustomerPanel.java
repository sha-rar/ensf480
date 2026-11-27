import java.awt.*;

public class CustomerPanel extends Panel {

    private TextField nameField = new TextField();
    private TextField emailField = new TextField();
    private TextField phoneField = new TextField();

    private Label status = new Label(" ");

    public CustomerPanel(CustomerManager manager,
            Customer customer,
            Runnable back,
            Runnable onDeleted) {

        setLayout(new BorderLayout(10, 12));

        add(new Label("My Profile"), BorderLayout.NORTH);

        Panel fields = new Panel(new GridLayout(3, 2, 8, 8));

        fields.add(new Label("Full name"));
        fields.add(nameField);

        fields.add(new Label("Email"));
        fields.add(emailField);

        fields.add(new Label("Phone (optional)"));
        fields.add(phoneField);

        Panel center = new Panel(new BorderLayout());
        center.add(fields, BorderLayout.NORTH);

        add(center, BorderLayout.CENTER);

        Button saveButton = new Button("Save Changes");
        Button deleteButton = new Button("Delete Profile");
        Button backButton = new Button("Back");

        Panel buttons = new Panel(new FlowLayout(FlowLayout.LEFT));
        buttons.add(saveButton);
        buttons.add(deleteButton);
        buttons.add(backButton);

        Panel bottom = new Panel(new BorderLayout());
        bottom.add(buttons, BorderLayout.NORTH);
        bottom.add(status, BorderLayout.SOUTH);

        add(bottom, BorderLayout.SOUTH);

        // Display the log-in customer's details.
        if (customer == null) {
            nameField.setEditable(false);
            emailField.setEditable(false);
            phoneField.setEditable(false);

            saveButton.setEnabled(false);
            deleteButton.setEnabled(false);

            status.setText("Please log in to view your profile.");
        } else {
            nameField.setText(customer.getName());
            emailField.setText(customer.getEmail());
            phoneField.setText(customer.getPhone());
        }

        saveButton.addActionListener(event -> {
            if (customer == null) {
                return;
            }

            String name = nameField.getText().trim();
            String email = emailField.getText().trim();
            String phone = phoneField.getText().trim();

            try {
                boolean updated = manager.updateCustomer(
                        customer.getCustomerId(),
                        name,
                        email,
                        phone);

                if (updated) {
                    status.setText("Your profile has been updated.");
                } else {
                    status.setText("Sorry! We couldn't find your profile.");
                }
            } catch (IllegalArgumentException exception) {
                status.setText(exception.getMessage());
            } catch (Exception exception) {
                status.setText(
                        "We couldn't save your changes. Please try again.");
            }
        });

        deleteButton.addActionListener(event -> {
            if (customer == null) {
                return;
            }

            try {
                boolean deleted = manager.removeCustomer(
                        customer.getCustomerId());

                if (!deleted) {
                    status.setText("Sorry! We couldn't find your profile.");
                    return;
                }
            } catch (Exception exception) {
                status.setText(
                        "We couldn't delete your profile. Please try again.");
                return;
            }

            nameField.setText("");
            emailField.setText("");
            phoneField.setText("");

            nameField.setEditable(false);
            emailField.setEditable(false);
            phoneField.setEditable(false);

            saveButton.setEnabled(false);
            deleteButton.setEnabled(false);

            // The main application clears the login session and returns to the login
            // screen.
            onDeleted.run();
        });

        backButton.addActionListener(event -> {
            back.run();
        });
    }
}