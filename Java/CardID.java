import java.util.Scanner;
import java.util.Calendar;
class CardID {
	private String cardNum;
	
	public CardID(){
		cardNum = "";
	}
	public CardID(String s){
		cardNum = s;
	}
	
	public void setCardID(){
		Scanner sc=new Scanner(System.in);
		System.out.print("请输入身份证号：");
		String s = "";
		s = sc.nextLine();
		this.cardNum = s;
	}
	
	public boolean lengthVerify(){//位数验证
		if(cardNum.length() == 18){
			return true;
		}
		else{
			return false;
		}
	}
	
	public boolean charVerify(){//字符验证
		for(int i = 0; i < 17; i++){
			if(!(cardNum.charAt(i) >= '0' && cardNum.charAt(i) <= '9')){
				//System.out.println("F1 "+i+cardNum.charAt(17));
				return false;
			}
		}
		if(!((cardNum.charAt(17) >= '0' && cardNum.charAt(17) <= '9') || cardNum.charAt(17) == 'x' || cardNum.charAt(17) == 'X')){
			//System.out.println("F2");
			return false;
		}
		return true;
	}
	
	public boolean checkcodeVerify(){//i,ai,wi,sum,校验码验证
		String newCard = cardNum.substring(0,17)+"0";
		char b1[]={'1','0','X','9','8','7','6','5','4','3','2','1'};
		char b2[]={'1','0','x','9','8','7','6','5','4','3','2','1'};
		int ai,wi,sum = 0;
		for(int i = 18; i >= 1; i--){
			ai = newCard.charAt(18-i)-'0';
			wi = (int)(Math.pow(2,(i-1)))%11;
			sum += ai*wi;
			//System.out.println("i="+i+" ai="+ai+" wi="+wi+" sum="+sum);
		}
		int mod = sum % 11;
		return (cardNum.charAt(17) == b1[mod] || cardNum.charAt(17) == b2[mod]);
	}
	
	public void output(){//输出个人信息
		System.out.println(this.cardNum);
		Calendar now = Calendar.getInstance();
		Calendar bd = Calendar.getInstance();
		int month = this.cardNum.charAt(6);
		bd.set(this.cardNum.substring(6,10), this.cardNum.substring(10,12),this.cardNum.substring(12,14));
		System.out.println(bd.get(Calendar.MONTH)+1);
	}
}

class CardIDDemo{
	public static void main(String arg[]){
		while(true){
			CardID ID=new CardID();
			ID.setCardID();
			if(!ID.lengthVerify()){
				System.out.println("身份证号位数错误!");
			}else if(!ID.charVerify()){
				System.out.println("身份证号字符错误!");
			}else if(!ID.checkcodeVerify()){
				System.out.println("身份证号验证码错误!");
			}else{
				ID.output();
			}
		}
	}
}
