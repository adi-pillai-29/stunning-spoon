//Adi Pillai - arp3np, Arwen Chandler - ac9kf, Sara Liu - syl5fr, Ann Li - al7gc, Lilian Zhang - lgz9cm

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.HeadlessException;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Hashtable;
import javax.swing.JSpinner;
import javax.swing.JLabel;
import javax.swing.JSplitPane;
import javax.swing.JTextField;
import javax.swing.JSlider;
import javax.swing.SpringLayout;
import javax.swing.SpinnerNumberModel;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JToolBar;
/**
 * This Calculator class represents the JFrame on containing the 
 * Roth IRA calculator. 
 * @author Your Friendly CS Professors
 *
 */
public class Calculator extends JFrame{
	
	/**
	 * Instance variables for State of Calculator
	 * Don't change the variable names they are used by test
	 * case
	 */
	protected int monthlySavings;
	protected int numYears;
	protected int currentAge;
	protected double rateOfReturn = .07;
	protected double investmentValue;
	protected int futureAge; 

	/**
	 * This represents the elements that are displayed on screen. 
	 * Don't change the name of these variables they ar used by the
	 * test cases. 
	 */
	protected JLabel ageLabel;
	protected JSpinner ageSpinner;
	protected JLabel monthSaveLabel;
	protected JSlider monthlySaveSlider;
	protected JLabel monthlySaveDisplayAmount;
	protected JLabel numYearsDisplay;
	protected JLabel futureAgeLabel; 
	protected JLabel investmentDisplayValue;
	protected JLabel rateOfReturnDisplay;
	protected JLabel numberOfYearsLabel;
	protected JSlider numYearsSlider;

	/**
	 * A getter for the monthlySaving instance variable
	 * @return the monthSavings
	 */
	public int getMonthlySavings() {
		return monthlySavings;
	}
	
	/**
	 * A getter for the numYears instance variable
	 * @return the numYears
	 */
	public int getNumYears() {
		return numYears;
	}
	
	/**
	 * A getter for the currentAge instance variable
	 * @return the currentAge
	 */
	public int getCurrentAge() {
		return currentAge;
	}
	
	/**
	 * A getter for the futureAge instance variable
	 * @return the futureAge
	 */
	public String getfutureAgeDisplayText() {
		return "Future Age: " + futureAge;
	}
	
	/**
	 * A getter for the rateOfReturn instance variable
	 * @return the rateOfReturn
	 */
	public double getRateOfReturn() {
		return rateOfReturn;
	}
	
	/**
	 * A getter for the investmentValue instance variable
	 * @return the investmentValue
	 */
	public String getInvestmentValueDisplayText() {
		return "Investment: $" + Math.round(investmentValue);
	}
	
	
	/**
	 * A setter for the monthlySavings instance variable
	 * 
	 */
	public void setMonthlySavings(int savings) {
		monthlySavings = savings;
		monthlySaveDisplayAmount.setText("$"+Integer.toString(savings));
	}
	/**
	 * A setter for the currentAge instance variable
	 * 
	 */
	public void setCurrentAge(int age) {
		currentAge = age;
	}
	/**
	 * A setter for the numYears instance variable
	 * 
	 */
	public void setNumYears(int years) {
		numYears = years;
		numYearsDisplay.setText(Integer.toString(years) + " years");
	}
	
	/**
	 * A setter for the futureAge instance variable
	 * 
	 */
	public void setFutureAge() {
		futureAge = getCurrentAge() + getNumYears();
		futureAgeLabel.setText(getfutureAgeDisplayText());
	}
	
	/**
	 * A setter for the investmentValue instance variable
	 * 
	 */
	public void setInvestmentValue(double value) {
		investmentValue = value;
		investmentDisplayValue.setText(getInvestmentValueDisplayText());
	}
	
	/**
	 * method that calculates the investment value
	 * @return the calculated investment value
	 */
	public double calculateInvestmentValue() {
		return getMonthlySavings()*((Math.pow((1 + getRateOfReturn()/12),(12*getNumYears())) - 1)/(getRateOfReturn()/12))*(1+getRateOfReturn()/12);
	}
	
	
	/**
	 * Inner classes that implement the handler form listeners
	 *  These classes implement the change listeners. 
	 */
	protected class NumYearsListener implements ChangeListener {
		//TODO: Implement this class.
		  public void stateChanged(ChangeEvent e) {
	          	JSlider source = (JSlider)e.getSource();
	          	int value = source.getValue();
	          	//TODO: Update appropriate values and labels
	          	setNumYears(value); //assigning NumYears variable with value from slider
	          	setFutureAge(); //setting future age given change to num years
	          	setInvestmentValue(calculateInvestmentValue()); //setting the investment value based on updated values for number of years with the calculateInvestmentValue method
	            }	
    }
	
	/**(
	 *
	 *	Listener for age change events. 
	 */
	
	 protected class AgeListener implements ChangeListener{
		 //TODO: Implement this class. 
		  public void stateChanged(ChangeEvent e) {
	          	JSpinner source = (JSpinner)e.getSource();
	          	int value = (int) source.getValue();
	          	//TODO: Update appropriate values and labels
	          	setCurrentAge(value); //assigning the current age variable with the value from the spinner
	            setFutureAge(); //setting future age given change to current age 
		  	}	
	 }
	
	
	/**
	 * 
	 * Listener for month change events. 
	 *
	 */
	protected class MonthSavingListener implements ChangeListener{

		  public void stateChanged(ChangeEvent e) {
          	JSlider source = (JSlider)e.getSource();
          	int value = source.getValue();
          	//TODO: Update appropriate values and labels
          	setMonthlySavings(value); //assigning the monthly savings variable with the value from the slider
          	setInvestmentValue(calculateInvestmentValue()); //setting the investment value based on updated values for monthly savings with the calculateInvestmentValue method
            }	
	}
 
