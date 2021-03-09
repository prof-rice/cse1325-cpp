import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class AllWidgets extends JFrame {
    private final static int width = 300;
    private final static int height = 110;
    
    public AllWidgets() {
        super();  // Initialize JFrame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close on X click
        setSize(width,height); // Set the JFrame size
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));

        // Button
        JButton button = new JButton("Ouch!");
        button.addActionListener(
		    (var event) -> JOptionPane.showMessageDialog(this, "Ouch!"));
        add(button);                      // Add the button to the JFrame
		
		// Combo Box
		String[] options = {"JComboBox Row 1", "JComboBox Row 2", "JComboBox Row 3"};
		JComboBox combo = new JComboBox<String>(options); // This is a template (coming soon!)
		combo.addActionListener(
		    (var event) -> JOptionPane.showMessageDialog(this, (String)combo.getSelectedItem()));
		add(combo);
		
		// Toggle Button
		JToggleButton toggle = new JToggleButton("Toggle Button");
		toggle.addActionListener(
		    (var event) -> JOptionPane.showMessageDialog(this, toggle.isSelected() ? "Down" : "Up"));
		/* Or more verbosely,
		toggle.addItemListener(
		    (var event) -> {
		        if(event.getStateChange() == ItemEvent.SELECTED)   JOptionPane.showMessageDialog(this, "SELECTED");		        
		        else if(event.getStateChange() == ItemEvent.DESELECTED) JOptionPane.showMessageDialog(this, "DESELECTED");
		        else JOptionPane.showMessageDialog(this, event.paramString());  // "Impossible" case
		    });
		*/
		add(toggle);

        // Check Button
        JCheckBox check = new JCheckBox("Check Box (enables Slider)");
        check.setSelected(true); // start checked
        check.addActionListener(
            (var event) -> JOptionPane.showMessageDialog(this, check.isSelected() ? "Checked" : "Unchecked"));
        add(check);
        
        // Radio Buttons
        ButtonGroup radioGroup = new ButtonGroup();            // Logical grouping - only one button in group may be down at a time
        JPanel radioPanel = new JPanel();                      // Physical grouping - visually group the radio buttons
        radioPanel.setLayout(new BoxLayout(radioPanel, BoxLayout.PAGE_AXIS));
        //JPanel radioPanel = new JPanel(new FlowLayout());    // BoxLayout is vertical; FlowLayout is horizontal
        radioPanel.setBorder(BorderFactory.createTitledBorder("This Border visually groups the JRadioButtons"));
        
        JRadioButton radio1 = new JRadioButton("Radio Button 1");
        radio1.setSelected(true);
        radioGroup.add(radio1);  // Add to logical grouping
        radioPanel.add(radio1);  // Add to physical grouping
        
        JRadioButton radio2 = new JRadioButton("Radio Button 2");
        radioGroup.add(radio2);
        radioPanel.add(radio2);

        add(radioPanel);

		// Display the window
		pack();
        setVisible(true); // Make the JFrame visible
    }

    public static void main(String[] args) {
       AllWidgets app = new AllWidgets();
       app.setVisible(true);
    }
}
