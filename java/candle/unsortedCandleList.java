class UnsortedCandleList extends CandleList {
	/*
	 * calling the super class and appending the candle to 
	 * the end of the list
	 */
	UnsortedCandleList() {
		super();
	}
	
	public void add(Candle c) {
		append(c);
	}
}
