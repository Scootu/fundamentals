public interface IEmailService {
    void sendEmail(EmailMessage message);

    void downloadEmail(String emailId);
}
public class EmailMessage {};
public class BasicEmailService implements IEmailService {
    @Override
    public void sendEmail(EmailMessage message) {
        // Core sending logic
    }

    @Override
    public void downloadEmail(String emailId) {
        // Core download logic
    }
}

// With Retries
public class EmailServiceWithRetries extends BasicEmailService {
    @Override
    public void sendEmail(EmailMessage message) {
        int retryCount = 0;
        while (retryCount < MAX_RETRIES) {
            try {
                super.sendEmail(message);
                return;
            } catch (EmailException e) {
                retryCount++;
            }
        }
    }
}

// With Logging
public class EmailServiceWithLogging extends BasicEmailService {
    @Override
    public void sendEmail(EmailMessage message) {
        logger.log("Sending email: " + message.getId());
        super.sendEmail(message);
        logger.log("Sent email: " + message.getId());
    }
}

// Retries + Logging
public class EmailServiceWithRetriesAndLogging
        extends EmailServiceWithRetries {

    @Override
    public void sendEmail(EmailMessage message) {
        logger.log("Attempting send with retries: " + message.getId());
        super.sendEmail(message); // Uses retry logic from parent
        logger.log("Completed send with retries: " + message.getId());
    }
}

// Thread-safe + Logging
public class ThreadSafeEmailServiceWithLogging
        extends ThreadSafeEmailService {

    @Override
    public synchronized void sendEmail(EmailMessage message) {
        logger.log("Thread-safe send: " + message.getId());
        super.sendEmail(message);
    }
}

public class homework9 {
    public static void main(String[] args) {
        
        // Basic service with logging
        IEmailService service = new EmailServiceWithLogging();
        
        // Thread-safe service with retries and logging
        IEmailService premiumService = new ThreadSafeEmailServiceWithRetriesAndLogging();
    }
}