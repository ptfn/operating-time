import javax.swing.*;

class HelloWorldGui {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Hello");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel label = new JLabel("Hello", SwingConstants.CENTER);
        frame.getContentPane().add(label);

        frame.pack();
        frame.setVisible(true);
    }
}
