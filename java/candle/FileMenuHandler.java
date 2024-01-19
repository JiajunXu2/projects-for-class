import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.StringTokenizer;

public class FileMenuHandler implements ActionListener {
	SortedCandleList S = new SortedCandleList();
	
	UnsortedCandleList U = new UnsortedCandleList();
   
   CandleGUI cnGUI; 
   
   public FileMenuHandler (CandleGUI cn) {
      cnGUI = cn;
   
   }
   
   
   public void actionPerformed(ActionEvent event) {
      
      String menuName = event.getActionCommand();
      
      // if clicked "Open," display a file chooser
      if (menuName.equals("Open")) {
         openFile();  
      }
      
      // if clicked "Exit," quit the program
      else if (menuName.equals("Exit")) {
          System.exit(0);
      }
      
   } 
 
   private void openFile(){
      JFileChooser fileopen = new JFileChooser();
      FileNameExtensionFilter filter = new FileNameExtensionFilter("Text Files", "txt"); // filter to only .txt files 
      fileopen.setFileFilter(filter);
      int returnVal = fileopen.showOpenDialog(null);
      if(returnVal == JFileChooser.APPROVE_OPTION) // if condition set by filter is met
         readFile(fileopen.getSelectedFile()); // read file 
   }
   
  
   private void readFile(File selectedFile) {
      TextFileInput file = new TextFileInput(selectedFile.toString());
      String line = file.readLine();
      while(line != null) {
			
			/*
			 * while the file has a next line that has 3 values, store the file values in
			 * a placeholder then add into their respective Lists
			 */
			
			StringTokenizer tokens = new StringTokenizer(line,","); 
			
			int numofTokens = tokens.countTokens();
			if(numofTokens < 3) {
				break;
			}
			
			int placeholder1;
			int placeholder2;
			float placeholder3;
				
			placeholder1 = Integer.parseInt(tokens.nextToken());	
			placeholder2 = Integer.parseInt(tokens.nextToken());
			placeholder3 = Float.parseFloat(tokens.nextToken());
			
			U.add(new Candle(placeholder1, placeholder2, placeholder3));
			
			S.add(new Candle(placeholder1, placeholder2, placeholder3));
			
			line = file.readLine();
			
			
      } //while loop
      
     
   
   } //readfile method
      
} 
