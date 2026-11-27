import java.awt.*;
import java.time.LocalDate;

public class PromotionPanel extends Panel {

    public PromotionPanel(PromotionManager manager, Runnable back) {
        setLayout(new BorderLayout(10, 12));

        add(new Label("Monthly Promotions"), BorderLayout.NORTH);

        TextArea news = new TextArea(
                "",
                12,
                50,
                TextArea.SCROLLBARS_VERTICAL_ONLY);

        news.setEditable(false);
        news.setText(manager.getCurrentPromotions(LocalDate.now()));

        add(news, BorderLayout.CENTER);

        Button backButton = new Button("Back");

        Panel buttons = new Panel(new FlowLayout(FlowLayout.LEFT));
        buttons.add(backButton);

        add(buttons, BorderLayout.SOUTH);

        backButton.addActionListener(event -> {
            back.run();
        });
    }
}