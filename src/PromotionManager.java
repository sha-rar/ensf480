import java.time.LocalDate;
import java.time.LocalTime;

public class PromotionManager {

    public String getCurrentPromotions(LocalDate date) {
        return "Monthly Promotion News"
                + "\n" + date.getMonth() + " " + date.getYear()
                + "\n\nWelcome to this month's travel news!"
                + "\nCheck the flight list for available fares."
                + "\n\nThis is a sample message for the project.";
    }

    // promot if the flight is from 0 to 6am
    public double calculateDiscountedPrice(double originalPrice, LocalTime departureTime) {
        if (departureTime.getHour() < 6) {
            double discountedPrice = originalPrice * 0.9;

            return Math.round(discountedPrice * 100.00) / 100.00;
        }
        return originalPrice;
    }

    public boolean checkMonthlyPromotion(LocalDate date) {
        return date.getDayOfMonth() == 1;
    }
}