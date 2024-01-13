public class Candle {
	private int height;
	private int width;
	private float price;
	private boolean isLit;
	
	public Candle(int h, int w, float p) {
		super();
		this.height = h;
		this.width = w;
		this.price = p;	
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public float getPrice() {
		return price;
	}

	public void setPrice(float price) {
		this.price = price;
	}

	public boolean isLit() {
		return isLit;
	}

	public void setLit(boolean isLit) {
		this.isLit = isLit;
	}
	
	
	public String add() {
		return height + "," + width + "," +price;	
	}
	
}
