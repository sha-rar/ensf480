public interface BookingPaymentAccess {
    String getBookingId();

    int getCustomerId();

    double getAmountDue();

    boolean isAwaitingPayment();

    int savePaymentAndConfirmBooking(Payment payment) throws Exception;
}