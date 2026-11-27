public class PaymentManager {

    // temp here remove when connect to SQL thsi is for save payment history
    private Payment[] payments = new Payment[100];
    private int paymentCount = 0;

    // pick a payment here
    public boolean validatePaymentInformation(String method) {
        if ("Credit Card".equals(method)
                || "Debit Card".equals(method)) {
            return true;
        }

        return false;
    }

    // some checking
    public boolean processPayment(Customer customer,
            BookingPaymentAccess booking,
            String method) throws Exception {

        if (customer == null) {
            throw new IllegalArgumentException(
                    "Please log-in before making a payment.");
        }

        if (booking == null) {
            throw new IllegalArgumentException(
                    "Sorry! we can't find your booking.");
        }

        if (booking.getCustomerId() != customer.getCustomerId()) {
            throw new IllegalArgumentException(
                    "You can only pay for your own booking.");
        }

        if (!booking.isAwaitingPayment()) {
            throw new IllegalArgumentException(
                    "This booking can't be paid right now.");
        }

        if (!validatePaymentInformation(method)) {
            throw new IllegalArgumentException(
                    "Please choose a payment method.");
        }

        double amount = booking.getAmountDue();

        if (amount < 0) {
            throw new IllegalArgumentException(
                    "The payment amount is invalid.");
        }
        // this is just checking if the payment array storge for history payment is full
        // or not
        // could remove when connect to data base
        if (paymentCount >= payments.length) {
            throw new IllegalArgumentException(
                    "Payment history is full.");
        }

        // JUst to add some fun simulate a 20% chance of payment failure.
        if (Math.random() < 0.2) {
            return false;
        }

        Payment payment = new Payment(
                0,
                booking.getBookingId(),
                customer.getCustomerId(),
                amount,
                method);

        // Save payment and confirm the booking.
        int paymentId = booking.savePaymentAndConfirmBooking(payment);
        payment.setPaymentId(paymentId);

        payments[paymentCount] = payment;
        paymentCount++;

        return true;
    }

    // this is for the backend people use the customerID to pull out all his patment
    // history
    public Payment[] getPaymentsForCustomer(int customerId) {
        int count = 0;

        // Count this customer's payments.
        for (int i = 0; i < paymentCount; i++) {
            if (payments[i].getCustomerId() == customerId) {
                count++;
            }
        }

        Payment[] result = new Payment[count];
        int index = 0;

        // Copy this customer's payments into the result.
        for (int i = 0; i < paymentCount; i++) {
            if (payments[i].getCustomerId() == customerId) {
                result[index] = payments[i];
                index++;
            }
        }

        return result;
    }
}