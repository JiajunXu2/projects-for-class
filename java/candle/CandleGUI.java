class CandleGUI extends JFrame{
    
	JFrame myFrame;
	Container myContentPane;
    TextArea sortedTextarea = new TextArea();
    TextArea unsortedTextarea = new TextArea();
    JMenuBar menubar = new JMenuBar();
    JMenuItem item;
    
    public CandleGUI(String title){
    	super();
    	myFrame = new JFrame();
    	/*
    	 * Initializing a GUI
    	 */
    	myFrame.setTitle(title);
    	myFrame.setSize(500, 500);
    	myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
    	myContentPane = new Container();
        myContentPane.setLayout(new GridLayout(1, 2));
        myContentPane.add(sortedTextarea);
        myContentPane.add(unsortedTextarea);
        myFrame.add(myContentPane);
        
        createFileMenu(menubar);
        pack();
        this.setVisible(true);
        
        //sortedTextarea.append(sortedList.toString());
        //unsortedTextarea.append(UnsortedList.toString());
        
    }
    
    public void createFileMenu(JMenuBar menubar) {   	
    	/*
    	 * creating menuitems and adding item listeners to the items
    	 * and putting them inside the menubar
    	 */
        JMenu file = new JMenu("file");
        FileMenuHandler fmh = new FileMenuHandler(this);
        
        JMenuItem open = new JMenuItem("open");
        open.addActionListener(fmh);
        file.add(open);
        
        JMenuItem exit = new JMenuItem("exit");
        exit.addActionListener(fmh);
        file.add(exit);
        
        setJMenuBar(menubar);
        menubar.add(file);
        
    } 
    
    
    
}
