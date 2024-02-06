public class A1LinkedListXJ{
   	public static void main(String argc[]){
		LinkedList<Integer> sl = new LinkedList<>();
		PolynomialLinkedList sum = new PolynomialLinkedList();
		PolynomialLinkedList prod = new PolynomialLinkedList();
		
		for (int i = 1000; i > 0; i-=3) sl.add(i);
		
		System.out.println("Mid Element is " + sl.midElement());
		
		try {
			sl.insert(111, sl.getNode(50), sl.getNode(51));
			if (sl.detectLoop()) System.out.println("Loop!");
			else System.out.println("No loop.");
		
		
			sl.insert(123, sl.getNode(51), sl.getNode(50));
			if (sl.detectLoop()) System.out.println("Loop!");
			else System.out.println("No loop.");
		}
		catch(Exception e){
			e.printStackTrace();
		}
		
		
		PolynomialLinkedList p1, p2, p3, p4;
		p1 = new PolynomialLinkedList(2,3);
		p2 = new PolynomialLinkedList(3,2);
		p3 = p1.add(p2);
		p1 = new PolynomialLinkedList(3,2);
		p2 = new PolynomialLinkedList(1,0);
		p4 = p1.add(p2);
		sum = p3.add(p4);
		prod = p3.multiply(p4);
		p3.print();
		p4.print();
		sum.print();
		prod.print();
	}
}
