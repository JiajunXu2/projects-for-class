class SortedCandleList extends CandleList {
	
	SortedCandleList() {
		super();
	}
	
	public void add(Candle c) {
		CandleNode newnode = new CandleNode(c);
		CandleNode curr = first.next;
		CandleNode prevNode = first;
		
		while (curr != null) {
			if(curr.data.getPrice() > newnode.data.getPrice()) {
				curr = curr.next;
				prevNode = prevNode.next;
			} else {
				newnode.next = curr;
				prevNode.next = newnode;
				length++;
				return;
			}
		}
		append(c);
		
	}

}
