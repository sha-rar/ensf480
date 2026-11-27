public class CustomerManager {

    // Temp here to storge customers remove when connect to SQL
    private Customer[] customers = new Customer[100];
    private int customerCount = 0;
    private int nextId = 1;

    public boolean validateCustomerDetails(
            String name, String email, String phone) {

        if (name == null || email == null || phone == null) {
            return false;
        }

        if (name.trim().isEmpty()) {
            return false;
        }

        String address = email.trim();
        int at = address.indexOf('@');
        int dot = address.lastIndexOf('.');

        if (address.contains(" ")
                || at <= 0
                || at != address.lastIndexOf('@')
                || dot <= at + 1
                || dot == address.length() - 1) {
            return false;
        }

        return true;
    }

    public boolean emailExists(String email) {
        if (email == null) {
            return false;
        }

        // temp replace this loop with a database query later.
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getEmail()
                    .equalsIgnoreCase(email.trim())) {
                return true;
            }
        }

        return false;
    }

    public Customer createCustomer(
            String name, String email, String phone) {

        if (!validateCustomerDetails(name, email, phone)) {
            throw new IllegalArgumentException(
                    "Please enter your name and a valid email.");
        }

        if (emailExists(email)) {
            throw new IllegalArgumentException(
                    "This email is already registered.");
        }

        // TEMPORARY: Remove this check after using database storage.
        if (customerCount >= customers.length) {
            throw new IllegalArgumentException(
                    "Customer storage is full.");
        }

        // TEMPORARY: The database will generate the ID
        // and save the customer later.
        Customer customer = new Customer(
                nextId,
                name.trim(),
                email.trim(),
                phone.trim());

        customers[customerCount] = customer;
        customerCount++;
        nextId++;

        return customer;
    }

    public Customer getCustomerDetails(int customerId) {
        // TEMPORARY: Replace this search with a database query.
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getCustomerId() == customerId) {
                return customers[i];
            }
        }

        return null;
    }

    public boolean updateCustomer(int customerId,
            String name, String email, String phone) {

        Customer customer = getCustomerDetails(customerId);

        if (customer == null) {
            return false;
        }

        if (!validateCustomerDetails(name, email, phone)) {
            throw new IllegalArgumentException(
                    "Please enter your name and a valid email.");
        }

        // temp replace this loop with a database query later.
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getCustomerId() != customerId
                    && customers[i].getEmail()
                            .equalsIgnoreCase(email.trim())) {

                throw new IllegalArgumentException(
                        "This email is already registered.");
            }
        }

        // save these changes
        // to the database.
        customer.updateDetails(
                name.trim(), email.trim(), phone.trim());

        return true;
    }

    public boolean removeCustomer(int customerId) {
        // temp
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getCustomerId() == customerId) {

                for (int j = i; j < customerCount - 1; j++) {
                    customers[j] = customers[j + 1];
                }

                customerCount--;
                customers[customerCount] = null;

                return true;
            }
        }

        return false;
    }

    public Customer[] getAllCustomers() {
        /// temp
        Customer[] result = new Customer[customerCount];

        for (int i = 0; i < customerCount; i++) {
            result[i] = customers[i];
        }

        return result;
    }
}