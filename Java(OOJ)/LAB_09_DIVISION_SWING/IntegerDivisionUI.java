import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class IntegerDivisionUI {

    private JFrame frame;
    private JTextField num1Field;
    private JTextField num2Field;
    private JTextField resultField;
    private JButton divideButton;

    // ===== FUNCTION 1: main =====
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            IntegerDivisionUI app = new IntegerDivisionUI();
            app.createUI();
        });
    }

    // ===== FUNCTION 2: createUI =====
    private void createUI() {
        frame = new JFrame("Integer Division");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(4, 2));

        num1Field = new JTextField();
        num2Field = new JTextField();
        resultField = new JTextField();
        resultField.setEditable(false);
        divideButton = new JButton("Divide");

        frame.add(new JLabel("Num1:"));
        frame.add(num1Field);
        frame.add(new JLabel("Num2:"));
        frame.add(num2Field);
        frame.add(new JLabel("Result:"));
        frame.add(resultField);
        frame.add(divideButton);

        addListeners();

        frame.setVisible(true);
    }

    // ===== FUNCTION 3: addListeners =====
    private void addListeners() {
        divideButton.addActionListener(e -> divideNumbers());
    }

    // ===== FUNCTION 4: divideNumbers =====
    private void divideNumbers() {
        try {
            int num1 = Integer.parseInt(num1Field.getText());
            int num2 = Integer.parseInt(num2Field.getText());

            if (num2 == 0) {
                throw new ArithmeticException("Cannot divide by zero!");
            }

            int result = num1 / num2;
            resultField.setText(String.valueOf(result));

        } catch (NumberFormatException ex) {
            showError("Invalid Input: Please enter integers only.\n" + ex.getMessage());
        } catch (ArithmeticException ex) {
            showError("Math Error: " + ex.getMessage());
        }
    }

    // ===== FUNCTION 5: showError =====
    private void showError(String message) {
        JOptionPane.showMessageDialog(frame, message, "Error", JOptionPane.ERROR_MESSAGE);
    }
}
