import java.util.Scanner;
public class Tri {
	private double bottom;
	private double height;
	Tri(){}
	Tri(double b,double h){
		bottom = b;
		height = h;
	}
	public double area(){
		return bottom*height/2;
	}
	public boolean equals(Tri t){
		if((this.bottom == t.bottom && this.height == t.height) || (this.bottom == t.height && this.height == t.bottom)){
			return true;
		}
		else{
			return false;
		}
	}
	public String toString(){
		String s = "底为"+this.bottom+"高为"+this.height+"的直角三角形";
		return s;
	}
	
	public static void main(String args[]){
	
		Tri t1 = new Tri(3,4);
		Tri t2 = new Tri(3,3);
		System.out.println("t1:"+t1);
		System.out.println("t1面积="+t1.area());
		System.out.println("t1与t2是否相等:"+t1.equals(t2));
	}

}
