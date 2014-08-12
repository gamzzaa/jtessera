package graphicutil;

public class GraphicUtil {
	public native static void clearScreen();
	public native static void setTextColor(int color);
	public native static int captureKeyboardArrows();
	public native static void setCursorPosition(int x, int y);
	public native static void hideCursor(boolean hide);
	
	static {	
		System.loadLibrary("graphicutil");
	}

	public static void main(String[] args) {
		clearScreen();
		
		setTextColor(0x02);
		System.out.println("Text...");
		setTextColor(0x30);
		System.out.println("             ");
		setTextColor(0x50);
		System.out.println(" \n");
		setTextColor(0x40);
		System.out.println("  ");
		System.out.println("      ");
		
		captureKeyboardArrows();
		
		setTextColor(0x07);
		setCursorPosition(60,20);
		System.out.println("1st point!");
		setCursorPosition(60,0);
		System.out.println("2nd point!");
		setTextColor(0x07);
		setCursorPosition(0,40);
	}
}