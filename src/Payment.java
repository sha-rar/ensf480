import java.time.LocalDateTime;

public class Payment {
    private int paymentId;
    private String bookingId;
    private int customerId;
    private double amount;
    private String method;
    private LocalDateTime paymentTime;

    public Payment(int paymentId, String bookingId, int customerId,
            double amount, String method) {
        this.paymentId = paymentId;
        this.bookingId = bookingId;
        this.customerId = customerId;
        this.amount = amount;
        this.method = method;
        this.paymentTime = LocalDateTime.now();
    }

    public int getPaymentId() {
        return paymentId;
    }

    public void setPaymentId(int paymentId) {
        this.paymentId = paymentId;
    }

    public String getBookingId() {
        return bookingId;
    }

    public int getCustomerId() {
        return customerId;
    }

    public double getAmount() {
        return amount;
    }

    public String getMethod() {
        return method;
    }

    public LocalDateTime getPaymentTime() {
        return paymentTime;
    }

    public String getStatus() {
        return "Successful";
    }

    public String toString() {
        return "Payment " + paymentId + " | Booking " + bookingId
                + " | CAD " + String.format("%.2f", amount)
                + " | " + method + " | " + paymentTime.toString();
    }
}