 /**
	 * Class represents the frame. That we will create
	 * @param monthlySavings
	 * @param numYears
	 * @param currentAge
	 * @param rateOfReturn
	 */
	public Calculator(int monthlySavings, int numYears, int currentAge, double rateOfReturn) {
		super();
		/*
		 * Set up the default values
		 */
		this.monthlySavings = monthlySavings;
		this.numYears = numYears;
		this.currentAge = currentAge;
		this.rateOfReturn = rateOfReturn;
	
		/*
		 * Setup close window behavior 
		 */
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 587, 363);
		getContentPane().setLayout(null);
         
        /*------------------------------------------------------------
         * Logo Section Value Section.
         * Doesn't show up in the designer.
         *  You will need to run the program to see it.
      	 * ------------------------------------------------------------
      	 */
        ImageIcon iconLogo = new ImageIcon("Images/logo-uvacs.png");
        JLabel logoCS = new JLabel();
        logoCS.setIcon(iconLogo);
        logoCS.setBounds(350, 28, 165, 63);
        getContentPane().add(logoCS);
      
        /*------------------------------------------------------------
      	 * Future age section 
      	* ------------------------------------------------------------
      	*///default value to be initially displayed for the future age
        futureAgeLabel = new JLabel();
        futureAgeLabel.setBounds(31, 307, 142, 16);
        getContentPane().add(futureAgeLabel);
        
        /*------------------------------------------------------------
		 * Investment value section 
		 * ------------------------------------------------------------
		 */
        investmentDisplayValue = new JLabel("Investment: $" + Math.round(calculateInvestmentValue()));
        investmentDisplayValue.setBounds(403, 307, 184, 16);
        getContentPane().add(investmentDisplayValue);
      
		/*------------------------------------------------------------
		 * monthly contribution section 
		 * ------------------------------------------------------------
		 */
        //Month Saving Title Label
        monthSaveLabel = new JLabel("Monthly Savings");
        monthSaveLabel.setBounds(31, 131, 118, 26);
        getContentPane().add(monthSaveLabel);
        // Month Saving Display Label
        monthlySaveDisplayAmount = new JLabel("$"+getMonthlySavings());
        monthlySaveDisplayAmount.setBounds(469, 137, 46, 14);
        getContentPane().add(monthlySaveDisplayAmount);
        
        //Slide for selecting Month Savings 
        monthlySaveSlider = new JSlider();
        //Sets the maximum value of the slide
        monthlySaveSlider.setMaximum(500);
        //Sets the sliders default value 
        monthlySaveSlider.setValue(getMonthlySavings());
        //Set the location (x,y, .., ..) and the 
        // width and height (..., ..., width, height)
        monthlySaveSlider.setBounds(169, 122, 266, 45);
        //Show the ruler style lines
        monthlySaveSlider.setPaintTicks(true);
        //Spacing between major Ticks
        monthlySaveSlider.setMajorTickSpacing(150);
        //Spacing between minor Ticks
        monthlySaveSlider.setMinorTickSpacing(10);
        //Show labels on Ticks 
        monthlySaveSlider.setPaintLabels(true);
        //Add Change listener. 
        monthlySaveSlider.addChangeListener(new MonthSavingListener());
        getContentPane().add(monthlySaveSlider);
        
        /*------------------------------------------------------------
		 * Number of years section 
		 * ------------------------------------------------------------
		 */
        numberOfYearsLabel = new JLabel("Number of Years"); //created from the design window
        numberOfYearsLabel.setBounds(31, 217, 142, 16);
        getContentPane().add(numberOfYearsLabel);
        
        numYearsDisplay = new JLabel(getNumYears() + " years"); 
        numYearsDisplay.setBounds(469, 217, 61, 16);
        getContentPane().add(numYearsDisplay);
        
        numYearsSlider = new JSlider();
      //Sets the sliders default value 
        numYearsSlider.setValue(getNumYears());
        numYearsSlider.setMinorTickSpacing(1);
        numYearsSlider.setMajorTickSpacing(15);
        numYearsSlider.setPaintLabels(true);
        numYearsSlider.setPaintTicks(true);
        numYearsSlider.setSnapToTicks(true);
        numYearsSlider.setBounds(169, 204, 266, 45);
        numYearsSlider.addChangeListener(new NumYearsListener()); //add the listener
        getContentPane().add(numYearsSlider);
        
        /*------------------------------------------------------------
		 * Age section 
		 * ------------------------------------------------------------
		 */
        ageLabel = new JLabel("Age");
        ageLabel.setBounds(31, 55, 61, 16);
        getContentPane().add(ageLabel);
        
        ageSpinner = new JSpinner();
        ageSpinner.setValue(getCurrentAge());
        ageSpinner.setBounds(169, 53, 61, 33);
        ageSpinner.addChangeListener(new AgeListener()); //add the listener
        getContentPane().add(ageSpinner);
        
        /*------------------------------------------------------------
		 * Future age section 
		 * ------------------------------------------------------------
		 *///default value to be initially displayed for the future age
        futureAgeLabel = new JLabel("Future Age: " + (getNumYears()+getCurrentAge()));
        futureAgeLabel.setBounds(31, 307, 142, 16);
        getContentPane().add(futureAgeLabel);
        
        /*------------------------------------------------------------
		 * Rate of return section 
		 * ------------------------------------------------------------
		 */
        rateOfReturnDisplay = new JLabel("Rate: 7%"); //fixed rate
        rateOfReturnDisplay.setBounds(234, 307, 61, 16);
        getContentPane().add(rateOfReturnDisplay);
        
        
	}
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Calculator frame = new Calculator(77, 70, 18, 0.07);
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}