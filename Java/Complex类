import java.text.DecimalFormat;
class Complex {
	private double realPart;
	private double imaginPart;
	
	Complex() {
		realPart = 0;
		imaginPart = 0;
	}
	
	Complex(double r, double i) {
		realPart = r;
		imaginPart = i;
	}
	
	public void setReal(double m) {//设置复数对象的实部值
		realPart = m;
	}
	
	public void setImagin(double m) {//设置复数对象的虚部值
		imaginPart = m;
	}
	
	public double getReal() {//获得复数对象的实部数值
		return realPart;
	}
	
	public double getImagin() {//获得复数对象的虚部数值
		return imaginPart;
	}
	
	public Complex complexAdd(Complex a) {//加法
		Complex result = new Complex();
		result.setReal(realPart+a.realPart);
		result.setImagin(imaginPart+a.imaginPart);
		return result;
	}
	
	public Complex complexSub(Complex a) {//减法
		Complex result = new Complex();
		result.setReal(realPart-a.realPart);
		result.setImagin(imaginPart-a.imaginPart);
		return result;
	}
	
	public Complex complexMulti(Complex a) {//乘法
		Complex result = new Complex();
		result.setReal(realPart*a.realPart-imaginPart*a.imaginPart);
		result.setImagin(imaginPart*a.realPart+realPart*a.imaginPart);
		return result;
	}
	
	public Complex complexDiv(Complex a) {//调用乘法方法完成除法
		Complex result = new Complex();
		Complex b = new Complex(a.getReal(),a.getImagin()*-1);//a的共轭复数b
		result.setReal((this.complexMulti(b).getReal())/a.complexMulti(b).getReal());
		result.setImagin((this.complexMulti(b).getImagin())/a.complexMulti(b).getReal());
		return result;
	}
	
	public boolean equals(Complex a) {//比较是否相等
		return (this.getReal() == a.getReal() && this.getImagin() == a.getImagin());
	}
	
	public String toString() {//输出复数
		String s = "";
		DecimalFormat df = new DecimalFormat("#.##");
		String rp = df.format(this.realPart);
		String ip = df.format(this.imaginPart);
		if(Math.abs(this.realPart) >= 0.005){
			if(this.imaginPart == 0){
				s = rp;
			}
			else if(this.imaginPart == 1){
				s = rp+"i";
			}
			else if(this.imaginPart == -1){
				s = rp+"-i";
			}
			else if(this.imaginPart > 0){
				s = rp+"+"+ip+"i";
			}
			else{
				s = rp+""+ip+"i";
			}
		}
		else{
			if(this.imaginPart == 0){
				s = "0";
			}
			else if(this.imaginPart == 1){
				s = "i";
			}
			else if(this.imaginPart == -1){
				s = "-i";
			}
			else{
				s = ip+"i";
			}
		}
		return s;
	}
	
}
