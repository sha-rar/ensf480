import java.awt.*;

public class PaymentPanel extends Panel {
    private Choice method = new Choice();
    private Label status = new Label(" ");

    // Open this panel after the flight and seat have been selected.
    public PaymentPanel(PaymentManager manager, Customer customer,
            BookingPaymentAccess booking,
            Runnable onSuccess, Runnable onCancel) {

        setLayout(new BorderLayout(10, 12));
        add(new Label("Payment"), BorderLayout.NORTH);

        TextArea details = new TextArea(
                "", 6, 50, TextArea.SCROLLBARS_VERTICAL_ONLY);
        details.setEditable(false);

        if (booking != null) {
            details.setText(
                    "Booking: " + booking.getBookingId()
                            + "\nAmount due: CAD "
                            + String.format("%.2f", booking.getAmountDue()));
        }

        method.add("Credit Card");
        method.add("Debit Card");

        Panel fields = new Panel(new GridLayout(1, 2, 8, 8));
        fields.add(new Label("Payment method"));
        fields.add(method);

        Panel center = new Panel(new BorderLayout(8, 10));
        center.add(details, BorderLayout.CENTER);
        center.add(fields, BorderLayout.SOUTH);
        add(center, BorderLayout.CENTER);

        Button pay = new Button("Confirm Payment");
        Button cancel = new Button("Cancel");

        Panel buttons = new Panel(new FlowLayout(FlowLayout.LEFT));
        buttons.add(pay);
        buttons.add(cancel);

        Panel bottom = new Panel(new BorderLayout());
        bottom.add(buttons, BorderLayout.NORTH);
        bottom.add(status, BorderLayout.SOUTH);
        add(bottom, BorderLayout.SOUTH);

        if (customer == null || booking == null) {
            pay.setEnabled(false);
            status.setText("Please log in and select a booking first.");
        }

        pay.addActionListener(event -> {
            boolean success;

            try {
                success = manager.processPayment(
                        customer,
                        booking,
                        method.getSelectedItem());
            } catch (IllegalArgumentException exception) {
                status.setText(exception.getMessage());
                return;
            } catch (Exception exception) {
                status.setText(
                        "We couldn't save your payment. Please try again.");
                return;
            }

            if (success) {
                pay.setEnabled(false);
                cancel.setEnabled(false);
                status.setText(
                        "Payment successful! Your booking is confirmed.");
                onSuccess.run();
            } else {
                status.setText("Payment failed. Please try again.");
            }
        });

        cancel.addActionListener(event -> {
            onCancel.run();
        });
    }
}